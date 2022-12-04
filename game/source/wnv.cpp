#include "wnv.hpp"

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

ostream &operator<<(ostream &left, const wnv &right) {  // << overloading
    left << right.m;
    return left;
}