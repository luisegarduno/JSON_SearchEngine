#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "player.h"

struct PlayerNode{
    Player * player;
    PlayerNode* nextPlayer;
    PlayerNode* previousPlayer;
};

class LinkedList{

    PlayerNode* firstPlayer;
    PlayerNode* lastPlayer;
    int TeamSize;

    public:
        LinkedList();
        void addPlayer(Player * player);
        void getPlayer(int index);
        void printLow();
};

#endif // LINKEDLIST_H
