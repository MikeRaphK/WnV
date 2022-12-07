#include "common.hpp"
#include "map.hpp"
#include "entity.hpp"
#include "vampire.hpp"
#include "werewolf.hpp"

class wnv {
    public:
        wnv(int in_x, int in_y);
        ~wnv();
        void set_vampires(vampire* array);
        void set_werewolfs(werewolf* array);
        vampire* get_vampires();
        werewolf* get_werewolfs();
        map get_map();
        friend ostream &operator<<(ostream &left, const wnv &right);
    private:
        int x;
        int y;
        map m;
        vampire *vampires;
        werewolf *werewolfs;
};