//
//  Blackjack.cpp
//  Final Project
//
//  Created by Steven Mumford on 12/1/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#include "Blackjack.hpp"
#include "Card.hpp"


void Blackjack::play(User user1)
{
    //int deck[13]={1,2,3,4,5,6,7,8,9,10,10,10,10};
    int total=0, /*card,*/ aces=0;
    bool aceReduced=false,bust=false, end=false,hitAsked;
    int dealerTotal=0, dealerAces=0;
    bool dealerBust=false, dealerAceReduced=false, /*dealerHitAsked,*/ dealerFirst=true;
    srand(time(0));
    
    do {
        aces=0;
        dealerAces = 0;
        aceReduced = false;
        dealerAceReduced = false;
        hitAsked = false;
        
        cout<<"Dealer is Displaying: ";
        dealerTotal=hit(dealerAces);
        cout << "You Recieved: ";
        total=hit(aces);
        
        bust = userPlay(total, aces, aceReduced, bust, hitAsked);
        
        dealerPlay(bust, dealerFirst, dealerTotal, dealerAces, dealerBust, dealerAceReduced, total);
        
        end=askEnd();
        cout << endl;
    } while(!end);
}
    // Function to get a suit for the card and output the card and suit. Also assigns a face card if the card value is 10
void Blackjack::cardOutput(int card) {
        string suit[4] = { "Hearts","Diamonds", "Clubs", "Spades" };
        
        int tmp = rand() % 4;
        if(card == 10) {
            string tens[4] = { "10", "Jack", "Queen", "King" };
            
            int tmp1 = rand() % 4;
            cout <<  tens[tmp1] << " of " << suit[tmp]<<endl;
        }else if(card==1 || card==11)
            cout << "Ace of " << suit[tmp] << endl;
        else {
            cout <<  card << " of " << suit[tmp]<<endl;
        }
    }
    // Takes new card from getCard() and adds it to the rest of hand and runs thru the ace functions in case that card is an ace
int Blackjack::hit(int& aces){
    int card=getCard();
        aces+=isAce(card);
        card=aceAddition(card, aces);
        cardOutput(card);
        return card;
    }
    
    // Function to ask user whether or not they want hit on their hand
bool Blackjack::askHit(int total){
        string userInput;
        do{
            bool hitAsked;
            cout<<"Your total is "<<total<<". Do you want to hit?(Y/N) ";
            cin>>userInput;
            if (userInput=="Y"||userInput=="y"){
                hitAsked=true;
                return hitAsked;
            }
            if (userInput=="N"||userInput=="n"){
                hitAsked=false;
                return hitAsked;
            }
        }while(!((userInput=="Y"||userInput=="y")||(userInput=="N"||userInput=="n")));
        return total;
    }
    
    // Function to ask user whether or not they wish to continue playing
bool Blackjack::askEnd(){
        bool choice;
        cout<<"Do you wish to quit? (Enter 0 to continue or any other number to quit) ";
        cin>>choice;
            return choice;
    }
    
    // Checks to see if card is an aces, and if it is, assigns it either the value 0 or 1
int Blackjack::isAce(int card){
        if (card==1)
            return 1;
        else
            return 0;
    }
    
    // Checks total in the hand to determine whether or not the hand busts
bool Blackjack::isBust(int userSum){
        if (userSum <= 21)
            return false;
        else
            return true;
    }
    
    // Function that gets a numerical value for the card
int Blackjack::getCard() {
        int deck[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
        int num = rand() % 13;
        int card = deck[num];
        return card;
    }
    //Gives the Ace card from getCard either the value 1 or 11
int Blackjack::aceAddition(int total, int aces){
        if (total==1){
            if (aces==1)
                total+=10;
        }
        return total;
    }
    //Checks the bool aceReduced and if false will reduce the valued ace of 11 to 1
int Blackjack::aceReduction(int total, int aces, bool& aceReduced){
        if (aceReduced==false){
            if (aces>0){
                total-=10;
                aceReduced=true;
            }
            return total;
        }
        return total;
    }
    //Function that keeps tally of Users hand and uses all the functions in order to keep the users hand tallied correctly, and returns bust when user tally goes above 21
bool Blackjack::userPlay(int& total, int aces, bool& aceReduced, bool bust, bool hitAsked) {
        do {
            cout << "You Recieved: ";
            total+=hit(aces);
            bust=isBust(total);
            if (bust==true){
                int tmp = total;
                total = aceReduction(total, aces, aceReduced);
                if (total<tmp)
                    cout << "Ace Reduced" << endl;
            }
            bust=isBust(total);
            
            if(bust==1) {
                cout << "Your total is " << total << endl;
                cout<<"You lose!!!"<<endl;
                break;//continue;
            } else {
                hitAsked = askHit(total);
            }
        } while(hitAsked==true && bust==false);
        return bust;
    }
    //Function that tallies the hand of the dealer and uses all functions in order to do so, also checks dealer hand with the user hand to see who won the game, also returns if dealer busts
void Blackjack::dealerPlay(bool bust, bool dealerFirst, int dealerTotal, int dealerAces, bool dealerBust, bool dealerAceReduced, int& total) {
        if (bust==false){
            do {
                if (dealerFirst==false)
                    cout<<"The dealer recieved a ";
                if (dealerFirst==true)
                    cout<<"The dealer revealed a ";
                dealerTotal+=hit(dealerAces);
                dealerBust=isBust(dealerTotal);
                if (dealerBust==true){
                    dealerTotal=aceReduction(dealerTotal, dealerAces, dealerAceReduced);
                    if(dealerAceReduced== true) 
                        cout<<"Ace Reduced"<<endl;
                }
                dealerBust=isBust(dealerTotal);
                dealerFirst=false;
            } while(dealerTotal<17);
            
            cout << "The dealer had " << dealerTotal << endl;
            if(dealerBust==false) {
                if (total>dealerTotal)
                    cout<<"You win!!!\n";
                else
                    cout<<"You lose!!!\n";
            } 
            if(dealerBust==true && bust==false) {
                cout << "Dealer Busts" << endl << "You win!!!\n";
            }
        }
        
    }
    

    
    
    
    
