#include "wnv.hpp"
#include "vampire.hpp"
#include "werewolf.hpp"
#include "common.hpp"
#include <windows.h>


wnv::wnv(char race, int in_y, int in_x) : m(in_x, in_y), player(race) {
    x = in_x;
    y = in_y;
    turn = 0;
    vampire_count = x*y/15;
    werewolf_count = x*y/15;
    if (rand()%2) time = "Day";
    else time = "Night"; 
//-------------vampires-----------------------    
    vampires = new vampire [x*y/15];
    int i, j, k = 0;
    for (i = 0 ; i < x ; i++) {
        for (j = 0 ; j < y ; j++) {
            if ( m[i][j] == 'v') {
                vampires[k].set_x(i);
                vampires[k].set_y(j);
                vampires[k].set_id(k);
                k++;
            }
        }
    }
//-------------werewolfs-----------------------
    k = 0;
    werewolfs = new werewolf [x*y/15];
    for (i = 0 ; i < x ; i++) {
        for (j = 0 ; j < y ; j++) {
            if ( m[i][j] == 'w') {
                werewolfs[k].set_x(i);
                werewolfs[k].set_y(j);
                werewolfs[k].set_id(k);
                k++;
            }
        }
    }

//-------------player-----------------------
    int rand_x = rand()%x;
    int rand_y = rand()%y;
    while (m[rand_x][rand_y] != ' ') {  // find an empty space
        rand_x = rand()%x;
        rand_y = rand()%y;
    }
    // place the player in the empty space
    player.set_x(rand_x);
    player.set_y(rand_y);
    m[rand_x][rand_y] = 'A';
//-----------------------------------------
};

wnv::~wnv() {
    delete [] vampires;
    delete [] werewolfs;
}

void wnv::player_turn() {   // During their turn the player can move, wait, pause or quit
    while (true) {
        if (GetKeyState(VK_UP) & 0x8000) {  // if up is pressed, move up
            player.move("up", m);
            break;
        }
        if (GetKeyState(VK_DOWN) & 0x8000) { // if down is pressed, move down
            player.move("down", m);
            break;
        }
        if (GetKeyState(VK_LEFT) & 0x8000) { // if left is pressed, move left
            player.move("left", m);
            break;
        }
        if (GetKeyState(VK_RIGHT) & 0x8000) { // if right is pressed, move right
            player.move("right", m);
            break;
        }
        if (GetKeyState(VK_SPACE) & 0x8000) {   // if space is pressed, heal
            if (player.get_potion() > 0 ) {
                if (player.is_vampire() && is_day()) {
                    player.heal(vampires, x*y/15); // heal vampires only during the day
                } 
                else if (player.is_werewolf() && is_night()) {
                    player.heal(werewolfs, x*y/15);    // heal werewolfs only during the night
                }
                // if none of the above apply, player can't heal during that round and they lose a turn
                break;
            }
        }
        if (GetKeyState('P') & 0x8000) { // if P is pressed, pause
            //---------------first line----------------
            cout << char(201);
            for (int i = 0 ; i < 19 ; i++)
                cout << char(205);
            cout << char(187) << endl;
            //---------------middle line---------------
            cout << char(186) << "    GAME PAUSED    " << char(186) << endl;
             //---------------last line----------------- 
            cout << char(200); 
            for (int i = 0 ; i < 19 ; i++)
                cout << char(205);
            cout << char(188) << endl;
            player.show_stats();
            cout << "Number of active vampires: " << vampire_count << endl;
            cout << "Number of active werewolves: " << werewolf_count << endl;
            system("pause");
            break;
        }
        if (GetKeyState('Q') & 0x8000) { // if Q is pressed, quit
            cout << "Quitting..." << endl;
            exit(0);
        }
    }
    Sleep(100); // add a 100ms delay so no accidental double-presses are registered

    turn++; // raise the turn counter
    if (turn % 3 == 0) cycle_time();    // change the time once every 3 turns
}

void wnv::vampire_turn() {
    for (int i = 0 ; i < x*y/15 ; i++) {
        if ( !(vampires[i].is_dead()) )
            vampires[i].move(m);
    } 
}

void wnv::werewolf_turn() {
    for (int i = 0 ; i < x*y/15 ; i++) {
        if ( !(werewolfs[i].is_dead()) )
            werewolfs[i].move(m);
    } 
}

void wnv::interactions() {
    for (int i = 0 ; i < x*y/15 ; i++) {
        if ( !(vampires[i].is_dead()) )
            entity_near(vampires[i].get_id(), 'v');
    }
    for (int i = 0 ; i < x*y/15 ; i++) {
        if ( !(werewolfs[i].is_dead()) )
            entity_near(werewolfs[i].get_id(), 'w');
    }
    //check for every vampire if its dead 
    for (int i = 0 ; i < x*y/15 ; i++) {
        if ( vampires[i].is_dead() && vampires[i].get_x() >= 0 ) { //if it just died (dead but not already dead)
            cout << "Vampire previously at (" << vampires[i].get_x() << "," << vampires[i].get_y() << ") is now dead!\n";
            Sleep(1500);
            m.clear_cell(vampires[i].get_x(), vampires[i].get_y());
            vampires[i].set_x(-1);
            vampire_count--;
        }
        
        if ( werewolfs[i].is_dead() && werewolfs[i].get_x() >= 0 ) { //if it just died (dead but not already dead)
            cout << "Werewolf previously at (" << werewolfs[i].get_x() << "," << werewolfs[i].get_y() << ") is now dead!\n";
            Sleep(1500);
            m.clear_cell(werewolfs[i].get_x(), werewolfs[i].get_y());
            werewolfs[i].set_x(-1);
            werewolf_count--;
        }
    }

}

void wnv::entity_near(int id, char type) {
    int entity_x, entity_y;
    if ( type == 'v') {
        entity_x = vampires[id].get_x();
        entity_y = vampires[id].get_y();
    } else if (type == 'w'){
        entity_x = werewolfs[id].get_x();
        entity_y = werewolfs[id].get_y();
    } else {
        cout << "ERROR:wrong type input in entity near\n"; 
        return;
    }
    
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
            temp_x = entity_x + i; // x-1, x , x+1
            temp_y = entity_y + j; //y-1, y, y+1
            //cout << "CHECKING" << "(" << temp_x << "," << temp_y << ")" << endl;
            if (! (temp_x == entity_x && temp_y == entity_y) ) {
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

    for (int i = 0 ; i < counter ; i++) { //for every neighbour entity
        if (m.is_vampire(neighbour_cells[0][i] , neighbour_cells[1][i]) ) { //if neighbour cell is vampire
            if (m.is_vampire(entity_x,entity_y)) { //if the current position is vampire->heal
                //conditionally heal the teammate
                vampires[coords_to_id(entity_x , entity_y, 'v')].do_heal(vampires[ coords_to_id(neighbour_cells[0][i], neighbour_cells[1][i], 'v') ]  );
            }
            else if (m.is_werewolf(entity_x, entity_y)) { //if the current position is werewolfs->attack
                //current attacks conditionally the enemy 
                werewolfs[coords_to_id(entity_x , entity_y, 'w')].do_attack(vampires[coords_to_id(neighbour_cells[0][i] , neighbour_cells[1][i], 'v')]);
            }
        }
        else if (m.is_werewolf(neighbour_cells[0][i] , neighbour_cells[1][i]) ) { //if neighbour cell is werewolf
            if (m.is_vampire(entity_x, entity_y)) { //if the current position is vampire->attack
                //current attacks conditionally the enemy 
                vampires[coords_to_id(entity_x , entity_y, 'v')].do_attack(werewolfs[coords_to_id(neighbour_cells[0][i] , neighbour_cells[1][i], 'w')]);
            }
            else if (m.is_werewolf(entity_x, entity_y)) { //if the current position is werewolf->heal
                 //conditionally heal the teammate
                werewolfs[coords_to_id(entity_x , entity_y, 'w')].do_heal(werewolfs[ coords_to_id(neighbour_cells[0][i], neighbour_cells[1][i], 'w') ]  );
            }
        }
    }



}

int wnv::coords_to_id(int in_x, int in_y, char type) {
    if ( type == 'v') {
        for(int i = 0 ; i < x*y/15 ; i++ )
            if (in_x == vampires[i].get_x() && in_y == vampires[i].get_y() )
                return vampires[i].get_id();
    } else if (type == 'w'){
        for(int i = 0 ; i < x*y/15 ; i++ )
            if (in_x == werewolfs[i].get_x() && in_y == werewolfs[i].get_y() )
                return werewolfs[i].get_id();
    } else {
        cout << "ERROR:wrong type input in coords to id\n"; 
        return -1;
    }
    return -1;
}


void wnv::show() {  // prints time, round, map and player stats
    system("cls");
    cout << "Time: " << time <<  "   |   Turn: " << turn << endl;
    cout << m;
    player.show_stats();
}

bool wnv::is_day() {    // returns true if it is day, false otherwise
    return time == "Day";
}

bool wnv::is_night() {  // returns true if it is night, false otherwise
    return time == "Night";
}

void wnv::cycle_time() {    // cycle through day and night
    if (time == "Day") time = "Night";
    else time = "Day";
}

bool wnv::is_game_finished() {
    if (vampire_count == 0 || werewolf_count == 0)
        return true;
    else 
        return false;
}

void wnv::result() {
    system("cls");
     if (vampire_count == 0 ) {
        if (player.is_werewolf()) {
            //---------------first line----------------
            cout << char(201);
            for (int i = 0 ; i < 34 ; i++)
                cout << char(205);
            cout << char(187) << endl;
            //---------------middle line---------------
            cout << char(186) << "               YOU WON!           "<< char(186) << endl;
            cout << char(186) << "           With: " << player.get_potion() << " potions        " << char(186) << endl;
            cout << char(186) << " The werewolves are now victorious" << char(186) << endl;
            //---------------last line----------------- 
            cout << char(200);
            for (int i = 0 ; i < 34 ; i++)
                cout << char(205);
            cout << char(188) << endl;
        }
        else { 
            //---------------first line----------------
            cout << char(201);
            for (int i = 0 ; i < 34 ; i++)
                cout << char(205);
            cout << char(187) << endl;
            //---------------middle line---------------
            cout << char(186) << "              YOU LOST!           "<< char(186) << endl;
            cout << char(186) << "           With: " << player.get_potion() << " potions        " << char(186) << endl;
            cout << char(186) << " The vampires are dissapointed... " << char(186) << endl;
            //---------------last line----------------- 
            cout << char(200);
            for (int i = 0 ; i < 34 ; i++)
                cout << char(205);
            cout << char(188) << endl;
        } 
    } else if (werewolf_count == 0) { 
        if (player.is_vampire()) {
            //---------------first line----------------
            cout << char(201);
            for (int i = 0 ; i < 34 ; i++)
                cout << char(205);
            cout << char(187) << endl;
            //---------------middle line---------------
            cout << char(186) << "               YOU WON!           "<< char(186) << endl;
            cout << char(186) << "           With: " << player.get_potion() << " potions        " << char(186) << endl;
            cout << char(186) << "  The vampires are now victorious " << char(186) << endl;
            //---------------last line----------------- 
            cout << char(200);
            for (int i = 0 ; i < 34 ; i++)
                cout << char(205);
            cout << char(188) << endl;
        } else { 
             //---------------first line----------------
            cout << char(201);
            for (int i = 0 ; i < 34 ; i++)
                cout << char(205);
            cout << char(187) << endl;
            //---------------middle line---------------
            cout << char(186) << "              YOU LOST!           "<< char(186) << endl;
            cout << char(186) << "           With: " << player.get_potion() << " potions        " << char(186) << endl;
            cout << char(186) << "The werewolves are dissapointed..." << char(186) << endl;
            //---------------last line----------------- 
            cout << char(200);
            for (int i = 0 ; i < 34 ; i++)
                cout << char(205);
            cout << char(188) << endl;
        }
    }
    cout << endl;  
    system("pause");
}