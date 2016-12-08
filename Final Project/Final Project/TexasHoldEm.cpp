//
//  TexasHoldEm.cpp
//  Final Project
//
//  Created by Steven Mumford on 12/1/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#include "TexasHoldEm.hpp"

//TexasHoldEm::TexasHoldEm()
//{
//    
//}

void TexasHoldEm::play(User user1)
{
    CPU cpu1(1);
    CPU cpu2(2);
    int pot = 0;
    int rounds = 1;
    user1.setFolded(false);
    Deck deck(1);
    deck.shuffleDeck();
    for(int i=0; i<6; i+=3)
    {
        user1.addToHand((deck.at(i)));
        cpu1.addToHand(deck.at(i+1));
        cpu2.addToHand(deck.at(i+2));
    }
    user1.sortHand();
    cpu1.sortHand();
    cpu2.sortHand();
    cout << "Users hand: " << endl;
    user1.showHand();
    cout << "CPU1 Hand: " << endl;
    cpu1.showHand();
    cout << "CPU2 Hand: " << endl;
    cpu2.showHand(); cout << endl;
    
    cout << user1.understandHand() << endl;
    
    // Loops through the 3 rounds of the game
    while (rounds <= 3)
    {
        int userBet = 0, cpu1Bet = 0, cpu2Bet = 0;
        cout << "You have $" << user1.getMoney() << endl;
        cout << "Enter a amount to bet or \"f\" to fold: ";
        userBet = user1.texasBet();
        //cout << "User bet: " << userBet << endl;
        // Makes sure cpu hasn't folded
        pot += userBet;
        if(cpu1Bet != -1)
        {
            cpu1Bet = cpu1.texasBet(2, userBet, false);
            cout << "CPU1 bet $" << cpu1Bet << endl;
        }
        pot += cpu1Bet;
        if(cpu2Bet != -1)
        {
            cpu2Bet = cpu2.texasBet(1, cpu1Bet, false);
            cout << "CPU2 bet $" << cpu2Bet << endl;
        }
        pot += cpu2Bet;
        cout << "The pot has $" << pot << " in it." << endl;
        rounds++;
    }
}
