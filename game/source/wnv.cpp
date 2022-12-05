#include "wnv.hpp"


wnv::wnv(int in_x, int in_y) : m(in_x, in_y) {
    x = in_x;
    y = in_y;
};

wnv::~wnv() {}

ostream &operator<<(ostream &left, const wnv &right) {  // << overloading
    left << right.m;
    return left;
}