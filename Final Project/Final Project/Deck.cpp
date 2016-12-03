//
//  Deck.cpp
//  Final Project
//
//  Created by Steven Mumford on 11/16/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#include "Deck.hpp"

Deck::Deck(int temp)
{
    deck.push_back(new Card("2", "Hearts"));
    deck.push_back(new Card("3", "Hearts"));
    deck.push_back(new Card("4", "Hearts"));
    deck.push_back(new Card("5", "Hearts"));
    deck.push_back(new Card("6", "Hearts"));
    deck.push_back(new Card("7", "Hearts"));
    deck.push_back(new Card("8", "Hearts"));
    deck.push_back(new Card("9", "Hearts"));
    deck.push_back(new Card("10", "Hearts"));
    deck.push_back(new Card("Jack", "Hearts"));
    deck.push_back(new Card("Queen", "Hearts"));
    deck.push_back(new Card("King", "Hearts"));
    deck.push_back(new Card("Ace", "Hearts"));
    deck.push_back(new Card("2", "Diamonds"));
    deck.push_back(new Card("3", "Diamonds"));
    deck.push_back(new Card("4", "Diamonds"));
    deck.push_back(new Card("5", "Diamonds"));
    deck.push_back(new Card("6", "Diamonds"));
    deck.push_back(new Card("7", "Diamonds"));
    deck.push_back(new Card("8", "Diamonds"));
    deck.push_back(new Card("9", "Diamonds"));
    deck.push_back(new Card("10", "Diamonds"));
    deck.push_back(new Card("Jack", "Diamonds"));
    deck.push_back(new Card("Queen", "Diamonds"));
    deck.push_back(new Card("King", "Diamonds"));
    deck.push_back(new Card("Ace", "Diamonds"));
    deck.push_back(new Card("2", "Clubs"));
    deck.push_back(new Card("3", "Clubs"));
    deck.push_back(new Card("4", "Clubs"));
    deck.push_back(new Card("5", "Clubs"));
    deck.push_back(new Card("6", "Clubs"));
    deck.push_back(new Card("7", "Clubs"));
    deck.push_back(new Card("8", "Clubs"));
    deck.push_back(new Card("9", "Clubs"));
    deck.push_back(new Card("10", "Clubs"));
    deck.push_back(new Card("Jack", "Clubs"));
    deck.push_back(new Card("Queen", "Clubs"));
    deck.push_back(new Card("King", "Clubs"));
    deck.push_back(new Card("2", "Spades"));
    deck.push_back(new Card("3", "Spades"));
    deck.push_back(new Card("4", "Spades"));
    deck.push_back(new Card("5", "Spades"));
    deck.push_back(new Card("6", "Spades"));
    deck.push_back(new Card("7", "Spades"));
    deck.push_back(new Card("8", "Spades"));
    deck.push_back(new Card("9", "Spades"));
    deck.push_back(new Card("10", "Spades"));
    deck.push_back(new Card("Jack", "Spades"));
    deck.push_back(new Card("Queen", "Spades"));
    deck.push_back(new Card("King", "Spades"));
    deck.push_back(new Card("Ace", "Spades"));
    
}

Deck::~Deck()
{
    for(int i=0; i < 51; i++)
    {
        delete deck.at(i);
    }
}

Card* Deck::at(int index)
{
    return deck.at(index);
}

void Deck::shuffleDeck()
{
    srand((unsigned int)time(NULL));
    for(int i=0; i<deck.size(); i++)
    {
        int index = rand() % deck.size();
        Card *temp = deck[index];
        deck[index] = deck[i];
        deck[i] = temp;
    }
}
