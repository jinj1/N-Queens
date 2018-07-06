//
//  classes.cpp
//  N-Queens
//
//  Created by Jonson Jin on 7/5/18.
//  Copyright © 2018 Jonson Jin. All rights reserved.
//

#include "classes.hpp"

N_Queens::N_Queens(short boardSize){
    queenPos.resize(boardSize);
    for(short i = 0; i < boardSize; i++){
        queenPos[i] = i + 1;
    }
}

void N_Queens::solve(){
    genPerms(0);
}

void N_Queens::genPerms(short currLen){
    if(currLen == queenPos.size()){
        for(unsigned i = 0; i < queenPos.size(); i++){
            cout << queenPos[i] << " ";
        }
        cout << endl;
    }
    else{
        for(unsigned i = currLen; i < queenPos.size(); i++){
            std::swap(queenPos[currLen], queenPos[i]);
            genPerms(currLen + 1);
            std::swap(queenPos[currLen], queenPos[i]);
        }
    }
}

void N_Queens::printSols(){
    for(vector<short> sol: currSols){
        for(short i: sol){
            for(short j = 0; j < i; j++)
                cout << "-";
            cout << "Q";
            for(short j = i+1; j < sol.size(); j++)
                cout << "-";
            cout << endl;
        }
    }
}
