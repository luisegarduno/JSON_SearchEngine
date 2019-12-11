#include "word.h"

word::word(){

}

word::word(string word){
    this->the_Word = word;
}

// Constructor
word::word(string aWord, string documentName){
    the_Word = aWord;
    docANDfreq[documentName] = 1;
}

word::word(const word& originalWord){
    the_Word = originalWord.the_Word;
    docANDfreq = originalWord.docANDfreq;
}

word& word::operator=(const word& originalWord){
    this->the_Word = originalWord.the_Word;
    this->docANDfreq = originalWord.docANDfreq;

    return *this;
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


