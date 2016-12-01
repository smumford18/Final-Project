//
//  main.cpp
//  Final Project
//
//  Created by Steven Mumford on 11/15/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#include <iostream>
#include <vector>
#include "User.hpp"
#include "CPU.hpp"
#include "Card.hpp"
#include "Deck.hpp"

using namespace std;

void texasHoldEmGame(User);

int main() {
    
//     DEBUG for User class
//    User player1("Steven");
//    int bet = player1.texasBet();
//    cout << "The resulting bet is " << bet << endl;
//    cout << "The player has " << player1.getMoney() << endl;
//    cout << "The player has " << player1.getBlackJackNumberOfWins() << " number of blackjack wins." << endl;
//    player1.saveStats();
    
    //CPU cpu1;
    
    User user1("Lydia");
    texasHoldEmGame(user1);
    return 0;
    
    
}

void texasHoldEmGame(User user1)
{
    CPU cpu1(1);
    CPU cpu2(2);
    int pot = 0;
    int rounds = 1;
    while (rounds <= 3)
    {
        int userBet, cpu1Bet, cpu2Bet;
        if(userBet != -1)
        {
            userBet = user1.texasBet();
            pot += userBet;
        }
        cout << "User bet: " << userBet << endl;
        if(cpu1Bet != -1)
        {
            cpu1Bet = cpu1.texasBet(2, userBet, false);
            cout << "CPU1 bet $" << cpu1Bet << endl;
        }
        pot += cpu1Bet;
        if(cpu2Bet != -1)
        {
            cpu2Bet = cpu2.texasBet(1, userBet, false);
            cout << "CPU2 bet $" << cpu2Bet << endl;
        }
        cout << "The pot has $" << pot << " in it." << endl;
        rounds++;
    }
}



