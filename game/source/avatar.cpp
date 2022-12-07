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
}

bool avatar::is_vampire() {
    return vamp == true;
}

bool avatar::is_werewold() {
    return were == true;
}

void avatar::stats() {  // prints the avatar's stats to the screen
    cout << "Player stats: " << *this;
    if (is_vampire()) cout << " Race: Vampire" << endl;
    else cout << " Race: Werewolf" << endl;
}

avatar &avatar::operator=(const vampire right) {    // = overloading for vampires
    potion = right.get_potion();
    health = right.get_health();
    x = right.get_x();
    y = right.get_y();
    id = right.get_id();

    return *this;
}

avatar &avatar::operator=(const werewolf right) {   // = overloading for werewolves using polymorphism
    potion = right.get_potion();
    health = right.get_health();
    x = right.get_x();
    y = right.get_y();
    id = right.get_id();

    return *this;
}