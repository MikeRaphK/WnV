#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/wnv.hpp"

int main() {
    // initializers
    srand(time(0));
    
    wnv game(10, 10, 'V');

        // game only lets player move
        while (true) {
            game.show();
            game.player_turn();
        }
        cout << endl;

    return 0;
}