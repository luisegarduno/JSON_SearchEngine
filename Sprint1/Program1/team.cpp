#include <iostream>
#include "team.h"

Team::Team(){
    teamSize = 0;                                       // Initialize Team size & points to 0
    teamPoints = 0;
}

Team::Team(DSString& TeamFile,LinkedList& team){
    ifstream theTeamFile(TeamFile.c_str());             // Opens Team text file

    char * tempTeamChar = new char[100];
    theTeamFile.getline(tempTeamChar,100);              // Reads first line of text file
    setTeamName(tempTeamChar);                          // Uses setter to declare TeamName

    int tempNumOfMembers;
    theTeamFile >> tempNumOfMembers;                    // Reads second line of text file
    setTeamSize(tempNumOfMembers);                      // Uses setter to declare TeamSize

    for(int i = 0; i < getTeamSize(); i++){             // Using the TeamSize integer
        thePlayer(theTeamFile,team);                    // Add every player to appropriate team
    }

    theTeamFile.close();                                // Close team file
    delete [] tempTeamChar;                             // Delete temporary array
}

void Team::thePlayer(ifstream& TeamFile, LinkedList& team){     // Creates/adds player to team
    int num = 0, a = 0, b = 0;
    TeamFile >> num;                                            // Reads file to ONLY read playerID
    this->player = new Player();                                // Create new player on HEAP
    this->player->setIDNumber(num);

    char * tempLineChar = new char[100];                        // Create tempLineChar to hold ID & Name
    TeamFile.getline(tempLineChar,100);
    DSString theName(tempLineChar);                             // Save tempLineChar as new DSString

    while(theName[a] != '\0' && theName[0] != 0){               // Seperates Name from ID
        if(theName[a] == ' '){
            b = a;
        }
        a++;
    }
    this->player->setTeamName(getTeamName());                   // Set the team of this->player
    this->player->setPlayerName(theName.substring(b,a));        // Set the name of this->player
    team.addPlayer(this->player);                               // adds the player object to LinkedList

    delete [] tempLineChar;                                     // deletes tempLineChar from HEAP
}

void Team::setTeamName(const char * tempTeamName){
    this->teamName = tempTeamName;                              // setter for teamName
}

void Team::setTeamSize(int tempNumOfMembers){
    this->teamSize = tempNumOfMembers;                          // setter for teamSize
}

void Team::setTeamPoints(int points){
    this->teamPoints = points;                                  // setter for teamPoints
}

DSString& Team::getTeamName(){
    return this->teamName;                                      // returns teamName
}

int Team::getTeamSize(){
    return this->teamSize;                                      // returns teamSize
}

int Team::getTeamPoints(){
    return this->teamPoints;                                    // returns teamPoints
}
