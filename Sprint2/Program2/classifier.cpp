#include "classifier.h"
#include <iostream>

Classifier::Classifier(){
    //rowNum = 0;
    buffer = new char[1000];
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
    dataFile.getline(buffer,1000,',');
    cout << buffer << endl;

            /*
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < 4; j++ ){
            if(j == 0){
                dataFile.getline(buffer,1000,',');
            }
            if(j == 1){
                dataFile.getline(buffer,1000,',');
            }
        }
        dataFile.getline(buffer, 1000, ',');
        cout << buffer << endl;
    }
    */

    dataFile.close();

}

void Classifier::classifierTest(DSString&){

}

Classifier::~Classifier(){
    delete [] buffer;
}
