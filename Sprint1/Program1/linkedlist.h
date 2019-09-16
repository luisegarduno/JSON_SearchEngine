#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "player.h"

struct PlayerNode{                          // PlayerNode is a group of Data Elements
    Player * player;                        // Each PlayerNode is composed of a Player pointer
    PlayerNode* nextPlayer;                 // Each PlayerNode is also composed of PlayerNode pointer
};

class LinkedList{

    PlayerNode* firstPlayer;                // PlayerNode has a head
    PlayerNode* lastPlayer;                 // PlayerNode has a tail
    int TeamSize;                           // Size of LinkedList

    public:
        LinkedList();                       // Default constructor
        void addPlayer(Player * player);    // Adds Player to LinkedList
        void getPlayer(int taggerID,int pointsToBeAdded,bool aChecker);
        bool checkTeam(int);                // checks to see if player is in this->LinkedList
        void print();                       // Prints out this->player from LinkedList
        ~LinkedList();
};

#endif // LINKEDLIST_H
