#pragma once
#include "common.hpp"

class entity {
    public:
        entity();
        int get_attack() const;
        int get_defense() const;
        int get_health() const;
        int get_potion() const;
        int get_x() const;
        void set_x(int in_x);
        int get_y() const;
        void set_y(int in_y);
        int get_identifier();
        void set_identifier(int in_identifier);
        void do_attack(entity &enemy);
        bool is_dead();
        virtual void move(int in_x, int in_y);
        friend ostream &operator<<(ostream &left, const entity &right);
    protected:
        const int attack;
        const int defense;
        int health;
        int potion;
        int x;
        int y;
        int id;
};