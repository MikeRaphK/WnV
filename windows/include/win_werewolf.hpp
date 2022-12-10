#pragma once
#include "win_entity.hpp"
#include "win_map.hpp"

class werewolf : public entity {
    public:
        werewolf();
        ~werewolf();
        void move(map &m);
};