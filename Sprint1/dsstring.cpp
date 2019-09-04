#include "dsstring.h"
#include <iostream>


DSString::DSString(){
    data = nullptr;
}

DSString::DSString(const char* dsString){           // 'dsString' is a constant, can not change
    data = new char[strlen(dsString) + 1];          // create new 'data' array size of dsString + 1('\0')
    strcpy(data,dsString);                          // c-copy 'dsString' into 'data' array
}

DSString::DSString(const DSString&){                // Copy constructor, DSString parameter is a const,
    //data = new char[strlen(originalDSString) + 1];                   // that goes by another name (&)
    //strcpy(data,originalDSString);
}

DSString::~DSString(){
    delete [] data;
}

DSString& DSString::operator=(const char*){

}

DSString& DSString::operator=(const DSString&){

}

DSString DSString::operator+(const DSString&){

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
    return data;
}
