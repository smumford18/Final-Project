//
//  User.hpp
//  Final Project
//
//  Created by Steven Mumford on 11/16/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <string>

using namespace std;

class User
{
private:
    
    
public:
    User(); // Will create user from file IO
    User(string); // Will create new user
    void getName();
    void getMoney();
    void getBlackJackNumberOfWins();
    void getBlackJackNumberOfGames();
    void getTexasHoldEmNumberOfWins();
    void getTexasHoldEmNumberOfGames();
    
};

#endif /* User_hpp */
