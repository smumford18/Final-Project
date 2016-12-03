//
//  Card.cpp
//  Final Project
//
//  Created by Steven Mumford on 11/16/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//
#include <iostream>
using namespace std;
#include "Card.hpp"

Card::Card(string VALUE, string SUIT)
{
    value = VALUE;
    suit = SUIT;
}

string Card::getSuit()
{
    return suit;
}

string Card::getValue()
{
    return value;
}

string Card::displayCard()
{
    string output = value + " of " + suit;
    return output;
}

bool Card::operator==(Card& c)
{
    if(getValue() == c.getValue())
    {
        return true;
    }
    else
        return false;
}

bool Card::operator>(Card& c)
{
    if(getValue() > c.getValue())
    {
        return true;
    }
    else
        return false;
}

bool Card::operator<(Card& c)
{
    if(getValue() == c.getValue())
    {
        return true;
    }
    else
        return false;
}
