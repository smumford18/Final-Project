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
    CPU cpu1;
    CPU cpu2;
    int choice;
    Deck deck(1);
    do
    {
        int pot = 0;
        int rounds = 1;
        user1.setFolded(false);
        deck.shuffleDeck();
        int i=0;
        for(i=0; i<6; i+=3)
        {
            user1.addToHand((deck.at(i)));
            cpu1.addToHand(deck.at(i+1));
            cpu2.addToHand(deck.at(i+2));
        }
    
        user1.sortHand();
        cpu1.sortHand();
        cpu2.sortHand();
    
    vector<Card*> userSlot; userSlot.push_back(user1.handAt(0)); userSlot.push_back(user1.handAt(1));
    vector<Card*> cpu1Slot; cpu1Slot.push_back(cpu1.handAt(0)); cpu1Slot.push_back(cpu1.handAt(1));
    vector<Card*> cpu2Slot; cpu2Slot.push_back(cpu2.handAt(0)); cpu2Slot.push_back(cpu2.handAt(1));
    vector<Card*> table;
    
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
            for(int q=6; q<=10; q+=2)
            {
                deck.at(q)->displayCard();
                user1.addToHand(deck.at(q)); user1.sortHand();
                cpu1.addToHand(deck.at(q)); cpu1.sortHand();
                cpu2.addToHand(deck.at(q)); cpu2.sortHand();
                table.push_back(deck.at(q));
            }
        }
        if(rounds == 2)
        {
            cout << "The turn: " << endl;
            deck.at(12)->displayCard();
            user1.addToHand(deck.at(12)); user1.sortHand();
            cpu1.addToHand(deck.at(12)); cpu1.sortHand();
            cpu2.addToHand(deck.at(12)); cpu2.sortHand();
            table.push_back(deck.at(12));
        }
        if(rounds == 3)
        {
            cout << "The river: " << endl;
            deck.at(14)->displayCard();
            user1.addToHand(deck.at(14)); user1.sortHand();
            cpu1.addToHand(deck.at(14)); cpu1.sortHand();
            cpu2.addToHand(deck.at(14)); cpu2.sortHand();
            table.push_back(deck.at(14));
        }
        if(rounds == 4)
        {
            cout << "Cards on the table: " << endl;
            for(int i=0; i<table.size(); i++)
            {
                table.at(i)->displayCard();
            }
            cout << "Users hand: " << user1.understandHand() << endl;
            for(int i=0; i<userSlot.size(); i++)
            {
                userSlot.at(i)->displayCard();
            }
            cout << "CPU1 Hand: " << cpu1.understandHand() << endl;
            for(int i=0; i<cpu1Slot.size(); i++)
            {
                cpu1Slot.at(i)->displayCard();
            }
            cout << "CPU2 Hand: " << cpu2.understandHand() <<endl;
            for(int i=0; i<cpu2Slot.size(); i++)
            {
                cpu2Slot.at(i)->displayCard();
            }
            cout << endl;
        }
        rounds++;
    }
    if(user1.understandHand() > cpu1.understandHand() && user1.understandHand() > cpu2.understandHand())
    {
        cout << "You won!" << endl;
        user1.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfWins();
        user1.incrementTexasHoldEmNumberOfGames();
        cout << "You now have $" << user1.getMoney() << "!\n";
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
    if(user1.understandHand() == cpu1.understandHand() && user1.understandHand() > cpu2.understandHand())
    {
        User winner = tieBreaker(user1, cpu1);
        winner.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfGames();
        if(winner.getName() == user1.getName())
        {
            user1.incrementTexasHoldEmNumberOfWins();
            cout << "You won!" << endl;
            cout << "You now have $" << user1.getMoney() << "!\n";
        }
        else if(winner.getName() == cpu1.getName())
        {
            cout << "Cpu1 won!" << endl;
        }
        else if(winner.getName() == "Error")
        {
            cout << "Sorry, an error occured." << endl;
        }
    }
    if(user1.understandHand() == cpu2.understandHand() && user1.understandHand() > cpu1.understandHand())
    {
        User winner = tieBreaker(user1, cpu2);
        winner.addToMoney(pot);
        user1.incrementTexasHoldEmNumberOfGames();
        if(winner.getName() == user1.getName())
        {
            user1.incrementTexasHoldEmNumberOfWins();
            cout << "You won!" << endl;
            cout << "You now have $" << user1.getMoney() << "!\n";
        }
        else if(winner.getName() == cpu2.getName())
        {
            cout << "Cpu2 won!" << endl;
        }
        else if(winner.getName() == "Error")
        {
            cout << "Sorry, an error occured." << endl;
        }
    }
        if(cpu1.understandHand() == cpu2.understandHand()&& cpu1.understandHand() > user1.understandHand())
        {
            User winner = tieBreaker(cpu1, cpu2);
            winner.addToMoney(pot);
            user1.incrementTexasHoldEmNumberOfGames();
            if(winner.getName() == cpu1.getName())
            {
                cout << "Cpu1 won!" << endl;
            }
            else if(winner.getName() == cpu2.getName())
            {
                cout << "Cpu2 won!" << endl;
            }
            else if(winner.getName() == "Error")
            {
                cout << "Sorry, an error occured." << endl;
            }
        }
        user1.clearHand();
        cpu1.clearHand();
        cpu2.clearHand();
        cout << "Enter 0 to return to the menu or any other number to play again: ";
        cin >> choice;
    }   while(choice != 0);
}

User TexasHoldEm::tieBreaker(User user1, User user2)
{
    User error("Error");
    if(user1.understandHand() == 1)
    {
        for(int i=0; i<=6; i++)
        {
            if(*user1.highCard() > *user2.highCard())
                return user1;
        }
    }
    else
        return error;
    
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
            return error;
        
    }
    if(user1.understandHand() == 5 || user1.understandHand() == 9)
    {
        User error;
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
            return error;

    }
    else
        return error;
}
