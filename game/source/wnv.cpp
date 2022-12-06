#include "wnv.hpp"


wnv::wnv(int in_x, int in_y) : m(in_x, in_y) {
    x = in_x;
    y = in_y;
    vampires = new vampire [x*y/15];

    int i, j, k = 0;
    for (i = 0 ; i < x ; i++) {
        for (j = 0 ; j < y ; j++) {
            if ( m[i][j] == 'v') {
                vampires[k].set_x(i);
                vampires[k].set_y(j);
                k++;
            }
        }
    }
    for(int i = 0 ; i < x*y/15 ; i++)
        cout << "(" << vampires[i].get_x() << "," << vampires[i].get_y() << ")" << endl;  
};

wnv::~wnv() {}

ostream &operator<<(ostream &left, const wnv &right) {  // << overloading
    left << right.m;
    return left;
}