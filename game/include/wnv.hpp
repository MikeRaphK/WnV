#include "map.hpp"
#include "entity.hpp"
#include <string>

class wnv {
    public:
        wnv(int in_x, int in_y);
        ~wnv();
        friend ostream &operator<<(ostream &left, const wnv &right);
    private:
        int x;
        int y;
        int entity_count;
        map m;
        entity *werewolves;
        entity *vampires;
        string daytime;
};