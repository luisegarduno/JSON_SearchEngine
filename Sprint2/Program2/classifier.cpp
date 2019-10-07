#include "classifier.h"
#include <iostream>

Classifier::Classifier(){
    //rowNum = 0;
    buffer = new char[1000];
    rowNumber = 0;
    tweetID = 0;
    username = 0;
    tweets = 0;
    words = 0;
}

Classifier::Classifier(char * arg[]){
    DSString trainData(arg[1]);         // trainData = "dev-train-data.csv"
    DSString trainTarget(arg[2]);       // trainTarget = "dev-train-target.csv"
    DSString testData(arg[3]);          // testData = "dev-test-data.csv"
    DSString testTarget(arg[4]);        // testTarget = "dev-test-target.csv"

    classifierTrain(trainData);
}


void Classifier::classifierTrain(DSString& dataArg){
    ifstream dataFile;
    dataFile.open(dataArg.c_str());

    if(!dataFile.is_open()){
        cout << "Train Data File is not Open. Please check command line input" << endl;
        exit(-1);
    }
    char temp[100];
    dataFile.getline(temp,100);

    buffer = new char[1000];

    /*
    int delim = 0;
    buffer = new char[1000];
    rowBuffer = new char[10];
    dataFile.getline(buffer,1000);
    */

    DSString theLine("");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            if(j == 0){
                dataFile.getline(buffer,1000,',');
                cout << "Row: " << buffer << endl;
            }
            if(j == 1){
                dataFile.getline(buffer,1000,',');
                cout << "Tweet ID: " << buffer << endl;
            }
            if(j == 3){
                dataFile.getline(buffer,1000,',');
                cout << "Username: " << buffer << endl;
            }
            if(j == 4){
                dataFile.getline(buffer,1000,'\n');
                cout << "Tweet: " << buffer << endl;
            }
        }
        cout << endl;

    }

    dataFile.close();

}

void Classifier::classifierTest(DSString&){

}

Classifier::~Classifier(){
    delete [] buffer;
    //delete [] rowBuffer;
}
