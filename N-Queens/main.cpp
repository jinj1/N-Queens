//
//  main.cpp
//  N-Queens
//
//  Created by Jonson Jin on 7/4/18.
//  Copyright © 2018 Jonson Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include "classes.hpp"


using namespace std;

short getBoardSize();

int main(int argc, const char * argv[]) {
    int boardSize = getBoardSize();
    N_Queens nQueens(boardSize);
    return 0;
}

short getBoardSize(){
    cout << "Please enter the board size.\n";
    string input;
    cin >> input;
    try {
        short n = (short)stoi(input);
        return n;
    } catch (invalid_argument i) {
        cout << "You entered an invalid value please try again.\n";
        return getBoardSize();
    }
}
