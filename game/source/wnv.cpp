#include "wnv.hpp"
#include "vampire.hpp"
#include "werewolf.hpp"

wnv::wnv(int in_x, int in_y, char race) : m(in_x, in_y), player(race) {
    x = in_x;
    y = in_y;
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

void wnv::player_move(string move) {    // move the player
    player.move(move, m);
}

void wnv::show() {  // prints time, map and player stats
    cout << "Time: " << time << endl;
    cout << m;
    player.show_stats();
}