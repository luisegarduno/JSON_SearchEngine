#include "linkedlist.h"
#include "player.h"
#include <iostream>

LinkedList::LinkedList(){
    firstPlayer = nullptr;
    lastPlayer = nullptr;
    TeamSize = 0;
}

void LinkedList::addPlayer(Player *aPlayer){
    PlayerNode* newPlayerNode = new PlayerNode();
    newPlayerNode->player = aPlayer;

    if(firstPlayer == nullptr){
        firstPlayer = newPlayerNode;
        lastPlayer = newPlayerNode;
    }
    else{
        lastPlayer->nextPlayer = newPlayerNode;
        newPlayerNode->previousPlayer = lastPlayer;
        lastPlayer = newPlayerNode;
    }
    TeamSize++;
    delete newPlayerNode;
}

void LinkedList::getPlayer(int playerID){
    if(playerID >= TeamSize){
        cout << "Error: Invalid Player ID" << endl;
    }
    else{
        PlayerNode * currentPlayer = firstPlayer;
        int count = 0;
        while(count != playerID){
            currentPlayer = currentPlayer->nextPlayer;
            count++;
        }
    }
}

void LinkedList::deletePlayerNode(PlayerNode *currentPlayer){
    PlayerNode * newNextPlayer = currentPlayer->nextPlayer;
    PlayerNode * newPreviousPlayer = currentPlayer->previousPlayer;

    if(newNextPlayer != nullptr){
        newNextPlayer->previousPlayer = newPreviousPlayer;
    }
    if(newPreviousPlayer != nullptr){
        newPreviousPlayer->nextPlayer = newNextPlayer;
    }
    if(currentPlayer == firstPlayer){
        firstPlayer = newNextPlayer;
    }
    if(currentPlayer == lastPlayer){
        lastPlayer = newPreviousPlayer;
    }
}

void LinkedList::print(){
    if(firstPlayer == nullptr){
        cout << "No players" << endl;
    }
    else {
        PlayerNode * currentPlayer = firstPlayer;
        int count = 0;
        while(currentPlayer != nullptr){
            ++count;
            currentPlayer->player->print();
            currentPlayer = currentPlayer->nextPlayer;
        }

        cout << endl;
    }
}

LinkedList::~LinkedList(){
}
