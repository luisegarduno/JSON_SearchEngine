#include "avltreeindex.h"

AvlTreeIndex::AvlTreeIndex(){

}

void AvlTreeIndex::load_Index(){
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

                //index.insert(thisWord);
            }
        }

    }

    theIndex_Loader.close();

}

void AvlTreeIndex::search_Index(){

}

void AvlTreeIndex::insert_In_Index(new_word_obj& thisWord, string& thisString){

}

void AvlTreeIndex::print_Index(){
    //index.printTree();
}

void AvlTreeIndex::clear_Index(){
    index.makeEmpty();
}

AvlTreeIndex::~AvlTreeIndex(){
}
