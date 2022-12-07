#include <iostream>
#include <cstdlib>
#include <ctime>
#include "map.hpp"
#include "entity.hpp"
#include "wnv.hpp"
#include "avatar.hpp"
using namespace std;

int main() {
    srand(time(0));
    wnv game(10, 10);
    cout << game;

    entity e;
    e.set_x(3);
    e.set_y(6);
    cout << e << endl;

    avatar a(e);
    cout << a << endl;

    return 0;
}