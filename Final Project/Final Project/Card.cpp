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
    if(getValue() == "Ace" && c.getValue() != "Ace")
    {
        return true;
    }
    if(getValue() == "King" && c.getValue() != "Ace" && c.getValue() != "King")
    {
        return true;
    }
    if(getValue() == "Queen" && c.getValue() != "Ace" && c.getValue() != "King" && c.getValue() != "Queen")
    {
        return true;
    }
    if(getValue() == "Jack" && c.getValue() != "Ace" && c.getValue() != "King" && c.getValue() != "Queen"
        && c.getValue() != "Jack")
    {
        return true;
    }
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
