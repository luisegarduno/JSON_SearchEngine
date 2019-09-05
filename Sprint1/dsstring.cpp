#include "dsstring.h"
#include <iostream>
#include <fstream>

DSString::DSString(){
    data = nullptr;
}

DSString::DSString(const char* originalChar){                               // 'originalChar' is a constant, can not change
    this->data = new char[strlen(originalChar) + 1];                        // create new 'data' array size of originalChar + 1('\0')
    strcpy(this->data,originalChar);                                        // c-copy 'originalChar' into 'data' array
}

DSString::DSString(const DSString& originaldsString){                   // Copy constructor, DSString parameter is a const,
    this->data = new char[strlen(originaldsString.data) + 1];           // that goes by another name (&)
    strcpy(this->data,originaldsString.data);

}

DSString::~DSString(){
    delete [] this->data;
}

DSString& DSString::operator=(const char* originalChar){                    // returns DSString& = originalChar
    this->data = new char[strlen(originalChar) + 1];                        // create new data array size of parameter + 1
    strcpy(this->data,originalChar);                                        //

    return *this;                                                           // *this returns a reference to the object
}

DSString& DSString::operator=(const DSString& originalString){              // returns DSString& = originalString
    this->data = new char[strlen(originalString.data) + 1];                 // create this->data size of parameter + 1
    strcpy(this->data,originalString.data);                                 // copy parameter data, to this->data

    return *this;
}

DSString DSString::operator+(const DSString& originaldsString){
    DSString newString;
    strcpy(newString.data,originaldsString.data);

    return newString;
}

DSString& DSString::operator+=(const DSString& originaldsString){
    char * tempString = this->data;
    this->data = new char[strlen(tempString) + strlen(originaldsString.data) + 1];
    strcpy(this->data,tempString);
    strcat(this->data,originaldsString.data);

    delete [] tempString;

    return *this;                                                           // return a reference to invoking address
}

bool DSString::operator==(const char*){
    return false;
}

bool DSString::operator==(const DSString&){
    return true;
}

bool DSString::operator<(const char *){
    return true;
}

bool DSString::operator<(const DSString&){
    return true;
}

char& DSString::operator[](const int){

}

int DSString::size(){
    return 0;
}

char* DSString::c_str(){
    return this->data;
}

