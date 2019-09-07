#include "dsstring.h"
#include <iostream>

DSString::DSString(){
    //cout << "in default constructor" << endl;
    this->data = nullptr;
}

DSString::DSString(const char* originalChar){                               // 'originalChar' is a constant, can not change

    this->data = new char[strlen(originalChar) + 1];                        // create new 'data' array size of originalChar + 1('\0')
    strcpy(this->data,originalChar);                                        // c-copy 'originalChar' into 'data' array
    //cout << "in constructor: " << this->data << endl;
}

DSString::DSString(const DSString& originaldsString){                       // Copy constructor, DSString parameter is a const,
    this->data = new char[strlen(originaldsString.data) + 1];               // that goes by another name (&)
    strcpy(this->data,originaldsString.data);
    //cout << "in copy constructor: " << this->data << endl;

}

DSString::~DSString(){                                                      // destructor
    //cout << "in destructor: " << this->data << endl;
    delete [] this->data;
}

DSString& DSString::operator=(const char* originalChar){                    // returns DSString& = originalChar
    //cout << "in operator=(const char*) << ";
    this->data = new char[strlen(originalChar) + 1];
    strcpy(this->data,originalChar);                                        // copies originalChar to this->data

    return *this;                                                           // *this returns a reference to the object
}

DSString& DSString::operator=(const DSString& originalString){              // returns DSString& = originalString
    //cout << "in operator=(const DSString&) << ";
    this->data = new char[strlen(originalString.data) + 1];
    strcpy(this->data,originalString.data);                                 // copies originalString.data to this->data

    return *this;                                                           // return DSString by reference
}

DSString DSString::operator+(const DSString& originalString){
    cout << "in operator+(const DSString&) << ";
    DSString newString = this->data;
    strcat(newString.data,originalString.data);

    return newString;                                                       // return DSString by value
}

DSString& DSString::operator+=(const DSString& originaldsString){
    cout << "in operator+=(const DSString&) << ";
    char * tempChar = this->data;                                           // temporarily store this->data
    this->data = new char[strlen(tempChar) + strlen(originaldsString.data) + 1];    // empty out this->data
    strcpy(this->data,tempChar);                                            // copy tempChar to this->data
    strcat(this->data,originaldsString.data);                               // concatenate orginialString.data to this->data

    delete [] tempChar;

    return *this;                                                           // return a reference to invoking address
}

bool DSString::operator==(const char*){
    cout << "in operator==(const char*) << ";
    return false;
}

bool DSString::operator==(const DSString&){
    cout << "in operator==(const DSString&) << ";
    return true;
}

bool DSString::operator<(const char *){
    cout << "in operator<(const char*) << ";
    return true;
}


bool DSString::operator<(const DSString&){
    cout << "in operator<(const DSString&) << ";
    return true;
}

char& DSString::operator[](const int indexSize){
    //cout << "in operator[] << ";
    return *(this->data + indexSize);

}

int DSString::charToNum(char aValue){
    switch(aValue){
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case '0':
            return 0;
        default:
            return -1;
    }
}

int DSString::size(){                                                       // return by value
    //cout << "in size() << ";
    char *tempSize = &this->data[0];


    return strlen(tempSize);
}

/*  Parameter a represents the starting position
 *  Parameter b represents the # of characters to copy into the substring that is returned.
 *  If b is (+), count forward from position a.
 *  If b is (-), count backward from position b.
 */
DSString DSString::substring(int a, int b){
    cout << "in substring" << endl;
    if(b > 0){

    }
    else if(b < 0){

    }
}

char* DSString::c_str(){                                                    // returns by pointer
    //cout << "in c_str" << endl;
    return this->data;
}

ostream& operator<<(ostream& out, const DSString& theString){
    //cout << "is ostream&" << endl;
    out << theString.data;

    return out;
}

istream& operator>>(istream& stream,DSString& theString){
    cout << "in istream&" << endl;
    char * tempChar = theString.data;

    theString.data = new char[100];

    if(stream.good()){
        while(!stream.eof()){
            stream >> *(theString.data);
        }
        cout << *(theString.data) << endl;
    }

    delete [] tempChar;

    return stream;
}

