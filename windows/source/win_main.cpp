#include <iostream>
#include <cstdlib>
#include <ctime>
#include "win_wnv.hpp"

int main() {
    // initializers
    srand(time(0));
    
    wnv game(10, 10, 'V');

        // all that is left is to make entities interact with each other
        while (true) {
            game.show();
            game.player_turn();
            game.vampire_turn();
            game.werewolf_turn();
        }
        cout << endl;

    return 0;
}