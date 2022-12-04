#include <iostream>
#include <cstdlib>
#include <ctime>
#include "map.hpp"
#include "entity.hpp"
#include "wnv.hpp"
using namespace std;

int main() {
    srand(time(0));
    // entity testing
    // entity e1;
    // entity e2;
    // entity e3;
    // entity e4;
    // cout << e1 << endl << e2 << endl << e3 << endl << e4 << endl;

    // cout << endl;

    // while (!e2.is_dead()) {
    //     e1.do_attack(e2);
    //     cout << e1 << endl << e2 << endl << endl;
    //     if (e2.get_health() == 10) break;   // break out of the loop if e1 does no damage
    // }

    // cout << "----------" << endl;

    // while (!e4.is_dead()) {
    //     e3.do_attack(e4);
    //     cout << e3 << endl << e4 << endl << endl;
    //     if (e4.get_health() == 10) break; // break out of the loop if e3 does no damage
    // }
    
    
    // map testing
    // int x, y;
    // cout << "Give x: ";
    // cin >> x;
    // cout << "Give y: ";
    // cin >> y;

    // map m(x, y);
    // cout << m;

    wnv game(5, 5);
    cout << game;

    return 0;
}