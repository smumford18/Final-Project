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
    virtual void cardOutput(int);
    virtual int hit(int&);
    virtual bool askHit(int total);
    virtual bool askEnd();
    virtual int isAce(int);
    virtual bool isBust(int userSum);
    virtual int getCard();
    virtual int aceAddition(int total, int aces);
    virtual int aceReduction(int total, int aces, bool& aceReduced);
    virtual bool userPlay(int& total, int aces, bool& aceReduced, bool bust, bool hitAsked);
    virtual void dealerPlay(bool bust, bool dealerFirst, int dealerTotal, int dealerAces, bool dealerBust, bool dealerAceReduced, int& total);
    
    
};

#endif /* Blackjack_hpp */
