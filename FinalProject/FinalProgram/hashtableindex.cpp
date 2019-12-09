#include "hashtableindex.h"

HashTableIndex::HashTableIndex(){

}

void HashTableIndex::load_Index(){
    ifstream theIndex_Loader("Index.txt");

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
            //cout << "Word: " << theWord << endl;

            while(theLine != "-->"){
                theIndex_Loader >> theLine;
                if(theLine == "-->" || theIndex_Loader.eof()){
                    break;
                }
                theFile = theLine;

                theIndex_Loader >> theLine;
                theFrequency = theLine;

                //cout << "Word[" << theWord << "] : File[" << theFile << "] : Frequency[" << theFrequency << "]" << endl;

                new_word_obj thisWord;

                thisWord.the_Word = theWord;
                thisWord.the_File = theFile;
                thisWord.the_Frequency = std::stoi(theFrequency);

                index.insert(theWord, thisWord);

            }
        }

    }

    theIndex_Loader.close();
}

void HashTableIndex::search_Index(){

}

void HashTableIndex::print_Index(){
    index.print();
}

void HashTableIndex::insert_In_Index(new_word_obj& thisWord, string& thisString){

}

void HashTableIndex::clear_Index(){
    index.clear();
}

HashTableIndex::~HashTableIndex(){
}
