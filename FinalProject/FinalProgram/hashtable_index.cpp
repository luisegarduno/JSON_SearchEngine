#include "hashtable_index.h"

HashTable_Index::HashTable_Index(){
}

void HashTable_Index::load_Index(){
    ifstream theIndex_Loader("../Index.txt");

    string theLine;
    string theWord;
    string theFile;
    string theFrequency;

    while(theIndex_Loader >> theLine){
        if(theLine == "-->"){
            continue;
        }
        else{
            theWord = theLine;
            cout << "--> " << theWord;



            while(theLine != "-->"){
                theIndex_Loader >> theLine;
                if(theLine == "-->" || theIndex_Loader.eof()){
                    break;
                }
                theFile = theLine;

                theIndex_Loader >> theLine;
                theFrequency = theLine;

                cout << " " << theFile << " " << theFrequency;

                word thisWord;

                thisWord.the_Word = theWord;
                thisWord.the_File = theFile;
                thisWord.the_Frequency = std::stoi(theFrequency);

                index.insert(theWord,thisWord);
            }

            cout << endl;
        }
    }

    theIndex_Loader.close();
}

word& HashTable_Index::search_Index(word& thisWord){
    if(!index.contains(thisWord.the_Word)){
        throw std::out_of_range("Word not found in Index");
    }
    else{
        return index.searchKey(thisWord.the_Word);
    }
}

void HashTable_Index::print_Index(){
    index.print();
}

void HashTable_Index::insert_In_Index(word& thisWord, string& thisString){
    if(!index.contains(thisWord.the_Word)){
        index.insert(thisWord.the_Word,thisWord);
    }
    else{
        if(index.searchKey(thisWord.the_Word).docANDFreq.count(thisString)){
            index.searchKey(thisWord.the_Word).docANDFreq[thisString]++;
        }
        else{
            index.searchKey(thisWord.the_Word).docANDFreq[thisString] = 1;
        }
    }
}

void HashTable_Index::clear_Index(){
    index.clear();
}

HashTable_Index::~HashTable_Index(){
}

