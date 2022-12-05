#include <iostream>
#include "wnv.hpp"
using namespace std;

wnv::wnv(int in_x, int in_y) : m(in_x, in_y) {
    x = in_x;
    y = in_y;
    entity_count = 2*x;
    werewolves = new entity[x];
    vampires = new entity[x];
    daytime = "Day";
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