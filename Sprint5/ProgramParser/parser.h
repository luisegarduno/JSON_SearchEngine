#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include "AVLTree.h"
#include <experimental/filesystem>

namespace filesystem = std::experimental::filesystem;

using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::string;

class Parser{
    private:
        size_t totNumFiles;
        int totNumWordAppears;
        int totNumOfApperances;
        void setFileNames(string);
        list<string> setFileLocations(string);

        list<string> fileNamesOnly;
        list<string> allFileLocations;

    public:
        Parser();
        Parser(char* []);
        void addFolder(string);
        void removeStopWords();
        void stem(string);

        void printFileNames();
        size_t getSizeOfFolder();
        list<string> getFileLocations();
        list<string> getFileNamesOnly();
};

#endif // PARSER_H
