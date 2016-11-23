//
//  User.cpp
//  Final Project
//
//  Created by Steven Mumford on 11/16/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#include "User.hpp"

User::User()
{
    name = "Eric";
    money = 100;
    blackJackNumberOfWins = 0;
    blackJackNumberOfGames = 0;
    texasHoldEmNumberOfWins = 0;
    texasHoldEmNumberOfGames = 0;
    hand.push_back(NULL);
    cout << "Welcome, " << name << "!" << endl;
}

User::User(string NAME)
{
    string fileName = NAME + ".txt";
    ifstream fileIO(fileName);
    if(!fileIO)
    {
        name = NAME;
        money = 100;
        blackJackNumberOfWins = 0;
        blackJackNumberOfGames = 0;
        texasHoldEmNumberOfWins = 0;
        texasHoldEmNumberOfGames = 0;
        hand.push_back(NULL);
        cout << "Welcome, " << name << "!" << endl;
    }
    else
    {
        fileIO >> name >> money >> blackJackNumberOfWins >> blackJackNumberOfGames >> texasHoldEmNumberOfWins >> texasHoldEmNumberOfGames;
        hand.push_back(NULL);
        cout << "Welcome back, " << name << "!" << endl;
    }
    fileIO.close();
}

int User::getMoney()
{
    return money;
}

int User::getBlackJackNumberOfWins()
{
    return blackJackNumberOfWins;
}

int User::getBlackJackNumberOfGames()
{
    return blackJackNumberOfGames;
}

int User::getTexasHoldEmNumberOfWins()
{
    return texasHoldEmNumberOfWins;
}

int User::getTexasHoldEmNumberOfGames()
{
    return texasHoldEmNumberOfGames;
}

void User::setMoney(int MONEY)
{
    money = MONEY;
}

void User::incrementBlackJackNumberOfWins()
{
    blackJackNumberOfWins++;
}

void User::incrementBlackJackNumberOfGames()
{
    blackJackNumberOfGames++;
}

void User::incrementTexasHoldEmNumberOfWins()
{
    texasHoldEmNumberOfWins++;
}

void User::incrementTexasHoldEmNumberOfGames()
{
    texasHoldEmNumberOfGames++;
}

void User::saveStats()
{
    string fileName = name + ".txt";
    fstream fileIO(fileName, ios::out);
    if(fileIO.fail())
    {
        cout << "ERROR";
    }
    else
    {
        fileIO << name << " " <<  money << " " << blackJackNumberOfWins << " " << blackJackNumberOfGames << " " << texasHoldEmNumberOfWins << " " << texasHoldEmNumberOfGames;
    }
    fileIO.close();
}

void User::addToHand(Card* newCard)
{
    hand.push_back(newCard);
}

int User::understandHand()
{
    // Rankings:
    // High Card 1
    // Pair 2
    // Two Pair 3
    // Three of a kind 4
    // Straight 5
    // Flush 6
    // Full house 7
    // Four of a kind 8
    // Straight flush 9
    // Royal flush 10
    
    // Finds number of same suit
    int numOfSameSuit = 0;
    for(int i=0; i<hand.size(); i++)
    {
        //string suitTest = hand.at(i)/*.getSuit()*/;
        for(int j=0; j<hand.size(); i++)
        {
            //if(hand.at(j) == suitTest)
                numOfSameSuit++;
        }
    }
    
    vector<string> testValues;
    testValues.push_back("Ace");
    testValues.push_back("King");
    testValues.push_back("Queen");
    testValues.push_back("Jack");
    testValues.push_back("10");
    int numOfMatchingValues = 0;
    
    // Finds number of 
    for(int i=0; i<testValues.size(); i++)
    {
        //string tester = testValues.at(i).getValue;
        for(int j=0; j<hand.size(); j++)
        {
            //if(hand.at(j).getValue = tester)
                //numOfMatchingValues++;
        }
    }
    
    
    if(numOfSameSuit == 5 && numOfMatchingValues == 5)
        return 10;
    if(numOfSameSuit == 5)
        return 9;
    
    return 1;
}

int User::blackJackBet()
{
    bool tooMuch = true;
    int bet = 0;
    cout << "You have $" << money << endl;
    cout << "Enter a amount to bet or \"f\" to fold: ";
    while (tooMuch == true)
    {
        cin >> bet;
        string test = to_string(bet);
        if(test == "f" || test == "F")
        {
            folded = true;
            tooMuch = false;
        }
        else
        {
            if(bet > money)
            {
                cout << "You don't have that much money!\n Please enter another amount: ";
            }
            else
                tooMuch = false;
        }
    }

    money -= bet;
    folded = false;
    return bet;
}

int User::texasBet()
{
    bool tooMuch = true;
    int bet = 0;
    cout << "You have $" << money << endl;
    cout << "Enter a amount to bet or \"f\" to fold: ";
    while(tooMuch == true)
    {
        cin >> bet;
        string test = to_string(bet);
        if(test == "f" || test == "F")
        {
            folded = true;
            tooMuch = false;
        }
        else
        {
            if(bet > money)
            {
                cout << "You don't have that much money!\n Please enter another amount: ";
            }
            else
                tooMuch = false;
        }
    }
    money -= bet;
    folded = false;
    return bet;
}

void User::fold()
{
    folded = true;
}






