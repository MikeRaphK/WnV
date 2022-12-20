#pragma once
#include "common.hpp"
#include "map.hpp"
#include <array>

class entity {
    public:
        entity();
        entity(const entity &e);
        int get_attack() const;
        int get_defense() const;
        int get_health() const;
        int get_potion() const;
        int get_x() const;
        int get_y() const;
        int get_id() const;
        void set_x(int in_x);
        void set_y(int in_y);
        void set_id(int in_id);
        void heal();
        void do_heal(entity &enemy);
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