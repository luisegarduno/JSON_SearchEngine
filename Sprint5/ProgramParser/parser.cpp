#include "parser.h"

Parser::Parser(char* argv[]) : totNumNodes(0), totDocsFound(0), totNumOfApperances(0){
    filesystem::path file_name = argv[1];
    currentWord = argv[2];
    fileIsValidFlag = true;
    index = new AVLTree<string>;

    currentWord.erase(remove_if(currentWord.begin(),currentWord.end(),[] (char it){
                                    return !((it >= 'a' && it <= 'z') || it == '\''); }),
                      currentWord.end()
                      );

    makeLowerCase(currentWord);
    Porter2Stemmer::stem(currentWord);

    // If no file was selected, display warning message
    if(file_name == ""){
        cout << "Directory Error: Invalid path to a folder, exiting..." << endl;
        exit(EXIT_FAILURE);
    }

    else{
        ifstream inputFile("StopWords.txt");        // https://countwordsfree.com/stopwords
        string stopWordString;

        while(inputFile >> stopWordString){
            stopWordString.erase(remove_if(stopWordString.begin(),stopWordString.end(), [] (char it){
                return !(it == '\'' || (it >= 'a' && it <= 'z'));
            }), stopWordString.end());
            makeLowerCase(stopWordString);
            stopWords.emplace(stopWordString);
        }
        parseCurrentFile(file_name);
        setTotalNumberOfNodes();
        //index->printTree();
    }
}

void Parser::parseCurrentFile(filesystem::path fileName){
    filesystem::directory_iterator end;
    for(filesystem::directory_iterator theIterator(fileName) ; theIterator!= end; ++theIterator){
        // directory iterator is first converted to a path
        filesystem::path dirToPath = *theIterator;

        parseJSON(dirToPath);
    }
}

void Parser::parseJSON(filesystem::path pathString){
        FILE* fp = fopen(pathString.c_str() ,"rb"); // non-Windows use "r"

        char * readBuffer = new char[65536];
        FileReadStream is(fp, readBuffer, 65536);

        Document document;// document;
        document.ParseStream(is);
        fclose(fp);

        string htmlString,htmlLawbox;
        if(document.HasMember("html") && document["html"].IsString()){
            htmlString = stripHTML(document["html"].GetString());
            split2Word(htmlString);
        }

        if(document.HasMember("html_lawbox") && document["html_lawbox"].IsString()){
            htmlLawbox = stripHTML(document["html_lawbox"].GetString());
            split2Word(htmlLawbox);
        }

        string plainString = stripHTML(document["plain_text"].GetString());
        split2Word(plainString);


        if(htmlString != "" && fileIsValidFlag){
            ++totNumValidDocs;
        }

        delete [] readBuffer;
}

string Parser::stripHTML(string htmlString){
    for(size_t start = 0; start < htmlString.size(); start++){
        if(htmlString[start] == '<'){
            size_t end = start;

            while(htmlString[end] != '>' && end < htmlString.size()){
                end++;
            }
            htmlString.erase(start, end - start + 1);
            start--;
        }
    }
    return htmlString;
}

string& Parser::removeStopWords(string& aValue){

    if(aValue.size() == 0){
        return aValue;
    }

    makeLowerCase(aValue);

    aValue.erase(remove_if(aValue.begin(),aValue.end(), [] (char it){
        return !((it >= 'a' && it <= 'z') || it == '\'');
    }), aValue.end());

    if(aValue.size() == 0){
        return aValue;
    }

    if(stopWords.count(aValue) > 0){
        aValue = "";
        return aValue;
    }

    return aValue;
}

void Parser::split2Word(string htmlString){
    istringstream stream(htmlString);
    string word;
    int count = 0;
    bool wordFoundInDoc = false;
    vector<string> listOfWords;
    while(stream >> word){
        removeStopWords(word);

        if(word == "certiorari" || word == "petition"){
            count = 1;
        }
        else if((word == "denied" || word == "for") && count == 1){
            if(word == "denied"){
                fileIsValidFlag = false;
                break;
            }
            count = 2;
        }
        else if(word == "for" && count == 2){
            fileIsValidFlag = false;
            break;
        }
        else{
            count = 0;
            fileIsValidFlag = true;
            listOfWords.push_back(word);
        }
    }

    if(fileIsValidFlag == true){
        for(size_t vecCount = 0; vecCount < listOfWords.size(); vecCount++){
            if(listOfWords[vecCount].size() != 0){
                Porter2Stemmer::stem(listOfWords[vecCount]);
                if(listOfWords[vecCount] == currentWord){
                    ++totNumOfApperances;
                    if(wordFoundInDoc == false){
                        ++totDocsFound;
                        wordFoundInDoc = true;
                    }
                }
                index->insert(listOfWords[vecCount]);
            }
        }

    }
}

string& Parser::makeLowerCase(string& aWord){
    for(size_t aSize = 0; aSize < aWord.size(); aSize++){
        aWord[aSize] = char(tolower(aWord[aSize]));
    }
    return aWord;
}

bool Parser::checkIfstopWord(string& word){
    if(word.size() == 0){
        return false;
    }

    return stopWords.count(word) > 0;
}

void Parser::setTotalNumberOfNodes(){
    totNumNodes = index->getNumberOfNodes();
}


int Parser::getTotNumNodes(){
    if(totNumNodes > 0){
        return totNumNodes;
    }

    return 0;
}

int Parser::getTotDocsFound(){
    if(totDocsFound > 0){
        return totDocsFound;
    }

    return 0;
}

int Parser::getTotNumOfAppearances(){
    if(totNumOfApperances > 0){
        return totNumOfApperances;
    }

    return 0;
}
