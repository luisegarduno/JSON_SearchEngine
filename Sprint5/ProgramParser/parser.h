#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <string>
#include <vector>
#include <cstdio>
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
using std::cout;
using std::endl;
using std::list;
using std::fopen;
using std::vector;
using std::string;
using std::ifstream;
using std::remove_if;
using std::istringstream;
using std::unordered_set;
using std::ostream_iterator;

class Parser{
    private:
        AVLTree<string> index;
        size_t totNumNodes;
        string currentWord;
        int totDocsFound;
        int totNumOfApperances;
        void setFileNames(string);
        list<string> setFileLocations(string);

        unordered_set<string> stopWords;
        list<string> fileNamesOnly;
        list<string> allFileLocations;

    public:
        Parser();
        Parser(char* []);
        void parseJSON(string);
        string stripHTML(string);
        string split2Word(string);
        string& makeLowerCase(string&);
        string removeStopWords(string&);
        bool checkIfstopWord(string&);

        void printFileNames();
        void printStopWords(unordered_set<string> const&);
        size_t getTotNumNodes();
        int getTotDocsFound();
        int getTotNumOfAppearances();
        string getCaseTitle(string);
        list<string> getFileLocations();
        list<string> getFileNamesOnly();
};

#endif // PARSER_H
