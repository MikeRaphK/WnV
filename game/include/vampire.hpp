#pragma once
#include "entity.hpp"
#include "map.hpp"

class vampire : public entity {
    public:
        vampire();
        void move(map &m);
};