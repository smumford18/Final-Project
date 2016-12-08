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

bool User::getFolded()
{
    return folded;
}

void User::setMoney(int MONEY)
{
    money = MONEY;
}

void User::addToMoney(int pot)
{
    money += pot;
}

void User::setFolded(bool FOLDED)
{
    folded = FOLDED;
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

void User::showHand()
{
    for(int i=0; i<hand.size(); i++)
    {
        hand.at(i)->displayCard();
    }
}

void User::addToHand(Card* newCard)
{
    hand.push_back(newCard);
}

void User::sortHand()
{
//    bool isSorted(const T list[], int size)
//    {
//        bool sorted = true;
//        for(int i=0; i < size; i++)
//        {
//            if(list[i] > list[i+1])
//            {
//                sorted = false;
//                break;
//            }
//        }
//        
//        return sorted;
//    }
    
    double size = hand.size();
    for(int j=0; j < size; j++)
    {
        for(int i=0; i < size-1; i++)
        {
            if(*hand.at(i+1) > *hand.at(i))
            {
                Card *temp = hand.at(i);
                hand.at(i) = hand.at(i+1);
                hand.at(i+1) = temp;
            }
        }
    }
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
    
    vector<string> testValues;
    testValues.push_back("Ace");
    testValues.push_back("King");
    testValues.push_back("Queen");
    testValues.push_back("Jack");
    testValues.push_back("10");
    testValues.push_back("9");
    testValues.push_back("8");
    testValues.push_back("7");
    testValues.push_back("6");
    testValues.push_back("5");
    testValues.push_back("4");
    testValues.push_back("3");
    testValues.push_back("2");
    
    
    // Finds number of same suit
    int numOfSameSuit = 0;
    for(int i=0; i<hand.size(); i++)
    {
        string suitTest = hand.at(i)->getSuit();
        for(int j=0; j<hand.size(); j++)
        {
            if(hand.at(j)->getSuit() == suitTest)
                numOfSameSuit++;
        }
    }
    
    int numOfMatchingValues = 0;
    
    // Finds number of same values
    for(int i=0; i<hand.size(); i++)
    {
        string tester = hand.at(i)->getValue();
        for(int j=0; j<hand.size(); j++)
        {
            if(*(hand.at(i)) != *(hand.at(j)))
            {
                if(hand.at(j)->getValue() == tester)
                    numOfMatchingValues++;
            }
        }
    }
    
    
    if(numOfSameSuit == 5 && numOfMatchingValues == 5)
        return 10;
    else if(numOfSameSuit == 5 && numOfMatchingValues == 5)
        return 9;
    else if(numOfMatchingValues == 4)
        return 8;
    else if(numOfSameSuit == 5)
        return 6;
    else if(numOfMatchingValues == 3)
        return 4;
    else if(numOfMatchingValues == 2)
        return 2;
    else if(numOfMatchingValues == 1)
        return -1;
    else if(numOfMatchingValues == 0)
        return 1;
    
    
    return -100;
}

int User::blackJackBet()
{
    bool tooMuch = true;
    int bet = 0;
    cout << "You have $" << money << endl;
    cout << "Enter an amount to bet or \"f\" to fold: ";
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
    string input;
    //cout << "You have $" << money << endl;
    //cout << "Enter a amount to bet or \"f\" to fold: ";
    while(tooMuch == true)
    {
        cin >> input;
        int bet;
        if(input == "f" || input == "F")
        {
            folded = true;
            tooMuch = false;
            bet = 0;
            return bet;
        }
//        IMPLEMENT CHECK LATER?
//        else if(test == "c" || test == "C")
//        {
//            bet = 0;
//            return bet;
//        }
        else
        {
            bet = stoi(input);
            if(bet > money)
            {
                cout << "You don't have that much money!\n Please enter another amount: ";
            }
            else
            {
                tooMuch = false;
                money -= bet;
                folded = false;
                return bet;
            }
        }
    }
    return -1;
}

void User::fold()
{
    folded = true;
}






