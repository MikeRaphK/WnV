#include "vampire.hpp"
#include "werewolf.hpp"

class avatar : public entity {
    public:
        avatar();
        avatar &operator=(const vampire right);
        avatar &operator=(const werewolf right);
    private:
        bool is_vampire;
        bool is_werewolf;
};