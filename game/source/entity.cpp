#include <cstdlib>
#include "entity.hpp"

// attack and defense are const so we use initializer list for them
entity::entity() : attack(1 + rand()%3), defense(1 + rand()%2) {  // attack: [1,3], defense: [1,2], attack: [0,2]
    potion = rand()%3;
    health = 10;
}

int entity::get_attack() const {
    return attack;
}

int entity::get_defense() const {
    return defense;
}

int entity::get_health() const {
    return health;
}

int entity::get_potion() const {
    return potion;
}

int entity::get_x() const {
    return x;
}

void entity::set_x(int in_x) {
    x = in_x;
}

int entity::get_y() const {
    return y;
}

void entity::set_y(int in_y) {
    y = in_y;
}

void entity::do_attack(entity &enemy) { // current entity attacks enemy
    int damage = attack - enemy.defense;
    if (damage < 0) damage = 0;
    enemy.health -= damage;
}

bool entity::is_dead() {
    return health <= 0;
}

ostream &operator<<(ostream &left, const entity &right) {  // << overloading
    left << "Attack: " << right.attack << " Defense: " << right.defense << " Health: " << right.health << " Potion: " << right.potion << " Pos: (" << right.x << "," << right.y << ")";
    return left;
}