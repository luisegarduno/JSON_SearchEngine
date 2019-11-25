#ifndef PARSER_H
#define PARSER_H

#include <string>
//#include <cstdio>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "AVLTree.h"
#include <unordered_set>
#include "porter2_stemmer.h"
#include "rapidjson/document.h"
#include <experimental/iterator>
#include <experimental/filesystem>
#include "rapidjson/filereadstream.h"

using namespace rapidjson;

namespace filesystem = std::experimental::filesystem;

using std::copy;
using std::fopen;
using std::string;
using std::ifstream;
using std::remove_if;
using std::istringstream;
using std::unordered_set;
using std::ostream_iterator;

class Parser{
    private:
        AVLTree<string> * index;

        int totNumNodes;
        int totDocsFound;
        int totNumValidDocs;
        int totNumOfApperances;

        string currentWord;

        void setFileNames(string);
        void parseCurrentFile(string);
        void setTotalNumberOfNodes();

        unordered_set<string> stopWords;

    public:
        Parser(char* []);
        void parseJSON(string);
        string stripHTML(string);
        string split2Word(string);
        string& makeLowerCase(string&);
        string removeStopWords(string&);
        bool checkIfstopWord(string&);
        bool fileIsValidFlag;
        int getTotNumNodes();
        int getTotDocsFound();
        int getTotNumOfAppearances();
};

#endif // PARSER_H
