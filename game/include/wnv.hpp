#include <iostream>
#include <string>
#include "map.hpp"
#include "entity.hpp"

class wnv {
    public:
        wnv(int in_x, int in_y);
        ~wnv();
        //temporary helpful functions
        void print_werewolves();
        void print_vampires();
        friend ostream &operator<<(ostream &left, const wnv &right);
    private:
        int x;
        int y;
        int entity_count;
        map m;
        entity *werewolves;
        entity *vampires;
        std::string daytime;
};