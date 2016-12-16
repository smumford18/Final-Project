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
#include <vector>
#include <fstream>
#include <iostream>
#include "Card.hpp"

using namespace std;

class User
{
private:
    string name;
    int money;
    int blackJackNumberOfWins;
    int blackJackNumberOfGames;
    int texasHoldEmNumberOfWins;
    int texasHoldEmNumberOfGames;
    bool folded;
    vector<Card*> hand;
    
public:
    User(); // For debug purposes
    User(string); // Will create new user
    
    string getName();
    int getMoney();
    int getBlackJackNumberOfWins();
    int getBlackJackNumberOfGames();
    int getTexasHoldEmNumberOfWins();
    int getTexasHoldEmNumberOfGames();
    bool getFolded();
    
    void setMoney(int);
    void addToMoney(int); //????? good for added to players bank after they win
    void setFolded(bool);
    
    void incrementBlackJackNumberOfWins();
    void incrementBlackJackNumberOfGames();
    void incrementTexasHoldEmNumberOfWins();
    void incrementTexasHoldEmNumberOfGames();
    
    void saveStats();
    
    void sortHand();
    Card* handAt(int);
    void showHand();
    Card* highCard();
    void addToHand(Card*);
    int getHighValues();
    int getHighStraight();
    int understandHand();
    void clearHand();
    
    int blackJackBet(); //
    int texasBet();     // SAME? Only need one bet function?
    
    void fold();
    
};

#endif /* User_hpp */
