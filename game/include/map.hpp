/* Απο προγραμματιστικη αποψη το σκεφτομαι καπως ετσι:
    class map {
        ...
    };
    class entity {
        ...
    };
    class vampire : public entity {
        ...
    };
    class werewolf : public entity {
        ...
    };
    class player : public entity {
        ...
    };
    class game {
        public:
            ...
        private:
            map m;
            werewolf w;
            vampire v;
            player p;
    };
*/
#pragma once
#include <iostream>
using std::ostream;
class map {
    public:
        map(int in_x, int in_y);
        ~map();
        friend ostream &operator<<(ostream &left, const map &right);
    private:
        int x;
        int y;
        char **m;
};