//
//  Game.hpp
//  Final Project
//
//  Created by Steven Mumford on 12/1/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "User.hpp"

using namespace std;

class Game
{
private:
    string name;
    vector<string> games;
    
public:
    void menu(User*);
    User* intro();
    
};

#endif /* Game_hpp */
