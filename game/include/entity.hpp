#pragma once
#include <iostream>
using std::ostream;

class entity {
    public:
        entity();
        int get_attack() const;
        int get_defense() const;
        int get_health() const;
        int get_potion() const;
        void do_attack(entity &enemy);
        bool is_dead();
        friend ostream &operator<<(ostream &left, const entity &right);
    protected:
        int attack;
        int defense;
        int health;
        int potion;
};