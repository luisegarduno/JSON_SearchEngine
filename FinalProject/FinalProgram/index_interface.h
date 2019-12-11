#ifndef INDEX_INTERFACE_H
#define INDEX_INTERFACE_H

#include <string>
#include <fstream>
#include <iostream>
#include <experimental/iterator>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::ostream;
using std::vector;
using std::cout, std::endl;
using std::ostream_iterator;

struct word{
    string the_Word;
    string the_File;
    int the_Frequency;

    vector<string> wordInVec;
    int frequency;
    map<string,int> docANDFreq;
    vector<string> word_Index;

    void printWord(){
        map<string,int>::iterator theIterator;
        cout << the_Word << " was found in : ";
        for(theIterator = docANDFreq.begin(); theIterator != docANDFreq.end(); theIterator++){
            cout << theIterator->first << ", ";
        }
    }

};



class Index_Interface{
    public:
        Index_Interface() { }
        virtual void load_Index() = 0;
        virtual word& search_Index(word&) = 0;
        virtual void insert_In_Index(word&, string&) = 0;
        virtual void clear_Index() = 0;
        virtual void print_Index() = 0;

        virtual ~Index_Interface() { }
};

#endif // INDEX_INTERFACE_H
