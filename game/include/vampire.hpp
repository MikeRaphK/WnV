#pragma once
#include "entity.hpp"
#include "map.hpp"

class vampire : public entity {
    public:
        vampire();
        ~vampire();
        void move(map &m);
};