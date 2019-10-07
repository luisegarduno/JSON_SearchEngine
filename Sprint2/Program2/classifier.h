#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "dsstring.h"
#include "dsvector.h"

#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;
using std::endl;
using std::getline;
using std::flush;


class Classifier{

    private:
        DSVector<DSString> rowNumber;
        DSVector<DSString> tweetID;
        DSVector<DSString> username;
        DSVector<DSString> words;
        char * buffer;

    public:
        Classifier();
        Classifier(char *[]);
        void classifierTrain(DSString&);
        void classifierTest(DSString&);
        ~Classifier();
};

#endif // CLASSIFIER_H
