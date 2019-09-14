#include "linkedlist.h"
#include "player.h"

LinkedList::LinkedList(){
    firstPlayer = nullptr;
    lastPlayer = nullptr;
    TeamSize = 0;
}

void LinkedList::addPlayer(Player *player){
    PlayerNode* newPlayerNode = new PlayerNode();
    newPlayerNode->player = player;

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
    //delete firstPlayer;
    //delete lastPlayer;
}
