#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H

#include <string>
#include <iostream>

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
        virtual void search_Index() = 0;
        virtual void clear_Index() = 0;

    private:
        string index_File;
};

#endif // INDEXINTERFACE_H
