#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>
#include <fstream>

using std::ostream;
using std::cout;
using std::endl;
using std::istream;
using std::ifstream;

class DSString{

    private:
        char * data;

    public:
        DSString();                         // Default constructor
        DSString(const char*);              // Constructor w/ 1 paramenter
        DSString(const DSString&);          // Copy constructor
        ~DSString();                        // Destructor

        DSString& operator=(const char*);           // returns DSString& = char * orig
        DSString& operator=(const DSString&);       // returns DSString& = DSString a
        DSString operator+(const DSString&);        // returns DSString& + DSString a
        DSString& operator+=(const DSString&);      // returns DSString& = DSString b + DSString a
        bool operator==(const char*);               // returns bool b ==
        bool operator==(const DSString&);           // returns bool b ==
        bool operator<(const char *);               // returns bool b <
        bool operator<(const DSString&);            // returns bool b <
        char& operator[](const int);                // returns char

        int charToNum(char aValue);
        int size();

// substring: parameter a represents the starting position
//            parameter b represents the number of characters to copy
//            into the substring that is returned. If b is positive,
//            count forward from position a. If b is negative,
//            count backward from position a.
        DSString substring(int a, int b);

// c_str returns a c-string representation of the DSString obj.
        char* c_str();

        friend ostream& operator<<(ostream&, const DSString&);
        friend istream& operator>>(istream&,DSString&);
};

#endif // DSSTRING_H
