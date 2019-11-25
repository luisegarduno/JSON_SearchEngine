#ifndef PARSER_H
#define PARSER_H

#include <string>
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

        // Current word being searched
        string currentWord;

        // Total number of nodes in AVLTree
        int totNumNodes;

        // Total number of valid documents that
        // were NOT denied
        int totNumValidDocs;

        // Total number of documents the search
        // word was found in
        int totDocsFound;

        // Total number of times word was found
        // through all valid documents
        int totNumOfApperances;

        // Stores all StopWords from provided StopWords.txt
        // into an `unordered_set` for fast retrieval
        unordered_set<string> stopWords;

        // Opens up given Directory path and iterates
        // through folder to get all file names
        void parseCurrentFile(filesystem::path);

        // Iterates through AVLTree, to count total
        // number of nodes in index
        void setTotalNumberOfNodes();

    public:
        // Default constructor contains command line arguments
        // to initialize the 1)Directory Path and 2) word being searched
        Parser(char* []);

        // Uses path name to open up JSON file, the doing the following:
        // 1st) <rapidjson> library is used to parse JSON file properly.
        // 2nd) stripHTML member function is called to remove all HTML from section
        // 3rd) split2Word, which aside from splitting a section to individual words,
        //  it additionally makes every word lowercase & removes stopwords, & stems words
        void parseJSON(filesystem::path);

        // iteratates through sections and calls `removeStopWords` and stems each words
        // ONLY from Valid Documents
        void split2Word(string);

        // Simply removes all characters between characters '<' and '>' from section
        string stripHTML(string);

        // Simply makes a word lowercase
        string& makeLowerCase(string&);

        // checks if word is a StopWord, and returns word if it isn't
        // or returns empty string if it is a stop word
        string& removeStopWords(string&);

        // check if string paramater is within the StopWords.txt file
        bool checkIfstopWord(string&);

        // used as a flag, to let program know when the file is invalid
        // make `fileIsValidFlag` equal to false;
        bool fileIsValidFlag;

        // Returns total number of nodes in index
        int getTotNumNodes();

        // Returns total number of documents word was
        // found in
        int getTotDocsFound();

        // Returns total number of times the given word
        // was found through all valid documents
        int getTotNumOfAppearances();
};

#endif // PARSER_H
