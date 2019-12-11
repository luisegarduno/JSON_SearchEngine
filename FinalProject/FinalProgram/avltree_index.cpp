#include "avltree_index.h"

AvlTree_Index::AvlTree_Index(){
}

void AvlTree_Index::load_Index(){
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

            word thisWord;

            while(theLine != "-->"){
                theIndex_Loader >> theLine;
                if(theLine == "-->" || theIndex_Loader.eof()){
                    break;
                }
                theFile = theLine;

                theIndex_Loader >> theLine;
                theFrequency = theLine;

                //cout << " " << theFile << " " << theFrequency;

                thisWord.setWord(theWord);
                thisWord.addDocumentName(theFile);
                thisWord.setFrequencyForDoc(theFile,std::stoi(theFrequency));

                //cout << theWord << ", " << theFile << " : " << theFrequency << endl;
                index.insert(thisWord);
            }
            //cout << endl;
        }
    }
    theIndex_Loader.close();
}

word& AvlTree_Index::search_Index(word& thisWord){
    if(!index.contains(thisWord)){
        throw std::out_of_range("Word not found in Index");
    }
    else{
        return index.searchAvl(thisWord);
    }
}

void AvlTree_Index::insert_In_Index(word& thisWord, string& thisDoc){
    if(!index.contains(thisWord)){
        index.insert(thisWord);
    }
    else{
        if(index.searchAvl(thisWord).checkMap(thisDoc)){
            index.searchAvl(thisWord).newDocumentName(thisDoc);
        }
        else{
            index.searchAvl(thisWord).addDocumentName(thisDoc);
        }
    }
}

void AvlTree_Index::print_Index(){
    index.printTree();
}

void AvlTree_Index::clear_Index(){
    index.makeEmpty();
}

AvlTree_Index::~AvlTree_Index(){
}

