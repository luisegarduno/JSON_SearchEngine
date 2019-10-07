#include "classifier.h"
#include <iostream>

Classifier::Classifier(){
    buffer = new char[1000];
}

Classifier::Classifier(char * arg[]){
    DSString trainData(arg[1]);         // trainData = "dev-train-data.csv"
    DSString trainTarget(arg[2]);       // trainTarget = "dev-train-target.csv"
    DSString testData(arg[3]);          // testData = "dev-test-data.csv"
    DSString testTarget(arg[4]);        // testTarget = "dev-test-target.csv"

    classifierTrain(trainData);
    //classifierTest(testData);
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

    bool end = true;
    for(int i = 0; i < 5000; i++){
        DSString tempString("");
        DSString tempWord("");
        for(int j = 0; j < 4; j++){
            if(j == 0){
                dataFile.getline(buffer,1000,',');
                rowNumber.pushBack(buffer);
                //cout << buffer << ",";
            }
            if(j == 1){
                dataFile.getline(buffer,1000,',');
                tweetID.pushBack(buffer);
                //cout << buffer << ",";
            }
            if(j == 2){
                dataFile.getline(buffer,1000,',');
                username.pushBack(buffer);
                //cout << buffer << ",";
            }
            if(j == 3){
                dataFile.getline(buffer,1000);
                int size = 0;
                int start = 0;
                tempString = buffer;
                //cout << buffer << endl;

                while(end){
                    // if character is ABC, abc, ', read next character
                    if( ( ( (buffer[size] > 64) && (buffer[size] < 91) ) || ( (buffer[size] > 96)  && (buffer[size] < 123) ) || (buffer[size] == 39))){
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
                        if(start == 0){
                            tempWord = tempString.substring(start,size - start);
                            start = size + 1;
                        }
                        else{
                            tempWord = tempString.substring(start,size);
                            start = size;
                        }
                        words.pushBack(tempWord);

                        size = start;
                        tempString = buffer;
                    }
                }
                end = true;
            }
        }
        //cout << endl;

    }

    dataFile.close();
    words.quickSort();

    words.printVector();

}


void Classifier::classifierTest(DSString& dataArg){
    ifstream dataFile;
    dataFile.open(dataArg.c_str());

    if(!dataFile.is_open()){
        cout << "Train Data File is not Open. Please check command line input" << endl;
        exit(-1);
    }

    char temp[100];
    dataFile.getline(temp,100);

    //buffer = new char[1000];

    bool end = true;
    for(int i = 0; i < 10001; i++){
        DSString tempString("");
        DSString tempWord("");
        for(int j = 0; j < 4; j++){
            if(j == 0){
                dataFile.getline(buffer,1000,',');
                rowNumber.pushBack(buffer);
            }
            if(j == 1){
                dataFile.getline(buffer,1000,',');
                tweetID.pushBack(buffer);
            }
            if(j == 2){
                dataFile.getline(buffer,1000,',');
                username.pushBack(buffer);
            }
            if(j == 3){
                dataFile.getline(buffer,1000);
                int size = 0;
                int start = 0;
                tempString = buffer;

                while(end){
                    // if character is ABC, abc, ', read next character
                    if( ( ( (buffer[size] > 64) && (buffer[size] < 91) ) || ( (buffer[size] > 96)  && (buffer[size] < 123) ) || (buffer[size] == 39))){
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
                        if(start == 0){
                            tempWord = tempString.substring(start,size - start);
                            start = size + 1;
                        }
                        else{
                            tempWord = tempString.substring(start,size);
                            start = size;
                        }
                        words.pushBack(tempWord);
                        size = start;
                        tempString = buffer;
                    }
                }
                end = true;
            }
        }

    }

    dataFile.close();
}


Classifier::~Classifier(){
    delete [] buffer;
}
