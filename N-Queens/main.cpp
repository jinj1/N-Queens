//
//  main.cpp
//  N-Queens
//
//  Created by Jonson Jin on 7/4/18.
//  Copyright © 2018 Jonson Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int getN();
void genPerms(vector<int> & queenPos, int currLen);

int main(int argc, const char * argv[]) {
    int numQueens = getN();
    vector<int> queenPos;
    queenPos.resize(numQueens);
    for(int i = 0; i < numQueens; i++){
        queenPos[i] = i + 1;
    }
    genPerms(queenPos, 0);
    return 0;
}

int getN(){
    cout << "Please enter a value for n.\n";
    string input;
    cin >> input;
    try {
        int n = stoi(input);
        return n;
    } catch (invalid_argument i) {
        cout << "You entered an invalid value please try again.\n";
        return getN();
    }
}

void genPerms(vector<int> & queenPos, int currLen){
    if(currLen == queenPos.size()){
        for(unsigned i = 0; i < queenPos.size(); i++){
            cout << queenPos[i] << " ";
        }
        cout << endl;
    }
    else{
        for(unsigned i = currLen; i < queenPos.size(); i++){
            std::swap(queenPos[currLen], queenPos[i]);
            genPerms(queenPos, currLen + 1);
            std::swap(queenPos[currLen], queenPos[i]);
        }
    }
}
