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






