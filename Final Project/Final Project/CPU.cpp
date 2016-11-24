//
//  CPU.cpp
//  Final Project
//
//  Created by Steven Mumford on 11/16/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#include "CPU.hpp"

CPU::CPU()
{
    name = "CPU1";
    money = 100;
}

CPU::CPU(int num)
{
    string id = to_string(num);
    name = "CPU" + id;
    money = 100;
}

int CPU::blackJackBet()
{
    int bet = 0;
    srand((unsigned int)time(NULL));
    int temp = rand() % 10;
    bet = temp;
    return bet;
}

int CPU::texasBet(int rank)
{
    int bet = 0;
    srand((unsigned int)time(NULL));
    int bluff = rand() % 10;
    if(bluff == 1)
    {
        int temp = rand() % 15;
        bet = temp;
        return bet;
    }
    else
    {
        if(rank >= 6)
        {
            int temp = rand() % 25;
            bet = 25 + temp;
            return bet;
        }
        if(rank >= 3)
        {
            int temp = rand() % 20;
            bet = 10 + temp;
            return bet;
        }
        if(rank <= 2)
        {
            int temp = rand() % 10;
            bet = temp;
            return bet;
        }
    }
    return bet;
}
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
