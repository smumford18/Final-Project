//
//  TexasHoldEm.hpp
//  Final Project
//
//  Created by Steven Mumford on 12/1/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#ifndef TexasHoldEm_hpp
#define TexasHoldEm_hpp

#include <stdio.h>
#include "Game.hpp"
#include "User.hpp"
#include "CPU.hpp"
#include "Deck.hpp"
#include "Card.hpp"

using namespace std;

class TexasHoldEm : public Game
{
public:
    virtual void play(User*);
    virtual User tieBreaker(User, User);
};
#endif /* TexasHoldEm_hpp */
