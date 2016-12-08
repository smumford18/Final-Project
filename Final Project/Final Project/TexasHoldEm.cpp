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
    
    int userHand = user1.understandHand();
    int cpu1Hand = cpu1.understandHand();
    int cpu2Hand = cpu2.understandHand();
    
    // Loops through the 3 rounds of the game
    while (rounds <= 4)
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
            cpu1Bet = cpu1.texasBet(cpu1Hand, userBet, false);
            cout << "CPU1 bet $" << cpu1Bet << endl;
        }
        pot += cpu1Bet;
        if(cpu2Bet != -1)
        {
            cpu2Bet = cpu2.texasBet(cpu2Hand, cpu1Bet, false);
            cout << "CPU2 bet $" << cpu2Bet << endl;
        }
        pot += cpu2Bet;
        cout << "The pot has $" << pot << " in it." << endl;
        if(rounds == 1)
        {
            cout << "The flop: " << endl;
            for(int i=6; i<=10; i+=2)
            {
                deck.at(i)->displayCard();
                user1.addToHand(deck.at(i)); user1.sortHand();
                cpu1.addToHand(deck.at(i)); cpu1.sortHand();
                cpu2.addToHand(deck.at(i)); cpu2.sortHand();
            }
        }
        if(rounds == 2)
        {
            cout << "The turn: " << endl;
            deck.at(12)->displayCard();
            user1.addToHand(deck.at(12)); user1.sortHand();
            cpu1.addToHand(deck.at(12)); cpu1.sortHand();
            cpu2.addToHand(deck.at(12)); cpu2.sortHand();
        }
        if(rounds == 3)
        {
            cout << "The river: " << endl;
            deck.at(14)->displayCard();
            user1.addToHand(deck.at(14)); user1.sortHand();
            cpu1.addToHand(deck.at(14)); cpu1.sortHand();
            cpu2.addToHand(deck.at(14)); cpu2.sortHand();
        }
        if(rounds == 4)
        {
            cout << "Users hand: " << user1.understandHand() << endl;
            user1.showHand();
            cout << "CPU1 Hand: " << cpu1.understandHand() << endl;
            cpu1.showHand();
            cout << "CPU2 Hand: " << cpu2.understandHand() <<endl;
            cpu2.showHand(); cout << endl;
        }
        rounds++;
    }
    if(user1.understandHand() > cpu1.understandHand() && user1.understandHand() > cpu1.understandHand())
    {
        user1.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfWins();
        user1.incrementTexasHoldEmNumberOfGames();
    }
    if(cpu1.understandHand() > user1.understandHand() && cpu1.understandHand() > cpu2.understandHand())
    {
        cpu1.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfGames();
    }
    if(cpu2.understandHand() > user1.understandHand() && cpu2.understandHand() > cpu1.understandHand())
    {
        cpu2.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfGames();
    }
//    if(user1.understandHand() == cpu1.understandHand())
//    {
//        if(user1.)
//    } needs to be able to work if user and cpu has same value of hand
}
