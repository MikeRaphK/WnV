#include "win_entity.hpp"
#include "win_map.hpp"

// attack and defense are const so we use initializer list for them
entity::entity() : attack(1 + rand()%3), defense(1 + rand()%2) {  // attack: [1,3], defense: [1,2], attack: [0,2]
    potion = rand()%3;
    health = 10;
}


int entity::get_attack() const {
    return attack;
}

int entity::get_defense() const {
    return defense;
}

int entity::get_health() const {
    return health;
}

int entity::get_potion() const {
    return potion;
}

int entity::get_x() const {
    return x;
}

void entity::set_x(int in_x) {
    x = in_x;
}

int entity::get_y() const {
    return y;
}

void entity::set_y(int in_y) {
    y = in_y;
}

int entity::get_id() const {
    return id;
}

void entity::set_id(int in_id) {
    id = in_id;
}

void entity::heal() {   // increase entity's health by 1
    health++;
    if (health > 10) health = 10;   // don't exceed max health
}

void entity::do_attack(entity &enemy) { // current entity attacks enemy
    int damage = attack - enemy.defense;
    if (damage < 0) damage = 0;
    enemy.health -= damage;
}

bool entity::is_dead() {
    return health <= 0;
}

void entity::move(int in_x, int in_y) {}

void entity::entity_near(map &m) {
    /*
    ╔═════╦═════╦═════╗
    ║-x,-y║-x,y ║-x,+y║                 possible values of x = x-1, x+0, x+1 (temp_x + 2)
    ╠═════╬═════╬═════╣                 possible values of y = y-1, y+0, y+1                                        
    ║ x,-y║ x,y ║ x,+y║                 
    ╠═════╬═════╬═════╣                 and to check all cells we need all possible x with all possible y
    ║+x,-y║+x,y ║+x,+y║                 so we use nested loops!
    ╚═════╩═════╩═════╝
    */

    array<array<int, 7>, 2> neighbour_cells; //automatic array which is deleted when out of scope
    // a 2 sided array which saves the coords of the surrounding cells (8 neighbour cells)
    int counter = 0;
    int temp_x,temp_y;
    for(int i = -1  ; i <= 1 ; i++ ) { 
        for(int j = -1 ; j <= 1 ; j++ ) { 
            temp_x = x + i; // x-1, x , x+1
            temp_y = y + j; //y-1, y, y+1
            if (i + j != 0) {
                if (m.in_map(temp_x,temp_y)) {
                    if(m.is_vampire(temp_x,temp_y) || m.is_werewolf(temp_x,temp_y)) {
                        neighbour_cells[0][counter] = temp_x;
                        neighbour_cells[1][counter] = temp_y;
                        counter++;  
                    }
                }
            }
        }
    }
    cout << "The position" <<"(" << x << "," << y << "):\n";
    for (int i = 0 ; i < counter ; i++) {
        if (m.is_vampire(neighbour_cells[0][i] , neighbour_cells[1][i]) ) { //if neighbour cell is vampire
            if (m.is_vampire(x,y)) 
                cout << "heals->" << "(" << neighbour_cells[0][i] << "," << neighbour_cells[1][i] << ")" << endl;
            else if (m.is_werewolf(x,y)) 
                cout << "attacks " << "(" << neighbour_cells[0][i] << "," << neighbour_cells[1][i] << ")" << endl;
        }
        else if (m.is_werewolf(neighbour_cells[0][i] , neighbour_cells[1][i]) ) {
            if (m.is_vampire(x,y)) 
                cout << "attacks->" << "(" << neighbour_cells[0][i] << "," << neighbour_cells[1][i] << ")" << endl;
            else if (m.is_werewolf(x,y)) 
                cout << "heals->" << "(" << neighbour_cells[0][i] << "," << neighbour_cells[1][i] << ")" << endl;
        }
    } 
}

ostream &operator<<(ostream &left, const entity &right) {  // << overloading
    left << "Attack: " << right.attack << " Defense: " << right.defense << " Health: " << right.health << " Potion: " << right.potion << " Pos: (" << right.x << "," << right.y << ")";
    return left;
}