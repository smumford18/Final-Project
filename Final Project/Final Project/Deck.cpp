//
//  Deck.cpp
//  Final Project
//
//  Created by Steven Mumford on 11/16/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#include "Deck.hpp"

Deck::Deck()
{
    deck.push_back(Card("2", "Hearts"));
    deck.push_back(Card("3", "Hearts"));
    deck.push_back(Card("4", "Hearts"));
    deck.push_back(Card("5", "Hearts"));
    deck.push_back(Card("6", "Hearts"));
    deck.push_back(Card("7", "Hearts"));
    deck.push_back(Card("8", "Hearts"));
    deck.push_back(Card("9", "Hearts"));
    deck.push_back(Card("10", "Hearts"));
    deck.push_back(Card("Jack", "Hearts"));
    deck.push_back(Card("Queen", "Hearts"));
    deck.push_back(Card("King", "Hearts"));
    deck.push_back(Card("Ace", "Hearts"));
    deck.push_back(Card("2", "Diamonds"));
    deck.push_back(Card("3", "Diamonds"));
    deck.push_back(Card("4", "Diamonds"));
    deck.push_back(Card("5", "Diamonds"));
    deck.push_back(Card("6", "Diamonds"));
    deck.push_back(Card("7", "Diamonds"));
    deck.push_back(Card("8", "Diamonds"));
    deck.push_back(Card("9", "Diamonds"));
    deck.push_back(Card("10", "Diamonds"));
    deck.push_back(Card("Jack", "Diamonds"));
    deck.push_back(Card("Queen", "Diamonds"));
    deck.push_back(Card("King", "Diamonds"));
    deck.push_back(Card("Ace", "Diamonds"));
    deck.push_back(Card("2", "Clubs"));
    deck.push_back(Card("3", "Clubs"));
    deck.push_back(Card("4", "Clubs"));
    deck.push_back(Card("5", "Clubs"));
    deck.push_back(Card("6", "Clubs"));
    deck.push_back(Card("7", "Clubs"));
    deck.push_back(Card("8", "Clubs"));
    deck.push_back(Card("9", "Clubs"));
    deck.push_back(Card("10", "Clubs"));
    deck.push_back(Card("Jack", "Clubs"));
    deck.push_back(Card("Queen", "Clubs"));
    deck.push_back(Card("King", "Clubs"));
    deck.push_back(Card("2", "Spades"));
    deck.push_back(Card("3", "Spades"));
    deck.push_back(Card("4", "Spades"));
    deck.push_back(Card("5", "Spades"));
    deck.push_back(Card("6", "Spades"));
    deck.push_back(Card("7", "Spades"));
    deck.push_back(Card("8", "Spades"));
    deck.push_back(Card("9", "Spades"));
    deck.push_back(Card("10", "Spades"));
    deck.push_back(Card("Jack", "Spades"));
    deck.push_back(Card("Queen", "Spades"));
    deck.push_back(Card("King", "Spades"));
    deck.push_back(Card("Ace", "Spades"));
    
}

void Deck::shuffleDeck()
{
//    template <typename T>
//    void shuffle(vector<T>& v)
//    {
//        srand((unsigned int)time(NULL));
//        for(int i=0; i<v.size(); i++)
//        {
//            int index = rand() % v.size();
//            T temp = v[index];
//            v[index]=v[i];
//            v[i]=temp;
//        }
//    }
//This is my code for a function to shuffle the items in a vector from homework 5
//I'd adjust this to make it work for our cards
}
