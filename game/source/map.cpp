#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/map.hpp"
using namespace std;

map::map(int in_x, int in_y) {  // map constructor allocates memory and initializes the board 
    int i, j;
    x = in_x;
    y = in_y;

    // memory allocation 
    m = new char*[x];
    if (!m) cout << "Error allocating memory" << endl;

    for (i = 0 ; i < x ; i++) {
        m[i] = new char [y];
        if (!m[i]) cout << "Error allocating memory" << endl;
    }

    // entity init 
    for (j = 0 ; j < y ; j++) {
        // v: vampire , w: werewolf 
        m[0][j] = 'v';
        m[x-1][j] = 'w';
    }

    // terrain init 
    for (i = 1 ; i < x-1 ; i++) {
        for (j = 0 ; j < y ; j++) {
            // '.': Water , '*': Tree , "Empty": Land
            int rng = rand()%20;    // get a random number from 0-20. this allows us to get a 5% chance for Tree, 5% for Water and 90% for Land
            switch (rng) {
            case 0:
                m[i][j] = '.';
                break;
            case 1:
                m[i][j] = '*';
                break;
            default:
                m[i][j] = ' ';
                break;
            }
        }
    }
}

map::~map() {   // map destructor frees the allocated memory
    for (int i = 0 ; i < x ; i++)
        delete[] m[i];
    delete[] m;
}

bool map::is_obstacle(int in_x, int in_y) { // returns true if there is an obstacle in the selected position, false otherwise
    if (in_x >= x || in_y >= y) return false;
    return m[in_x][in_y] == '.' || m[in_x][in_y] == '*';
}

bool map::is_vampire(int in_x, int in_y) { // returns true if there is a vampire in the selected position, false otherwise 
    if (in_x >= x || in_y >= y) return false;
    return m[in_x][in_y] == 'v' || m[in_x][in_y] == 'V';
}

bool map::is_werewolf(int in_x, int in_y) { // returns true if there is a vampire in the selected position, false otherwise 
    if (in_x >= x || in_y >= y) return false;
    return m[in_x][in_y] == 'w' || m[in_x][in_y] == 'W';
}

ostream &operator<<(ostream &left, const map &right) {  // << overloading
    int i, j, k;
    // First row 
    left << "╔";
    for (i = 0 ; i < right.y  ; i++) {
        left << "═══╦";
    }
    left << "\b╗" << endl << "║ ";
    for (j = 0 ; j < right.y; j++)
        left << right.m[0][j] << " ║ ";
    left << endl;
    //Box 
    for (i = 1 ; i < right.x ; i++) {
        // This is used to print in-between lines 
        left << "╠";
        for (k = 0 ; k < right.y ; k++)
            left << "═══╬";
        left << "\b╣";
        left << endl << "║ ";
        // This is used to print the boxes 
        for (j = 0 ; j < right.y ; j++)
            left << right.m[i][j] << " ║ ";
        left << endl;
    }
    //Last line
     left << "╚";
    for (j = 0 ; j < right.y; j++)
        left << "═══╩";
    left << "\b╝" << endl;
    
    return left;
}