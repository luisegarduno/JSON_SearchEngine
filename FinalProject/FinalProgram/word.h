#ifndef WORD_H
#define WORD_H

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

class word{
    public:
        word();
        word(string,string);
        word(const word&);
        word& operator=(const word&);

        void setWord(string w);
        string getWord() const;

        void newDocumentName(string docName);
        void addDocumentName(string docName);
        map<string,int> getDocumentNames();

        void setFrequencyForDoc(string,int);
        int getFrequencyForDoc(string);

        bool checkMap(string);


        void printWord();
    private:
        string the_Word;
        string the_File;
        int the_Frequency;

        vector<string> wordInVec;
        map<string,int> docANDfreq;
        vector<string> word_Index;
};


#endif // WORD_H
