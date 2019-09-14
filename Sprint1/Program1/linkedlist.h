#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "player.h"

struct PlayerNode{
    Player * player;
    PlayerNode* nextPlayer;
};

class LinkedList{

    PlayerNode* firstPlayer;
    PlayerNode* lastPlayer;
    int TeamSize;

    public:
        LinkedList();
        void addPlayer(Player * player);
        void getPlayer(int taggerID,int pointsToBeAdded,bool aChecker);
        bool checkTeam(int);
        void print();
        ~LinkedList();
};

#endif // LINKEDLIST_H
