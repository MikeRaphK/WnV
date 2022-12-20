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

    while (!game.is_game_finished()) {
        game.show();
        game.player_turn();
        game.vampire_turn();
        game.werewolf_turn();
        game.interactions();
    }
    game.result();
    user.closing_message();

    return 0;
}
