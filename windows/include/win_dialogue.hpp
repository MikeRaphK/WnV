#include "win_common.hpp"

class dialogue {
public:
    dialogue();
    ~dialogue();
    void starting_message();
    void closing_message(); 
    int get_x();
    int get_y();
    char get_race();
};