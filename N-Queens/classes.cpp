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
    if(!promising(currLen)){
        return;
    }
    else if(currLen == queenPos.size()){
        solFound();
    }
    else{
        for(unsigned i = currLen; i < queenPos.size(); i++){
            std::swap(queenPos[currLen], queenPos[i]);
            genPerms(currLen + 1);
            std::swap(queenPos[currLen], queenPos[i]);
        }
    }
}

bool N_Queens::promising(short currLen){
    
    for(set<short> sol: currSols){
        short curr_pos = 0;
        auto it = sol.find(queenPos[curr_pos++]);
        ++it;
        while(it != sol.end() && curr_pos != currLen && *it == queenPos[curr_pos]){
            ++it;
            ++curr_pos;
        }
        if(++curr_pos == currLen) return true;
    }
    
    for(short i = 0; i < currLen; i++){
        for(short j = i + 1; j < currLen; j++){
            if(queenPos[i] - queenPos[j] == i - j) return false;
        }
    }
    
    return true;
}

void N_Queens::solFound(){
    set<short> temp;
    reflectX(temp);
    currSols.insert(temp);
    reflectY(temp);
    currSols.insert(temp);
}

//Calculate cordinates after relfection over the x-axis
void N_Queens::reflectX(set<short> & temp){
    set<short> holder;
    unsigned size = (unsigned)queenPos.size();
    
    for(unsigned i = 0; i < size; i++){
        holder.insert(-queenPos[i] + size + 1);
    }
    
    swap(temp, holder);
}

//Calculate cordinates after relfection over the y-axis
void N_Queens::reflectY(set<short> & temp){
    set<short> holder(queenPos.rend(), queenPos.rbegin());
    swap(holder,temp);
}

//Calculate cordinates after relfection over the line y = x
void N_Queens::reflectYX(set<short> & temp){
    
    vector<short> holder;
    holder.resize(queenPos.size());
    
    for(unsigned i = 0; i < queenPos.size(); i++){
        holder[queenPos[i] - 1] = i;
    }
    
    temp = set<short>(temp.begin(), temp.end());
}

//Calculate cordinates after relfection over the line y = -x
void N_Queens::reflectNegYX(set<short> & temp){
    
    unsigned size = (unsigned)queenPos.size();
    vector<short> holder;
    holder.resize(queenPos.size());
    
    for(unsigned i = 0; i < queenPos.size(); i++){
        holder[-queenPos[i] + size + 1] = -i + size + 1;
    }
    
    temp = set<short>(temp.begin(), temp.end());
}



void N_Queens::printSol(){
    
    for(set<short> sol: currSols){
        for(short i: sol){
            cout << "|";
            for(short j = 0; j < i; j++)
                cout << "-|";
            cout << "Q|";
            for(short j = i+1; j <= sol.size(); j++)
                cout << "-|";
            cout << endl;
        }
    }
}
