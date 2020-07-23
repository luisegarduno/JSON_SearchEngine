#ifndef INDEX_INTERFACE_H
#define INDEX_INTERFACE_H

#include "word.h"
#include <fstream>
#include <iostream>



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
