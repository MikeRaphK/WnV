#pragma once
#include "entity.hpp"
#include "map.hpp"

// vampire inherits entity class
class vampire : public entity {
    public:
        vampire();
        void move(map &m);
};
