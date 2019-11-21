#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <experimental/filesystem>

namespace filesystem = std::experimental::filesystem;

using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::string;

class Parser{
    private:
        int totNumFiles;
        int totNumWordAppears;
        int totNumOfApperances;

    public:
        Parser();
        Parser(int,char* []);
        void addFolder();
        void removeStopWords();
        void stem(string);
};

#endif // PARSER_H
