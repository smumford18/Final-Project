//
//  Card.hpp
//  Final Project
//
//  Created by Steven Mumford on 11/16/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <string>

using namespace std;

class Card
{
private:
    string suit;
    string value;
    
public:
    Card(string, string);
    void getSuit();
    void getValue();
    //void displayCard();
};

#endif /* Card_hpp */
