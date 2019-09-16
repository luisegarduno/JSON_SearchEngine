#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList(){                                           // Default Constructor
    firstPlayer = nullptr;                                          // "head" is set to nullptr
    TeamSize = 0;                                                   // LinkedList size starts at 0
}

void LinkedList::addPlayer(Player *aPlayer){
    PlayerNode * newPlayerNode = new PlayerNode();                  // creates a tempPlayerNode to store parameter
    newPlayerNode->player = aPlayer;                                // fills tempPlayerNode with parameter Node

    if(firstPlayer == nullptr){                                     // if LinkedList is empty
        firstPlayer = newPlayerNode;                                // head of LinkedList equals parameter Node
        lastPlayer = newPlayerNode;                                 // tail of LinkedList equals parameter Node
        newPlayerNode = nullptr;                                    // sets tempPlayerNode to nullptr
    }
    else{                                                            // if LinkedList is NOT empty
        lastPlayer->nextPlayer = newPlayerNode;                      // current lastPlayer, has a nextPlayer that is pointing to null
                                                                     // set the nextPlayer = to newPlayerNode
        lastPlayer = newPlayerNode;                                  // so now the current lastPlayer will be set equal to newPlayerNode
    }
    TeamSize++;
}

void LinkedList::getPlayer(int taggerID,int pointsToAdd,bool aChecker){
    if(aChecker == false){                                          // if aChecker false, for teamB
        PlayerNode * currentPlayer = firstPlayer;                   // create a Player pointer to be equal to the head
        int count = 0 + TeamSize;                                   // starts counter where teamA left off
        while(count != taggerID){                                   // keep looping until player is found
            currentPlayer = currentPlayer->nextPlayer;              // this sets the currentPlayer = to the nextPlayer
            count++;
        }
        currentPlayer->player->addPoints(pointsToAdd);              // adds points to current Node player
    }
    else{                                                           // for teamA
        PlayerNode * currentPlayer = firstPlayer;
        int count = 0;
        while(count != taggerID){
            currentPlayer = currentPlayer->nextPlayer;
            count++;
        }
        currentPlayer->player->addPoints(pointsToAdd);
    }
}

bool LinkedList::checkTeam(int taggerID){

    if(taggerID >= TeamSize){                                       // this helps split the teams by ID's
        return false;                                               // (assumming ID's are in order)
    }
    else{
        PlayerNode * currentPlayer = firstPlayer;
        int count = 0;
        while(count != taggerID){                                   // searches through players until taggerID matches counter
            currentPlayer = currentPlayer->nextPlayer;
            count++;
        }
        if(currentPlayer->player->getIDNumber() == taggerID){
            return true;                                            // if taggerID is found, return true;
        }
        return true;
    }
}

void LinkedList::print(){
    if(firstPlayer == nullptr){                                     // if head is empty
        cout << "No players" << endl;
    }
    else {
        PlayerNode * currentPlayer = firstPlayer;                   // create temp PlayerNode pointer
        while(currentPlayer != nullptr){
            currentPlayer->player->print();                         // print current Player
            currentPlayer = currentPlayer->nextPlayer;              // set current PlayerNode equal to next player in LinkedList
        }
        cout << endl;
    }
}

LinkedList::~LinkedList(){                                          // destructor for LinkedList class
}
