#include "avatar.hpp"

avatar::avatar() : entity() {}

avatar &avatar::operator=(const vampire right) {
    potion = right.get_potion();
    health = right.get_health();
    x = right.get_x();
    y = right.get_y();
    id = right.get_id();

    return *this;
}

avatar &avatar::operator=(const werewolf right) {
    potion = right.get_potion();
    health = right.get_health();
    x = right.get_x();
    y = right.get_y();
    id = right.get_id();

    return *this;
}