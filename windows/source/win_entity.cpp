#include "win_entity.hpp"

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

int entity::get_id() const {
    return id;
}

void entity::set_id(int in_id) {
    id = in_id;
}

void entity::heal() {   // increase entity's health by 1
    health++;
    if (health > 10) health = 10;   // don't exceed max health
}

void entity::do_attack(entity &enemy) { // current entity attacks enemy
    int damage = attack - enemy.defense;
    if (damage < 0) damage = 0;
    enemy.health -= damage;
}

bool entity::is_dead() {
    return health <= 0;
}

void entity::move(int in_x, int in_y) {}

ostream &operator<<(ostream &left, const entity &right) {  // << overloading
    left << "Attack: " << right.attack << " Defense: " << right.defense << " Health: " << right.health << " Potion: " << right.potion << " Pos: (" << right.x << "," << right.y << ")";
    return left;
}
