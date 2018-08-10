//
//  classes.hpp
//  N-Queens
//
//  Created by Jonson Jin on 7/5/18.
//  Copyright © 2018 Jonson Jin. All rights reserved.
//

#ifndef classes_hpp
#define classes_hpp

#include <stdio.h>
#include <vector>
#include <set>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class N_Queens{
public:
    N_Queens(short boardSize);
    void solve();
    
private:
    
    vector<short> queenPos;
    unordered_set<set<short> > currSols;
    void genPerms(short currLen);
    bool promising(short currLen);
    void solFound();
    void reflectX(set<short> & temp);
    void reflectY(set<short> & temp);
    void reflectYX(set<short> & temp);
    void reflectNegYX(set<short> & temp);
    void printSol();
    
};

#endif /* classes_hpp */
