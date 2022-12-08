#include "avatar.hpp"

avatar::avatar(char race) : entity() {
    if (race == 'v' || race == 'V') {
        vamp = true;
        were = false;
    }
    else {
        vamp = true;
        were = false;
    }
    potion = 1;
}

bool avatar::is_vampire() {
    return vamp == true;
}

bool avatar::is_werewold() {
    return were == true;
}

void avatar::move(string move, map &m) {    // moves the player in the map
    if (move == "up") {
        if (x-1 < 0 || m.is_obstacle(x-1, y) || m.is_vampire(x-1, y) || m.is_werewolf(x-1, y)) {    // check if move is legal
            cout << "Illegal move" << endl;
            return;
        }
        else {
            m[x][y] = ' ';
            x -= 1;  
        }
    }
    else if (move == "down") {
        if (x+1 >= m.get_x() || m.is_obstacle(x+1, y) || m.is_vampire(x+1, y) || m.is_werewolf(x+1, y)) { // check if move is legal
            cout << "Illegal move" << endl;
            return;
        }
        else {
            m[x][y] = ' ';
            x += 1;
        }
    }
    else if (move == "left") {
        if (y-1 < 0 || m.is_obstacle(x, y-1) || m.is_vampire(x, y-1) || m.is_werewolf(x, y-1)) { // check if move is legal
            cout << "Illegal move" << endl;
            return;
        }
        else {
            m[x][y] = ' ';
            y -= 1;
        }
    }
    else if (move == "right") {
        if (y+1 >= m.get_y() || m.is_obstacle(x, y+1) || m.is_vampire(x, y+1) || m.is_werewolf(x, y+1)) { // check if move is legal
            cout << "Illegal move" << endl;
            return;
        }
        else {
            m[x][y] = ' ';
            y += 1;
        }
    }

    // check to see if potion is picked up and update the map
    if (m[x][y] == 'P') {
        cout << "Potion picked up!" << endl;
        potion++;
    }
    m[x][y] = 'A';
}

void avatar::show_stats() {  // prints the avatar's stats to the screen (we can't overload << because it is a friend function in entity class)
    cout << "Player stats: Potion: " << potion << " Pos: (" << x << "," << y << ")";
    if (is_vampire()) cout << " Race: Vampire" << endl;
    else cout << " Race: Werewolf" << endl;
}