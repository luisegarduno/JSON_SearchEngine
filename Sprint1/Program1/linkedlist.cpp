#include "linkedlist.h"
#include "player.h"
#include <iostream>

LinkedList::LinkedList(){
    firstPlayer = nullptr;
    TeamSize = 0;
}

void LinkedList::addPlayer(Player *aPlayer){
    PlayerNode * newPlayerNode = new PlayerNode();
    newPlayerNode->player = aPlayer;

    if(firstPlayer == nullptr){
        firstPlayer = newPlayerNode;
        lastPlayer = newPlayerNode;
        newPlayerNode = nullptr;
    }
    else{
        lastPlayer->nextPlayer = newPlayerNode;
        lastPlayer = newPlayerNode;
    }
    TeamSize++;
}

void LinkedList::getPlayer(int taggerID,int taggedID,int pointsToAdd){
    if(taggerID >= TeamSize){
        cout << "Error: Invalid Player ID" << endl;
    }
    else{
        cout << "TeamSize" << TeamSize << endl;
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

    if(taggerID >= TeamSize){
        return false;
    }
    else{
        PlayerNode * currentPlayer = firstPlayer;
        int count = 0;
        while(count != taggerID){
            currentPlayer = currentPlayer->nextPlayer;
            count++;
        }
        if(currentPlayer->player->getIDNumber() == taggerID){
            return true;
        }
        return true;
    }
}

void LinkedList::print(){
    if(firstPlayer == nullptr){
        cout << "No players" << endl;
    }
    else {
        PlayerNode * currentPlayer = firstPlayer;
        while(currentPlayer != nullptr){
            currentPlayer->player->print();
            currentPlayer = currentPlayer->nextPlayer;
        }
        cout << endl;
    }
}

LinkedList::~LinkedList(){
}
