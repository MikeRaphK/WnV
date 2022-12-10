#include "win_common.hpp"
#include "win_map.hpp"
#include "win_entity.hpp"
#include "win_vampire.hpp"
#include "win_werewolf.hpp"
#include "win_avatar.hpp"

class wnv {
    public:
        wnv(int in_x, int in_y, char race);
        ~wnv();
        void set_vampires(vampire* array);
        void set_werewolfs(werewolf* array);
        vampire* get_vampires();
        werewolf* get_werewolfs();
        map get_map();
        string get_time() const;
        void player_turn();
        void show();
    private:
        int x;
        int y;
        int vampire_count;
        int werewolf_count;
        string time;
        map m;
        vampire *vampires;
        werewolf *werewolfs;
        avatar player;
};