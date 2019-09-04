#include "dsstring.h"
#include <iostream>


DSString::DSString(){
    data = nullptr;
}

DSString::DSString(const char* dsString){                               // 'dsString' is a constant, can not change
    data = new char[strlen(dsString) + 1];                              // create new 'data' array size of dsString + 1('\0')
    strcpy(data,dsString);                                              // c-copy 'dsString' into 'data' array
}

DSString::DSString(const DSString& originaldsString){                   // Copy constructor, DSString parameter is a const,
    this->data = new char[strlen(originaldsString.data) + 1];           // that goes by another name (&)
    strcpy(this->data,originaldsString.data);

}

DSString::~DSString(){
    delete [] this->data;
}

DSString& DSString::operator=(const char* dsString){
    this->data = new char[strlen(dsString)];
    strcpy(this->data,dsString);

    return *this;
}

DSString& DSString::operator=(const DSString& originaldsString){
    this->data = new char[strlen(originaldsString.data) + 1];
    strcpy(this->data,originaldsString.data);

    return *this;
}

DSString DSString::operator+(const DSString& originaldsString){
    strcat(this->data,originaldsString.data);
    return *this;
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
