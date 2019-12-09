#ifndef INDEX_INTERFACE_H
#define INDEX_INTERFACE_H

#include <string>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

struct new_word_obj{
    string the_Word;
    string the_File;
    int the_Frequency;
};


class Index_Interface{
    public:
        Index_Interface() { }
        virtual void load_Index() = 0;
        virtual new_word_obj& search_Index(new_word_obj&) = 0;
        virtual void insert_In_Index(new_word_obj&, string&) = 0;
        virtual void clear_Index() = 0;
        virtual void print_Index() = 0;

        virtual ~Index_Interface() { }

    private:
};

#endif // INDEX_INTERFACE_H
