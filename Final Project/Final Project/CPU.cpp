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

int CPU::texasBet(int rank, int otherBet, bool check)
{
    int bet = 0;
    srand((unsigned int)time(NULL));
    // An option for if check is passed on to the CPU
    if(check == true)
    {
        // 10% chance the CPU bluffs
        int bluff = rand() % 10;
        if(bluff == 0)
        {
            if(rank >= 3)
            {
                int temp = rand() % 15;
                bet = temp;
                return bet;
            }
            if(rank == 2)
            {
                int temp = rand() % 10;
                bet = 5 + temp;
                return bet;
            }
            if(rank == 1)
            {
                int temp = rand() % 5;
                bet = temp;
                return bet;
            }
        }
        else
        {
            if(rank >= 7)
            {
                int temp = rand() % 25;
                bet = temp;
                return bet;
            }
            if(rank >= 5)
            {
                int temp = rand() % 15;
                bet = 10 + temp;
                return bet;
            }
            if(rank >= 3)
            {
                int temp = rand() % 15;
                bet = temp;
                return bet;
            }
            if(rank == 2)
            {
                int chanceCheck = rand() % 2;
                // With a pair, 50% chance CPU checks or raises
                if(chanceCheck == 0)
                {
                    int temp = rand() % 5;
                    bet =  temp;
                    return bet;
                }
                else if(chanceCheck == 1)
                {
                    bet = otherBet;
                    return bet;
                }
            }
            // With a high card, matches bet
            // UPDATE? if high card is low enough, fold
            if(rank == 1)
            {
                bet = otherBet;
                return bet;
            }
        }
    }
    else if(check == false)
    {
        int bluff = rand() % 10;
        // Random number that allows for 10% chance the CPU bluffs
        if(bluff == 0)
        {
            // Random number that allows for 25% chance CPU increases the bet while bluffing and 75% chance CPU matches check
            int chanceCheck = rand() % 4;
            if(chanceCheck == 0)
            {
                int temp = rand() % 5;
                bet = otherBet + temp;
                return bet;
            }
            else if(chanceCheck >= 1)
            {
                bet = 0;
                return bet;
            }
        }
        // 90% chance the CPU doesn't bluff
        else
        {
            if(rank >= 6)
            {
                // If the total bet is less than 15, CPU raises bet
                if(otherBet < 15)
                {
                    int temp = rand() % 25;
                    bet = otherBet + temp;
                    return bet;
                }
                // Or matches the bet if it is greater than 15
                else
                {
                    bet = 0;
                    return bet;
                }
            }
            if(rank >= 3)
            {
                // If the total bet is less than 8, CPU raises bet
                if(otherBet < 8)
                {
                    int temp = rand() % 20;
                    bet = otherBet + temp;
                    return bet;
                }
                // Or matches the bet if it is greater than 8
                else
                {
                    bet = 0;
                    return bet;
                }
            }
            if(rank == 2)
            {
                // If the total bet is less than 4, CPU raises bet
                if(otherBet < 4)
                {
                    int temp = rand() % 10;
                    bet = temp;
                    return bet;
                }
                // Or matches the bet if it is greater than 4
                else
                {
                    bet = 0;
                    return bet;
                }
            }
            if(rank == 1)
            {
                bet = 0;
                return bet;
            }
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
