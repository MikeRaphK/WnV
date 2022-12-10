#include "win_vampire.hpp"
#include "win_werewolf.hpp"

class avatar : public entity {
    public:
        avatar(char race);
        bool is_vampire();
        bool is_werewold();
        void show_stats();
        void move(string move, map &m);
    private:
        bool vamp;
        bool were;
};