#include "wnv.hpp"
#include "vampire.hpp"
#include "werewolf.hpp"

wnv::wnv(int in_x, int in_y, char race) : m(in_x, in_y), player(race) {
    x = in_x;
    y = in_y;
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
    if (player.is_vampire()) player = vampires[rand()%(x*y/15)];
    else player = werewolfs[x*y/15];
    m[player.get_x()][player.get_y()] = 'A';
};

void wnv::player_stats() {  // prints the player's stats to the screen
    player.stats();
}

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

wnv::~wnv() {}

ostream &operator<<(ostream &left, const wnv &right) {  // << overloading
    left << right.m;
    return left;
}