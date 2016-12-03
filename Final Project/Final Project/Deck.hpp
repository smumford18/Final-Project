//
//  Deck.hpp
//  Final Project
//
//  Created by Steven Mumford on 11/16/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <vector>
#include <iostream>
#include "Card.hpp"

class Deck
{
private:
    vector<Card*> deck;
    
public:
    Deck(int);
    ~Deck();
    Card* at(int);
    void shuffleDeck();
    
};

#endif /* Deck_hpp */
