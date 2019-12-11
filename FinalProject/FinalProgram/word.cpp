#include "word.h"

word::word(){

}

void word::setWord(string aWord){
    this->the_Word = aWord;
}

string word::getWord() const{
    return the_Word;
}

void word::newDocumentName(string documentName){
    docANDfreq[documentName]++;
}

void word::addDocumentName(string documentName){
    docANDfreq[documentName] = 1;
}

map<string,int> word::getDocumentNames(){
    return docANDfreq;
}

void word::setFrequencyForDoc(string documentName,int theFrequency){
    docANDfreq[documentName] = theFrequency;
}

int word::getFrequencyForDoc(string documentName){
    return docANDfreq[documentName];

}

bool word::checkMap(string documentName){
    if(docANDfreq.count(documentName) > 0){
        return true;
    }
    else{
        return false;
    }

}

void word::printWord(){
    map<string,int>::iterator theIterator;
    cout << the_Word << " was found in : ";
    for(theIterator = docANDfreq.begin(); theIterator != docANDfreq.end(); theIterator++){
        cout << theIterator->first << ", ";
    }
}


