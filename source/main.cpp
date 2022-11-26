#include <iostream>
#include <cstdlib>
#include <ctime>
#include "map.hpp"
using namespace std;

int main() {
    srand(time(0));
    int x, y;
    
    cout << "Give x: ";
    cin >> x;
    cout << "Give y: ";
    cin >> y;

    map m(x, y);
    cout << m;

    return 0;
}