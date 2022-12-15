#include "win_dialogue.hpp"

dialogue::dialogue() {}

dialogue::~dialogue() {}


void dialogue::starting_message() {
    //---------------first line----------------
    cout << char(201);
    for (int i = 0 ; i < 39 ; i++)
        cout << char(205);
    cout << char(187) << endl;
    //---------------middle line---------------
    cout << char(186) << " WELCOME TO WnV GAME BY MIKE AND TONY! " << char(186) << endl;
    //---------------last line----------------- 
    cout << char(200);
    for (int i = 0 ; i < 39 ; i++)
        cout << char(205);
    cout << char(188) << endl << endl; 
}

int dialogue::get_x() {
    int usr_x;
    cout << "Give the x of the map: ";
    cin >> usr_x;
    while (usr_x <= 0 || usr_x > 999) {
        cout << "Please enter a reasonable value for x: ";
        cin >> usr_x; 
    }
    return usr_x;
}

int dialogue::get_y() {
    int usr_y;
    cout << "Give the y of the map: ";
    cin >> usr_y;
    while (usr_y <= 0 || usr_y > 999) {
        cout << "Please enter a reasonable value for y: ";
        cin >> usr_y; 
    }
    return usr_y;
}

char dialogue::get_race() {
    char usr_race;
    cout << "Specify the team you support\n(\"v\"/\"V\" for vampires OR \"w\"/\"W\" for werewolves): ";
    cin >> usr_race;
    while (usr_race != 'v' && usr_race != 'V' && usr_race != 'w' && usr_race != 'W') {
        cout << "(\"v\"/\"V\" for vampires OR \"w\"/\"W\" for werewolves: ";
        cin >> usr_race; 
    }
    return usr_race;
}