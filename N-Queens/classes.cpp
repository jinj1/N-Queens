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
    printSol();
}

//Generates all possible permutations
void N_Queens::genPerms(short currLen){
    //Checks if the current solution is promising
    if(!promising(currLen)){
        return;
    }
    //Adds the found solution
    else if(currLen == queenPos.size()){
        solFound();
    }
    //Generates the next permutation
    else{
        for(unsigned i = currLen; i < queenPos.size(); i++){
            std::swap(queenPos[currLen], queenPos[i]);
            genPerms(currLen + 1);
            std::swap(queenPos[currLen], queenPos[i]);
        }
    }
}

//Checks if the current solution is valid
bool N_Queens::promising(short currLen){
    
    //Checks if the curr solution is contained in any of the other solutions
    for(vector<short> sol: currSols){
        short curr_pos = 0;
        auto it = find(sol.begin(), sol.end(), queenPos[curr_pos++]);
        ++it;
        while(it != sol.end() && curr_pos != currLen && *it == queenPos[curr_pos]){
            ++it;
            ++curr_pos;
        }
        if(curr_pos == currLen) return true;
    }
    
    //Loops to check that all positions are valid
    for(short i = 0; i < currLen - 1; i++){
        for(short j = i + 1; j < currLen; j++){
            if(queenPos[i] - queenPos[j] == i - j || queenPos[j] - queenPos[i] == i - j) return false;
        }
    }
    
    return true;
}

//Runs through all possible symmetries of the found solution
void N_Queens::solFound(){
    
    vector<short> temp(queenPos.begin(), queenPos.end());
    currSols.insert(temp);

    reflectX(temp);
    currSols.insert(temp);

    reflectY(temp);
    currSols.insert(temp);
    
    reflectYX(temp);
    currSols.insert(temp);
    
    reflectNegYX(temp);
    currSols.insert(temp);
    
}

//Calculate cordinates after relfection over the x-axis
void N_Queens::reflectX(vector<short> & temp){
    
    vector<short> holder;
    unsigned size = (unsigned)queenPos.size();
    
    for(unsigned i = 0; i < size; i++){
        holder.push_back(-queenPos[i] + size + 1);
    }
    
    swap(temp, holder);
}

//Calculate cordinates after relfection over the y-axis
void N_Queens::reflectY(vector<short> & temp){
    
    vector<short> holder(queenPos.rbegin(), queenPos.rend());
    swap(holder,temp);
}

//Calculate cordinates after relfection over the line y = x
void N_Queens::reflectYX(vector<short> & temp){
    
    vector<short> holder;
    holder.resize(queenPos.size());
    
    for(unsigned i = 0; i < queenPos.size(); i++){
        holder[queenPos[i] - 1] = i + 1;
    }
    
    swap(holder,temp);
}

//Calculate cordinates after relfection over the line y = -x
void N_Queens::reflectNegYX(vector<short> & temp){
    
    unsigned size = (unsigned)queenPos.size();
    vector<short> holder;
    holder.resize(queenPos.size());
    
    for(unsigned i = 0; i < size; i++){
        holder[queenPos[i]- 1] = i + 1;
    }
    
    swap(holder,temp);
}


//Prints out all the found solutions
void N_Queens::printSol(){
    
    if(!currSols.size()){
        cout << "No solution was found" << endl;
        return;
    }
    
    cout << "A total of " << currSols.size() << " solutions were found" << endl;
    cout << "Would you like to print them (y/n)"<< endl;
    
    char print_Sols;
    cin >> print_Sols;
    cout << endl;
    
    if(print_Sols == 'y'){
        for(vector<short> sol: currSols){
            for(short i: sol){
                cout << "|";
                
                for(short j = 1; j < i; j++)
                    cout << "-|";
                cout << "Q|";
                
                for(short j = i+1; j <= sol.size(); j++)
                    cout << "-|";
                cout << endl;
            }
            cout << endl;
        }
    }
}
