#include "vampire.hpp"
#include "werewolf.hpp"

class avatar : public entity {
    public:
        avatar(char race);
        bool is_vampire();
        bool is_werewold();
        void stats();
    private:
        bool vamp;
        bool were;
};