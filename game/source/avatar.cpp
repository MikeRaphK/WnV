#include "avatar.hpp"

avatar::avatar(char race) : entity() {
    if (race == 'v' || race == 'V') {
        vamp = true;
        were = false;
    }
    else {
        vamp = true;
        were = false;
    }
    potion = 1;
}

bool avatar::is_vampire() {
    return vamp == true;
}

bool avatar::is_werewold() {
    return were == true;
}

void avatar::stats() {  // prints the avatar's stats to the screen (we can't overload << because it is a friend function in entity class)
    cout << "Player stats: Potion: " << potion << " Pos: (" << x << "," << y << ")";
    if (is_vampire()) cout << " Race: Vampire" << endl;
    else cout << " Race: Werewolf" << endl;
}