#pragma once
#include "win_entity.hpp"
#include "win_map.hpp"

class vampire : public entity {
    public:
        vampire();
        ~vampire();
        void move(map &m);
};