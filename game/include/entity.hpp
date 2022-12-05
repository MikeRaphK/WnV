#pragma once
#include "common.hpp"

class entity {
    public:
        entity();
        int get_attack() const;
        int get_defense() const;
        int get_health() const;
        int get_potion() const;
        void set_x(int in_x);
        void set_y(int in_y);
        void do_attack(entity &enemy);
        bool is_dead();
        friend ostream &operator<<(ostream &left, const entity &right);
    protected:
        const int attack;
        const int defense;
        int health;
        int potion;
        int x;
        int y;
};