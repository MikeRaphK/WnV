#include <iostream>
#include "wnv.hpp"
using namespace std;

wnv::wnv(int in_x, int in_y) : m(in_x, in_y) {
    x = in_x;
    y = in_y;
    entity_count = 2*x;
    daytime = "Day";
    werewolves = new entity[x];
    vampires = new entity[x];

    for (int i = 0 ; i < y ; i++) {
        vampires[i].set_x(0);
        vampires[i].set_y(i);

        werewolves[i].set_x(x-1);
        werewolves[i].set_y(i);
    }
};

wnv::~wnv() {
    delete[] werewolves;
    delete[] vampires;
}

void wnv::print_werewolves() {
    cout << "Werewolves:" << endl;
    for (int i = 0 ; i < x ; i++)
        cout << werewolves[i] << endl;
}

void wnv::print_vampires() {
    cout << "Vampires:" << endl;
    for (int i = 0 ; i < x ; i++)
        cout << vampires[i] << endl;
}

ostream &operator<<(ostream &left, const wnv &right) {  // << overloading
    left << right.m;
    return left;
}