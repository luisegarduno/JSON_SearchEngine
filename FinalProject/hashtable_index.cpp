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
            //cout << "--> " << theWord;
            word thisWord(theWord);



            while(theLine != "-->"){
                theIndex_Loader >> theLine;
                if(theLine == "-->" || theIndex_Loader.eof()){
                    break;
                }
                theFile = theLine;

                theIndex_Loader >> theLine;
                theFrequency = theLine;

                thisWord.setWord(theWord);
                thisWord.addDocumentName(theFile);
                thisWord.setFrequencyForDoc(theFile,std::stoi(theFrequency));

            }
            index.insert(theWord,thisWord);
        }
    }

    theIndex_Loader.close();
}

word& HashTable_Index::search_Index(word& thisWord){
    if(!index.contains(thisWord.getWord())){
        throw std::out_of_range("Word not found in Index");
    }
    else{
        return index.searchKey(thisWord.getWord());
    }
}

void HashTable_Index::print_Index(){
    index.print();
}

void HashTable_Index::insert_In_Index(word& thisWord, string& thisString){
    if(!index.contains(thisWord.getWord())){
        index.insert(thisWord.getWord(),thisWord);
    }
    else{
        if(index.searchKey(thisWord.getWord()).checkMap(thisString)){
            index.searchKey(thisWord.getWord()).newDocumentName(thisString);
        }
        else{
            index.searchKey(thisWord.getWord()).addDocumentName(thisString);
        }
    }
}

void HashTable_Index::clear_Index(){
    index.clear();
}

HashTable_Index::~HashTable_Index(){
}

