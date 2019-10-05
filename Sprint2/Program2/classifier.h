#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "dsstring.h"
#include "dsvector.h"


class Classifier{

    private:
        int rowNum;
        int tweetID;
        DSString user;
        DSVector<DSString> words;


    public:
        Classifier();
        Classifier(char * arv[]);
        ~Classifier();
};

#endif // CLASSIFIER_H
