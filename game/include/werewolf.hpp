#pragma once
#include "entity.hpp"
#include "map.hpp"

// werewolf inherits entity class
class werewolf : public entity {
    public:
        werewolf();
        void move(map &m);
};