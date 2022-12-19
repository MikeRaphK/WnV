#include "win_entity.hpp"
#include "win_map.hpp"

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
    if (health < 10)
        health++;
    return;
}

void entity::do_heal(entity &teammate) {
    int chance = rand() % 2;
    if (chance % 2 == 0) { //50% chance to get in
        if (potion > 0 && teammate.health < 10) { //if current has potions and teammate is not full health
            potion--;
            teammate.health++;
          //  cout << "(" << x << "," << y << ") heals->(" << teammate.x << "," << teammate.y << ")\n";
          //  cout << "   (" << teammate.x << "," << teammate.y << ") new health is: " << teammate.health << endl;
        }
    }
    return;
}

void entity::do_attack(entity &enemy) { // current entity attacks enemy
    int damage = attack - enemy.defense;
    if (damage < 0) damage = 0;
    enemy.health -= damage;
    if (damage > 0 ) {
       // cout << "(" << x << "," << y << ") attacks->(" << enemy.x << "," << enemy.y << ")\n";
       // cout << "   (" << enemy.x << "," << enemy.y << ") new health is: " << enemy.health << endl;
    }
    
}

bool entity::is_dead() {
    return health <= 0;
}

void entity::move(int in_x, int in_y) {}

ostream &operator<<(ostream &left, const entity &right) {  // << overloading
    left << "Attack: " << right.attack << " Defense: " << right.defense << " Health: " << right.health << " Potion: " << right.potion << " Pos: (" << right.x << "," << right.y << ")";
    return left;
}