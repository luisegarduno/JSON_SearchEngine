#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <vector>
#include <string>
#include <algorithm>

using std::string;

template<typename T>
class HashTable{
    public:
        HashTable();
        HashTable(int);

        void add(string,string);

        bool makeEmpty();
        bool remove(const T& x);
        bool contains(const T& x);

    private:

};


#endif // HASHTABLE_H
