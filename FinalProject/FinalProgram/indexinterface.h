#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H

#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

struct new_word_obj{
    string the_Word;
    string the_File;
    int the_Frequency;
};

class IndexInterface{
    public:
        IndexInterface();
        virtual ~IndexInterface() = 0;
        virtual void load_Index() = 0;
        virtual void insert_In_Index(new_word_obj&, string&) = 0;
        virtual new_word_obj& search_Index(new_word_obj&) = 0;
        virtual void clear_Index() = 0;
        virtual void print_Index() = 0;

    private:
        string index_File;
};

#endif // INDEXINTERFACE_H
