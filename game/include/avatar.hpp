#include "vampire.hpp"
#include "werewolf.hpp"

class avatar : public entity {
    public:
        avatar(char race);
        bool is_vampire();
        bool is_werewold();
        void stats();
        avatar &operator=(const vampire right);
        avatar &operator=(const werewolf right);
    private:
        bool vamp;
        bool were;
};