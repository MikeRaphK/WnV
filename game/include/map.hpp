#pragma once
#include "common.hpp"

class map {
    public:
        map(int in_x, int in_y);
        ~map();
        bool is_obstacle(int in_x, int in_y);
        bool is_vampire(int in_x, int in_y);
        bool is_werewolf(int in_x, int in_y);
        void clear_cell(int in_x, int in_y);
        int get_x();
        int get_y();
        bool in_map(int in_x, int in_y);
        friend ostream &operator<<(ostream &left, const map &right);
        char* operator[](int i);
    private:
        int x;
        int y;
        char **m;
};