#include "vampire.hpp"
#include "werewolf.hpp"

class avatar : public entity {
    public:
        avatar(char race);
        bool is_vampire();
        bool is_werewolf();
        void show_stats();
        void move(string move, map &m);
        void heal(vampire *(&vampires), int size);
        void heal(werewolf *(&werewolfs), int size);
    private:
        bool vamp;
        bool were;
};