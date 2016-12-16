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
    //cout << "Welcome, " << name << "!" << endl;
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

string User::getName()
{
    return name;
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

Card* User::highCard()
{
    return hand.at(0);
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

Card* User::handAt(int index)
{
    return hand.at(index);
}

int User::getHighValues()
{
    int values[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // greatest to least
    int suits[4] = {0, 0, 0, 0}; // Clubs, diamonds, hearts, spades
    
    for(int i=0; i<hand.size(); i++)
    {
        Card* c = hand.at(i);
        values[c->getValueAsInt()]++;
        suits[c->getSuitAsInt()]++;
    }
    int max = values[0];
    for(int i=0; i<13; i++)
    {
        if(values[i+1] > max)
        {
            max = values[i+1];
        }
    }
    for(int i=0; i<14; i++)
    {
        if(values[i] == max)
        {
            return i;
        }
    }
    return -1; // Error
}

int User::getHighStraight()
{
    int values[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // greatest to least
    int suits[4] = {0, 0, 0, 0}; // Clubs, diamonds, hearts, spades
    
    for(int i=0; i<hand.size(); i++)
    {
        Card* c = hand.at(i);
        values[c->getValueAsInt()]++;
        suits[c->getSuitAsInt()]++;
    }
    
    for(int i=2; i<=8; i++)
    {
        if(values[i] >= 1 && values[i+1] >= 1 && values[i+2] >= 1 && values[i+3] >= 1 && values[i+4] >= 1)
        {
            return i;
        }
    }
    return -1; // Error
}

int User::understandHand()
{
    // Rankings:
    // High Card 1
    // Pair 2
    // Two Pairs 3
    // Three of a kind 4
    // Straight 5
    // Flush 6
    // Full house 7
    // Four of a kind 8
    // Straight flush 9
    // Royal flush 10
    
    int values[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // greatest to least
    int suits[4] = {0, 0, 0, 0}; // Clubs, diamonds, hearts, spades
    
    for(int i=0; i<hand.size(); i++)
    {
        Card* c = hand.at(i);
        values[c->getValueAsInt()]++;
        suits[c->getSuitAsInt()]++;
    }
    
    bool flush = false;
    for(int i=0; i<4; i++)
    {
        if(suits[i] >= 5)
        {
            flush = true;
        }
    }
    bool royalStraight = values[1] >= 1 && values[10] >= 1 && values[11] >= 1 && values[12] >= 1 && values[13] >= 1;
    
    bool royalFlush = flush && royalStraight;
    
    bool straight = royalStraight;
    if(!straight)
    {
        for(int i=2; i<=8; i++)
        {
            if(values[i] >= 1 && values[i+1] >= 1 && values[i+2] >= 1 && values[i+3] >= 1 && values[i+4] >= 1)
            {
                straight = true;
            }
        }
    }
    bool straightFlush = flush && straight;
    
    bool fourOfAKind = false;
    for(int i=0; i<=13; i++)
    {
        if(values[i] == 4)
            fourOfAKind = true;
    }
    
    bool fullHouse = false;
    for(int i=0; i<=13; i++)
    {
        if(values[i] == 3)
        {
            for(int j=0; j<=13; j++)
            {
                if(values[j] == 2 && j != i)
                {
                    fullHouse = true;
                }
            }
        }
    }
    
    bool threeOfAKind = false;
    for(int i=0; i<=13; i++)
    {
        if(values[i] == 3)
            threeOfAKind = true;
    }
    
    bool twoPair = false;
    for(int i=0; i<=13; i++)
    {
        if(values[i] == 2)
        {
            for(int j=0; j<=13; j++)
            {
                if(values[j] == 2 && j != i)
                {
                    twoPair = true;
                }
            }
        }
    }

    bool pair = false;
    for(int i=0; i<=13; i++)
    {
        if(values[i] == 2)
            pair = true;
    }
    
    if(royalFlush == true)
        return 10;
    else if(straight == true && flush == true)
        return 9;
    else if(fourOfAKind == true)
        return 8;
    else if(fullHouse == true)
        return 7;
    else if(flush == true)
        return 6;
    else if(straight == true)
        return 5;
    else if(threeOfAKind == true)
        return 4;
    else if(twoPair == true)
        return 3;
    else if(pair == true)
        return 2;
    else
        return 1;
    
    
    return -100; // Error
}

void User::clearHand()
{
    for(int i=0; i<hand.size(); i++)
    {
        hand.clear();
    }
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






