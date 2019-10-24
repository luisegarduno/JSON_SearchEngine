#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>
#include <fstream>

using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;

class DSString{

    private:
        char * data;

    public:
        DSString();                                 // Default constructor
        DSString(const char*);                      // Constructor w/ 1 paramenter
        DSString(const DSString&);                  // Copy constructor
        ~DSString();                                // Destructor

        DSString& operator=(const char*);           // returns DSString& = char * orig
        DSString& operator=(const DSString&);       // returns DSString& = DSString a
        DSString operator+(const DSString&);        // returns DSString& + DSString a
        DSString& operator+=(const DSString&);      // returns DSString& = DSString b + DSString a
        bool operator==(const char*)const;          // returns bool b ==
        bool operator==(const DSString&)const;      // returns bool b ==
        bool operator<(const char *)const;          // returns bool b <
        bool operator<(const DSString&)const;       // returns bool b <
        bool operator>(const DSString&)const;       // returns bool b >
        bool operator<=(const DSString&)const;      // returns bool <=
        bool operator>=(const DSString&)const;
        char& operator[](const int);                // returns char

        int size();                                 // returns size of DSString

        DSString substring(int a, int b);           // View DSString.cpp for extended info

        char* c_str();                              // returns a c-string representation of the DSString Obj

        friend std::ostream& operator<<(std::ostream&, const DSString&);
        friend std::istream& operator>>(std::istream&,DSString&);
};

#endif // DSSTRING_H
