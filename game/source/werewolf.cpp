#include "werewolf.hpp"

werewolf::werewolf() : entity() {}

void werewolf::move(map &m) {
    /*
    ╔═════╦═════╦═════╗
    ║-x,-y║-x,y ║-x,+y║                 
    ╠═════╬═════╬═════╣                                                      
    ║ x,-y║ x,y ║ x,+y║                 possible pairs to move: (-x,y), (+x,y), (x,-y), (x,+y)
    ╠═════╬═════╬═════╣                 
    ║+x,-y║+x,y ║+x,+y║                
    ╚═════╩═════╩═════╝                 Note: +x = x + 1, -y = y - 1, ...
    */                                   
    array<array<int, 9>, 2> possible_moves; //automatic array which is deleted when out of scope
    // a 2 sided array which saves the coords of the possible moves (4 neighbour cells and 1(not move))

    int counter = 0;
    int temp_x,temp_y;
    for(int i = -1  ; i <= 1 ; i++ ) { 
        for(int j = -1 ; j <= 1 ; j++ ) { 
            temp_x = x + i; // x-1, x , x+1
            temp_y = y + j; //y-1, y, y+1
            if (m.in_map(temp_x,temp_y) && ( i == 0 || j == 0 )) { // with the OR filter it only checks the cross of the above square
                if( m[temp_x][temp_y] == ' ') {
                    possible_moves[0][counter] = temp_x;
                    possible_moves[1][counter] = temp_y;
                    counter++;  
                }
            }
        }
    } 
    //Note counter is 5 because of loop end and its ready for the not move case
    //add manually the possibility to not move:
    possible_moves[0][counter] = x;
    possible_moves[1][counter] = y;
    

    int the_one = rand()%(counter+1);   //pick a random set of coords out of the possible ones  
    m[x][y] = ' ';              
    x = possible_moves[0][the_one];     //and switch 'em
    y = possible_moves[1][the_one];     
    m[x][y] = 'w';

    return;
}