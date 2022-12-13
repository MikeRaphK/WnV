#include "win_map.hpp"

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

    // terrain init 
    for (i = 0 ; i < x ; i++) {
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

    // potion init
    m[rand()%x][rand()%y] = 'p';

    //entity init 
    for( i = 0 ; i < (x*y/15) * 2 ; i++ ) {
        char temp;
        int k,l;
        do {
            k = rand()%x;
            l = rand()%y;
            temp = m[k][l];
        }while ( temp != ' ');
        
        if (i % 2 == 0) 
            m[k][l] = 'w';
        else
            m[k][l] = 'v';  
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

int map::get_x() {
    return x;
}

int map::get_y() {
    return y;
}

bool map::in_map(int in_x, int in_y) {
    if(in_x  < 0 || in_y < 0 || in_x + 1 > x || in_y + 1 > y) {
        return false;
    }
    else {
        return true;
    } 
}

ostream &operator<<(ostream &left, const map &right) {  // << overloading for map
    int i, j, k;
    //top row of numbers 
    left << "WnV   ";
    for (i = 0 ; i < right.y ; i++) {
        if (i < 9)
            left << i << "   "; //1 digit numbers 
        else if (i < 100)
            left << i << "  "; //2 digit numbers
        else
            left << i << " "; //3 digit numbers
    }
    left << endl;
    // First row 
    left << "    " << char(201); // "╔"
    for (i = 0 ; i < right.y  ; i++) {
        left << char(205) << char(205) << char(205) << char(203); // "═══╦"
    }
    left << "\b" << char(187) << endl << "0   "<< char(186) << " "; //"\b╗\n0   ║ "
    for (j = 0 ; j < right.y; j++)
        left << right.m[0][j] << " " <<  char(186) << " "; //" ║ " 
    left << endl;
    //Box 
    for (i = 1 ; i < right.x ; i++) {
        
        // This is used to print in-between lines 
        left << "    " << char(204);  //"   ╠"
        for (k = 0 ; k < right.y ; k++)
            left << char(205) << char(205) << char(205) << char(206); //"═══╬"
        left << "\b" << char(185); //"\b╣"
        left << endl;
        if (i < 10)
            left << i << "  "; //1 digit numbers 
        else if (i < 100)
            left << i << " "; //2 digit numbers
        else
            left << i; //3 digit numbers
        left << " " <<  char(186) << " "; //" ║ "
        // This is used to print the boxes 
        for (j = 0 ; j < right.y ; j++)
            left << right.m[i][j] << " " <<  char(186) << " "; //" ║ "
        left << endl;
    }
    //Last line
     left << "    " << char(200); //"    ╚"
    for (j = 0 ; j < right.y; j++)
        left << char(205) << char(205) << char(205) << char(202); //"═══╩"
    left << "\b" << char(188) << endl; //"\b╝\n"
    
    return left;
}

char* map::operator[](int i) { // [] overloading for an array
    return m[i];
}