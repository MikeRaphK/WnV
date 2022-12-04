#pragma once
#include <iostream>
using std::ostream;
class map {
    public:
        map(int in_x, int in_y);
        ~map();
        bool is_obstacle(int in_x, int in_y);
        bool is_vampire(int in_x, int in_y);
        bool is_werewolf(int in_x, int in_y);
        friend ostream &operator<<(ostream &left, const map &right);
    private:
        int x;
        int y;
        char **m;
};