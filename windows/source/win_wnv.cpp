#include "win_wnv.hpp"
#include "win_vampire.hpp"
#include "win_werewolf.hpp"
#include <windows.h>


wnv::wnv(int in_x, int in_y, char race) : m(in_x, in_y), player(race) {
    x = in_x;
    y = in_y;
    vampire_count = x*y/15;
    werewolf_count = x*y/15;
    if (rand()%2) time = "Day";
    else time = "Night"; 
//-------------vampires-----------------------    
    vampires = new vampire [x*y/15];
    int i, j, k = 0;
    for (i = 0 ; i < x ; i++) {
        for (j = 0 ; j < y ; j++) {
            if ( m[i][j] == 'v') {
                vampires[k].set_x(i);
                vampires[k].set_y(j);
                vampires[k].set_id(k);
                k++;
            }
        }
    }
//-------------werewolfs-----------------------
    k = 0;
    werewolfs = new werewolf [x*y/15];
    for (i = 0 ; i < x ; i++) {
        for (j = 0 ; j < y ; j++) {
            if ( m[i][j] == 'w') {
                werewolfs[k].set_x(i);
                werewolfs[k].set_y(j);
                werewolfs[k].set_id(k);
                k++;
            }
        }
    }

//-------------player-----------------------
    int rand_x = rand()%x;
    int rand_y = rand()%y;
    while (m[rand_x][rand_y] != ' ') {  // find an empty space
        rand_x = rand()%x;
        rand_y = rand()%y;
    }
    // place the player in the empty space
    player.set_x(rand_x);
    player.set_y(rand_y);
    m[rand_x][rand_y] = 'A';
//-----------------------------------------
    vampires[0].move(m);
};

wnv::~wnv() {}

void wnv::set_vampires(vampire* array) {
    vampires = array;
}

void wnv::set_werewolfs(werewolf* array) {
    werewolfs = array;
}

vampire* wnv::get_vampires() {
    return vampires;
}

werewolf* wnv::get_werewolfs() {
    return werewolfs;
}

map wnv::get_map() {
    return m;
}

string wnv::get_time() const {
    return time;
}

void wnv::player_turn() {   // During their turn the player can move, wait, pause or quit
    while (true) {
        if (GetKeyState(VK_UP) & 0x8000) {  // if up is pressed, move up
            player.move("up", m);
            break;
        }
        if (GetKeyState(VK_DOWN) & 0x8000) { // if down is pressed, move down
            player.move("down", m);
            break;
        }
        if (GetKeyState(VK_LEFT) & 0x8000) { // if left is pressed, move left
            player.move("left", m);
            break;
        }
        if (GetKeyState(VK_RIGHT) & 0x8000) { // if right is pressed, move right
            player.move("right", m);
            break;
        }
        if (GetKeyState(VK_SPACE) & 0x8000) break; // if space is pressed, wait
        if (GetKeyState('P') & 0x8000) { // if P is pressed, pause
            cout << endl << "-----GAME PAUSED-----" << endl;
            player.show_stats();
            cout << "Number of active vampires: " << vampire_count << endl;
            cout << "Number of active werewolves: " << werewolf_count << endl;
            system("pause");
            break;
        }
        if (GetKeyState('Q') & 0x8000) { // if Q is pressed, quit
            cout << "Quitting..." << endl;
            exit(0);
        }
    }
    Sleep(100); // Add a 100ms delay so no accidental double-presses are registered
}

void wnv::show() {  // prints time, map and player stats
    system("cls");
    cout << "Time: " << time << endl;
    cout << m;
    player.show_stats();
}