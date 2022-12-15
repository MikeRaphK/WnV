#include <iostream>
#include <cstdlib>
#include <ctime>
#include "win_wnv.hpp"
#include "win_dialogue.hpp"

int main() {
    // initializers
    srand(time(0));
    dialogue user;
    user.starting_message();
    wnv game(user.get_race(), user.get_y(), user.get_x());

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
