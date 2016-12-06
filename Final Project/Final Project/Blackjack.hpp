//
//  Blackjack.hpp
//  Final Project
//
//  Created by Steven Mumford on 12/1/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#ifndef Blackjack_hpp
#define Blackjack_hpp

#include <stdio.h>
#include "Game.hpp"

#include "User.hpp"
#include "CPU.hpp"
#include "Deck.hpp"
#include "Card.hpp"

using namespace std;

class Blackjack : public Game
{
    
public:
    virtual void play(User);
    
};

#endif /* Blackjack_hpp */
