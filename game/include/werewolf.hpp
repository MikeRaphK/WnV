#pragma once
#include "entity.hpp"
#include "map.hpp"

class werewolf : public entity {
    public:
        werewolf();
        void move(map &m);
};