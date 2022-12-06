#include "common.hpp"
#include "map.hpp"
#include "entity.hpp"
#include "vampire.hpp"
#include "werewolf.hpp"

class wnv {
    public:
        wnv(int in_x, int in_y);
        ~wnv();
        friend ostream &operator<<(ostream &left, const wnv &right);
    private:
        int x;
        int y;
        map m;
        vampire *vampires;
        werewolf *werewolves;
};