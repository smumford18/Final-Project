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
    string getSuit();
    string getValue();
    void displayCard();
    bool isFace();
    
    bool operator==(Card&); // This should compare the value of the card (doesn't need to worry about suit)
    bool operator>(Card&); // Also compares value
    bool operator<(Card&); // Useful for sorting the cards in a hand
    bool operator!=(Card&);
};

#endif /* Card_hpp */
