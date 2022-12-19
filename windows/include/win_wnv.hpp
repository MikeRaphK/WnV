#include "win_common.hpp"
#include "win_map.hpp"
#include "win_entity.hpp"
#include "win_vampire.hpp"
#include "win_werewolf.hpp"
#include "win_avatar.hpp"

class wnv {
    public:
        wnv(char race, int in_y, int in_x);
        ~wnv();
        void set_vampires(vampire* array);
        void set_werewolfs(werewolf* array);
        vampire* get_vampires();
        werewolf* get_werewolfs();
        map get_map();
        string get_time() const;
        void player_turn();
        void vampire_turn();
        void werewolf_turn();
        void show();
        bool is_day();
        bool is_night();
        void cycle_time();
        void interactions();
        void entity_near(int id, char type);
        int coords_to_id(int in_x, int in_y, char type);
        bool is_game_finished();
    private:
        int x;
        int y;
        int turn;
        int vampire_count;
        int werewolf_count;
        string time;
        map m;
        vampire *vampires;
        werewolf *werewolfs;
        avatar player;
};