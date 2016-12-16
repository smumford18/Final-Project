//
//  Game.cpp
//  Final Project
//
//  Created by Steven Mumford on 12/1/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Game.hpp"
#include "User.hpp"
#include "Blackjack.hpp"
#include "TexasHoldEm.hpp"

User Game::intro()
{
    string username;
    cout << "Welcome to Cards R Us!" << endl;
    cout << "Enter your name: ";
    cin >> username;
    User user1(username);
    return user1;
}


void Game::menu(User newUser)
{
    int choice=0;
    do
    {
        cout << "Please select which game you would like to play" << endl;
        cout << "1 for BlackJack" << endl;
        cout << "2 for Texas Hold'em" << endl;
        cout << "3 to show statistics" << endl;
        cout << "4 to quit the game" << endl;
        cin >> choice;
        if ( choice == 1)
        {
            Blackjack newGame;
            newGame.play(newUser);
            cout << endl;
        }
        else if (choice == 2)
        {
            TexasHoldEm newGame;
            newGame.play(newUser);
            cout << endl;
        }
        else if (choice == 3)
        {
            newUser.ShowStats();
            cout << endl;
        }
        else if (choice != 4)
        {
            cout << "Whoops, you must have bumped the wrong key. Please try again" << endl;
        }
        newUser.saveStats();
    }while (choice != 4);
}

