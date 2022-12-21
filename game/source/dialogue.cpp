#include "dialogue.hpp"

void dialogue::starting_message() { // starting message
    system("cls");
    //---------------first line----------------
    cout << char(201);
    for (int i = 0 ; i < 39 ; i++)
        cout << char(205);
    cout << char(187) << endl;
    //---------------middle line---------------
    cout << char(186) << "                                       " << char(186) << endl;
    cout << char(186) << " WELCOME TO WnV GAME BY MIKE AND TONY! " << char(186) << endl;
    cout << char(186) << "                                       " << char(186) << endl;
    //---------------last line----------------- 
    cout << char(200);
    for (int i = 0 ; i < 39 ; i++)
        cout << char(205);
    cout << char(188) << endl << endl; 
}

int dialogue::get_x() { // prompt user to enter x
    int usr_x;
    cout << "Give the x of the map: ";
    cin >> usr_x;
    while (usr_x <= 1 || usr_x > 999) {
        cout << "Please enter a reasonable value for x: ";
        cin >> usr_x; 
    }
    return usr_x;
}

int dialogue::get_y() { // prompt user to enter y
    int usr_y;
    cout << "Give the y of the map: ";
    cin >> usr_y;
    while (usr_y <= 1 || usr_y > 999) {
        cout << "Please enter a reasonable value for y: ";
        cin >> usr_y; 
    }
    return usr_y;
}

char dialogue::get_race() { // prompt user to enter race
    string usr_race;
    cout << "Specify the team you support\n(\"v\"/\"V\" for vampires OR \"w\"/\"W\" for werewolves): ";
    cin >> usr_race;
    while ( (usr_race[0] != 'v' && usr_race[0] != 'V' && usr_race[0] != 'w' && usr_race[0] != 'W' )|| usr_race.length() != 1 ) {
        cout << "(\"v\"/\"V\" for vampires OR \"w\"/\"W\" for werewolves): ";
        cin >> usr_race;
    }
    return usr_race[0];
}

void dialogue::closing_message() {  // ending message
    system("cls");
    //---------------first line----------------
    cout << char(201);
    for (int i = 0 ; i < 34 ; i++)
        cout << char(205);
    cout << char(187) << endl;
    //---------------middle line---------------
    cout << char(186) << "      THANKS FOR PLAYING WnV!     " << char(186) << endl;
    cout << char(186) << "              made by             " << char(186) << endl;
    cout << char(186) << "      sdi2100046 & sdi2100078     " << char(186) << endl;
    //---------------last line----------------- 
    cout << char(200);
    for (int i = 0 ; i < 34 ; i++)
        cout << char(205);
    cout << char(188) << endl << endl; 

}