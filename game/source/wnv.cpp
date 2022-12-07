#include "wnv.hpp"


wnv::wnv(int in_x, int in_y) : m(in_x, in_y) {
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
                vampires[k].set_identifier(k);
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
                werewolfs[k].set_identifier(k);
                k++;
            }
        }
    }
};

wnv::~wnv() {}

ostream &operator<<(ostream &left, const wnv &right) {  // << overloading
    left << right.m;
    return left;
}