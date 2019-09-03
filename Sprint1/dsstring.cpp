#include "dsstring.h"
#include <iostream>


DSString::DSString(){

}

DSString::DSString(const char*){

}

DSString::DSString(const DSString&){          // Copy constructor

}

DSString::~DSString(){

}

DSString& DSString::operator=(const char*){

}

DSString& DSString::operator=(const DSString&){

}

DSString DSString::operator+(const DSString&){

}

DSString& DSString::operator+=(const DSString&){

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
    char theArray = "hi";
    return theArray;
}

int DSString::size(){
    return 0;
}

char* DSString::c_str(){

}
