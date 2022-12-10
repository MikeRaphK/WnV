#include "win_avatar.hpp"

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

bool avatar::is_werewolf() {
    return were == true;
}

void avatar::move(string move, map &m) {    // moves the player in the map
    if (move == "up") {
        if (x-1 < 0 || m.is_obstacle(x-1, y) || m.is_vampire(x-1, y) || m.is_werewolf(x-1, y)) return; // if move is illegal, return
        else {
            m[x][y] = ' ';
            x -= 1;  
        }
    }
    else if (move == "down") {
        if (x+1 >= m.get_x() || m.is_obstacle(x+1, y) || m.is_vampire(x+1, y) || m.is_werewolf(x+1, y)) return; // if move is illegal, return
        else {
            m[x][y] = ' ';
            x += 1;
        }
    }
    else if (move == "left") {
        if (y-1 < 0 || m.is_obstacle(x, y-1) || m.is_vampire(x, y-1) || m.is_werewolf(x, y-1)) return; // if move is illegal, return
        else {
            m[x][y] = ' ';
            y -= 1;
        }
    }
    else if (move == "right") {
        if (y+1 >= m.get_y() || m.is_obstacle(x, y+1) || m.is_vampire(x, y+1) || m.is_werewolf(x, y+1)) return; // if move is illegal, return
        else {
            m[x][y] = ' ';
            y += 1;
        }
    }

    // check to see if potion is picked up and update the map
    if (m[x][y] == 'p') potion++;
    m[x][y] = 'A';
}

void avatar::heal(vampire *(&vampires), int size) { // heal for vampires
    if (!potion) return;    // if player has no potions, return

    for (int i = 0 ; i < size ; i++) {
        vampires[i].heal(); // increase health by 1 for all vampires
        cout << "Healed 1 health to vampire in position (" << vampires[i].get_x() << "," << vampires[i].get_y() << "). Current health: " << vampires[i].get_health() << endl; 
    }
    cout << endl;
    potion--;   // player loses a potion
}

void avatar::heal(werewolf *(&werewolfs), int size) {   // heal for vampires using polymorphism
    if (!potion) return;    // if player has no potions, return
    
    for (int i = 0 ; i < size ; i++) {
        werewolfs[i].heal();    // increase health by 1 for all vampires
        cout << "Healed 1 health to werewolf in position (" << werewolfs[i].get_x() << "," << werewolfs[i].get_y() << ")" << endl; 
    }
    cout << endl;
    potion--; // player loses a potion
}

void avatar::show_stats() {  // prints the avatar's stats to the screen (we can't overload << because it is a friend function in entity class)
    cout << "Player stats: Potion: " << potion << " Pos: (" << x << "," << y << ")";
    if (is_vampire()) cout << " Race: Vampire" << endl;
    else cout << " Race: Werewolf" << endl;
}