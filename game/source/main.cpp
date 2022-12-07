#include <iostream>
#include <cstdlib>
#include <ctime>
#include "wnv.hpp"
using namespace std;

int main() {
    srand(time(0));
    wnv game(10, 10, 'V');
    cout << game;
    game.player_stats();

    return 0;
}