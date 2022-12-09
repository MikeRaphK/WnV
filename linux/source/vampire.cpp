#include "vampire.hpp"

vampire::vampire() : entity() {}

vampire::~vampire() {}

void vampire::move(map &m) {
    //cout << "Starting position:(" << x << "," << y << ")" << endl;
   
    //cout << "↓" << endl;
    //--------------------------------------------------
    /*
    ╔═════╦═════╦═════╗
    ║-x,-y║-x,y ║-x,+y║                 possible values of x = x-1, x+0, x+1 (temp_x + 2)
    ╠═════╬═════╬═════╣                 possible values of y = y-1, y+0, y+1                                        
    ║ x,-y║ x,y ║ x,+y║                 
    ╠═════╬═════╬═════╣                 and to check all cells we need all possible x with all possible y
    ║+x,-y║+x,y ║+x,+y║                 so we use nested loops!
    ╚═════╩═════╩═════╝
    */
    
    int** possible_moves = new int*[9]; // a 2 sided array which saves the coords of the possble moves (8 neighbour cells and 1(not move))
    for(int i = 0; i < 9; ++i) 
        possible_moves[i] = new int[2];

    int counter = 0;
    int temp_x,temp_y;
    for(int i = -1  ; i <= 1 ; i++ ) { 
        for(int j = -1 ; j <= 1 ; j++ ) { 
            temp_x = x + i; // x-1, x , x+1
            temp_y = y + j; //y-1, y, y+1
            if (m.in_map(temp_x,temp_y)) {
                if( m[temp_x][temp_y] == ' ') {
                    possible_moves[0][counter] = temp_x;
                    possible_moves[1][counter] = temp_y;
                    counter++;  
                }
            }
        }
    }
    counter--; //remove the one extra

  /*  cout << "Possible_moves:\n";
    for(int i = 0 ; i <= counter ; i++) {
        cout << "(" << possible_moves[0][i] << "," << possible_moves[1][i] << ")\t";
    }
    cout << endl << m;
    cout << "The one:\n(" << possible_moves[0][the_one] << "," << possible_moves[1][the_one] << ")\n";
    */
   
    int the_one = rand()%(counter+1);   //pick a random set of coords out of the possible ones
    m[x][y] = ' ';              
    x = possible_moves[0][the_one];     
    y = possible_moves[1][the_one];     
    m[x][y] = 'v';
}       


