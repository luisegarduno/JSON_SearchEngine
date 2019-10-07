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

    bool end = true;
    DSString theLine("");
    for(int i = 0; i < 2; i++){
        DSString tempString("");

        DSString tempWord("");
        for(int j = 0; j < 4; j++){
            if(j == 0){
                dataFile.getline(buffer,1000,',');
                rowNumber.pushBack(buffer);
                cout << buffer << ",";
            }
            if(j == 1){
                dataFile.getline(buffer,1000,',');
                tweetID.pushBack(buffer);
                cout << buffer << ",";
            }
            if(j == 2){
                dataFile.getline(buffer,1000,',');
                username.pushBack(buffer);
                cout << buffer << ",";
            }
            if(j == 3){
                dataFile.getline(buffer,1000);
                int size = 0;//int(strlen(buffer)) - 2;
                int start = 0;
                tempString = buffer;
                cout << buffer << endl;

                while(end){
                    // if character is ABC, abc, ', read next character
                    if( ( (buffer[size] > 64) && (buffer[size] < 91) ) || ( (buffer[size] > 96)  && (buffer[size] < 123) ) || (buffer[size] == 39) ){
                        size += 1;
                    }

                    else if(size > (tempString.size() - 1)){ // if  size is greater than tempString size, the end of the tweet has been reached
                        end = false;
                        break;
                    }
                    else if( (buffer[start] < 65) || ( (buffer[start] > 90) && (buffer[start] < 97) ) || (buffer[start] > 122)){
                        start = size + 1;
                        size = start;
                    }
                    else{
                        //cout << "tempSize " << tempString.size() << endl;
                        //DSString tempsString = tempString;
                        tempWord = tempString.substring(start,size - start);
                        cout << tempString << endl;
                        words.pushBack(tempWord);
                        start = size + 1;
                        size = start;
                        //tempString = buffer;
                        //cout << "tempSize " << tempString.size() << endl;
                    }
                }
                end = true;
            }
        }
        cout << endl;

    }

    dataFile.close();

    words.printVector();

}

void Classifier::classifierTest(DSString&){

}

Classifier::~Classifier(){
    delete [] buffer;
    //delete [] rowBuffer;
}
