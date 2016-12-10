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
    vector<Card*> userSlot; userSlot.push_back(user1.handAt(0)); userSlot.push_back(user1.handAt(1));
    vector<Card*> cpu1Slot; cpu1Slot.push_back(cpu1.handAt(0)); cpu1Slot.push_back(cpu1.handAt(1));
    vector<Card*> cpu2Slot; cpu2Slot.push_back(cpu2.handAt(0)); cpu2Slot.push_back(cpu2.handAt(1));
    vector<Card*> table;
    
    user1.sortHand();
    cpu1.sortHand();
    cpu2.sortHand();
//    cout << "Users hand: " << endl;
//    user1.showHand();
//    cout << "CPU1 Hand: " << endl;
//    cpu1.showHand();
//    cout << "CPU2 Hand: " << endl;
//    cpu2.showHand(); cout << endl;    // DEBUGGING
    
    // Loops through the 4 rounds of the game
    while (rounds <= 4)
    {
        int cpu1Hand = cpu1.understandHand();
        int cpu2Hand = cpu2.understandHand();

        int userBet = 0, cpu1Bet = 0, cpu2Bet = 0;
        if(user1.getFolded() == false)
        {
            cout << "You have $" << user1.getMoney() << endl;
            cout << "The cards in your hand: "; userSlot.at(0)->displayCard(); userSlot.at(1)->displayCard();
            cout << "Enter a amount to bet or \"f\" to fold: ";
            userBet = user1.texasBet();
        }
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
        cout << "The pot has $" << pot << " in it.\n\n";
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
    if(user1.understandHand() > cpu1.understandHand() && user1.understandHand() > cpu2.understandHand())
    {
        cout << "You won!" << endl;
        user1.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfWins();
        user1.incrementTexasHoldEmNumberOfGames();
    }
    if(cpu1.understandHand() > user1.understandHand() && cpu1.understandHand() > cpu2.understandHand())
    {
        cout << "Cpu1 won!" << endl;
        cpu1.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfGames();
    }
    if(cpu2.understandHand() > user1.understandHand() && cpu2.understandHand() > cpu1.understandHand())
    {
        cout << "Cpu2 won!" << endl;
        cpu2.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfGames();
    }
    if(user1.understandHand() == cpu1.understandHand())
    {
        User winner = tieBreaker(user1, cpu1);
        winner.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfGames();
        if(winner.getName() == user1.getName())
            user1.incrementTexasHoldEmNumberOfWins();
    }
    if(user1.understandHand() == cpu2.understandHand())
    {
        User winner = tieBreaker(user1, cpu2);
        winner.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfGames();
        if(winner.getName() == user1.getName())
            user1.incrementTexasHoldEmNumberOfWins();
    }
    if(cpu1.understandHand() == cpu2.understandHand())
    {
        User winner = tieBreaker(cpu1, cpu2);
        winner.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfGames();
        if(winner.getName() == user1.getName())
            user1.incrementTexasHoldEmNumberOfWins();
    }
}

User TexasHoldEm::tieBreaker(User user1, User user2)
{
    if(user1.understandHand() == 1)
    {
        for(int i=0; i<=6; i++)
        {
            if(*user1.highCard() > *user2.highCard())
                return user1;
        }
    }
    else
        return user2;
    
    if(user1.understandHand() == 2 || user1.understandHand() == 3 || user1.understandHand() == 4 || user1.understandHand() == 7 || user1.understandHand() == 8)
    {
        int user1Best = user1.getHighValues();
        int user2Best = user2.getHighValues();
        if(user1Best == 0 && user2Best !=0)
        {
            return user1;
        }
        else if(user2Best == 0 && user1Best !=0)
        {
            return user1;
        }
        else if(user1Best > user2Best)
        {
            return user1;
        }
        else
            return user2;
        
    }
    if(user1.understandHand() == 5 || user1.understandHand() == 9)
    {
        int user1Best = user1.getHighStraight();
        int user2Best = user2.getHighStraight();
        if(user1Best == 0 && user2Best != 0)
        {
            return user1;
        }
        else if(user2Best == 0 && user1Best != 0)
        {
            return user2;
        }
        else if(user1Best > user2Best)
        {
            return user1;
        }
        else
            return user2;

    }
    else
        return user1;
}
