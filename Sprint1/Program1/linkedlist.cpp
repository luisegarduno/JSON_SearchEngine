#include "linkedlist.h"

LinkedList::LinkedList(){
    firstPlayer = nullptr;
    lastPlayer = nullptr;
    TeamSize = 0;
}

void LinkedList::addPlayer(Player *player){
    PlayerNode *newPlayerNode = new PlayerNode();
    newPlayerNode->player = player;

    if(firstPlayer == nullptr){
        firstPlayer = newPlayerNode;
        lastPlayer = newPlayerNode;
    }
    else{
        lastPlayer->nextPlayer = new PlayerNode();
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

void LinkedList::printLow(){
    if(firstPlayer == nullptr){
        cout << "No players" << endl;
    }
    else {
        PlayerNode * currentPlayer = firstPlayer;
        int count = 0;
        cout << endl;
        while(currentPlayer != nullptr){
            ++count;
            //currentPlayer->player->print();
            cout << endl;
            currentPlayer = currentPlayer->nextPlayer;
        }

    }
}
