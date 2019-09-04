#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>

class DSString{

    private:
        char * data;

    public:
        DSString();                         // Default constructor
        DSString(const char*);
        DSString(const DSString&);          // Copy constructor
        ~DSString();                        // Destructor

        DSString& operator=(const char*);
        DSString& operator=(const DSString&);
        DSString operator+(const DSString&);
        DSString& operator+=(const DSString&);
        bool operator==(const char*);
        bool operator==(const DSString&);
        bool operator<(const char *);
        bool operator<(const DSString&);
        char& operator[](const int);

        int size();

// substring: parameter a represents the starting position
//            parameter b represents the number of characters to copy
//            into the substring that is returned. If b is positive,
//            count forward from position a. If b is negative,
//            count backward from position a.
        DSString substring(int a, int b);

// c_str returns a c-string representation of the DSString obj.
        char* c_str();

        friend std::ostream& operator<<(std::ostream&, const DSString &);
};

#endif // DSSTRING_H
