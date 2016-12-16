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
#include "Game.hpp"
#include "Blackjack.hpp"
#include "TexasHoldEm.hpp"

using namespace std;

//void texasHoldEmGame(User);

int main() {
    
    Game newGame;
    User *player = newGame.intro();
    newGame.menu(player);
    
    return 0;
}






//void texasHoldEmGame(User user1)
//{
//    CPU cpu1(1);
//    CPU cpu2(2);
//    int pot = 0;
//    int rounds = 1;
//    bool potRight;
//    user1.setFolded(false);
//    Deck deck(1);
//    deck.shuffleDeck();
//    for(int i=0; i<6; i+=3)
//    {
//        user1.addToHand((deck.at(i)));
//        cpu1.addToHand(deck.at(i+1));
//        cpu2.addToHand(deck.at(i+2));
//    }
//    cout << "Users hand: " << endl;
//    user1.showHand();
//    cout << "CPU1 Hand: " << endl;
//    cpu1.showHand();
//    cout << "CPU2 Hand: " << endl;
//    cpu2.showHand(); cout << endl;
//    
//    // Loops through the 3 rounds of the game
//    while (rounds <= 3)
//    {
//        int userBet = 0, cpu1Bet = 0, cpu2Bet = 0;
//        potRight = false;
//        // Loops while pot isn't right
//        while(potRight == false)
//        {
//            int raised;
//            // Checks to make sure user hasn't folded
//            if(user1.getFolded() == false)
//            {
//                cout << "You have $" << user1.getMoney() << endl;
//                cout << "Enter a amount to bet or \"f\" to fold: ";
//                userBet = user1.texasBet();
//            }
//            pot += userBet;
//            raised = userBet;
//            //cout << "User bet: " << userBet << endl;
//            // Makes sure cpu hasn't folded
//            if(cpu1Bet != -1)
//            {
//                cpu1Bet = cpu1.texasBet(2, userBet, false);
//                cout << "CPU1 bet $" << cpu1Bet << endl;
//            }
//            pot += cpu1Bet;
//            // Makes sure cpu hasn't folded
//            if(cpu2Bet != -1)
//            {
//                cpu2Bet = cpu2.texasBet(1, cpu1Bet, false);
//                cout << "CPU2 bet $" << cpu2Bet << endl;
//            }
//            pot += cpu2Bet;
//            int due = cpu2Bet - raised;
//            // checks to see if CPU made pot right
//            if(due == 0)
//                potRight = true;
//            // If pot isn't right, gives user chance to match, raise, or fold
//            else
//            {
//                // Makes sure user hasn't folded
//                if(user1.getFolded() == false)
//                {
//                    cout << "The bet has been raised, bet " << due << " to match or \"f\" to fold: ";
//                    int raisedBet = user1.texasBet();
//                    pot += raisedBet;
//                    // Returns true if user's bet made the pot right
//                    if(raisedBet == due)
//                    {
//                        potRight = true;
//                    }
//                    // If pot still isn't right, lets CPU's bet again
//                    else
//                    {
//                        int cpu1RaisedBet = cpu1.texasBet(2, raisedBet, false);
//                        cpu2.texasBet(1, cpu1RaisedBet, false);
//                    }
//                }
//            }
//            cout << "The pot has $" << pot << " in it." << endl;
//        }
//        rounds++;
//    }
//}
//
//
//
