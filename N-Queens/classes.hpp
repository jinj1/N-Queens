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
    vector<set<short> > currSols;
    
    void genPerms(short currLen);
    void printSol();
    
};

#endif /* classes_hpp */
