#include <iostream>
#include <cstdlib>
#include <ctime>
#include "wnv.hpp"
using namespace std;

int main() {
    // initializers
    srand(time(0));
    wnv game(10, 10, 'V');
    system("clear");

    while (true) {
        // print the game and the stats
        game.show();

        // only available move for player is up, down, left, right
        string move;
        while (move != "up" && move != "down" && move != "left" && move != "right" && move != "q") {
            cout << "Give move for player[up, down, left, right] or press q to quit: ";
            cin >> move;
        }
        
        // check if player quits
        if (move == "q") break;

        // do the move
        game.player_move(move);
        cout << endl;
    }

    return 0;
}