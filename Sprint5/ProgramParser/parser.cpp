#include "parser.h"

Parser::Parser() : totNumNodes(0), totDocsFound(0), totNumOfApperances(0){
}

Parser::Parser(char* argv[]) : totNumNodes(0), totDocsFound(0), totNumOfApperances(0){
    string file_name;
    file_name = argv[1];
    currentWord = argv[2];

    currentWord.erase(remove_if(currentWord.begin(),currentWord.end(), [] (char it){
        return !((it >= 'a' && it <= 'z') || it == '\'');
    }), currentWord.end());
    makeLowerCase(currentWord);
    Porter2Stemmer::stem(currentWord);

    // If no file was selected, display warning message
    if(file_name == ""){
        string noFile = "Nothing was selected!\n";
        string tryAgain = "Please select valid path to a folder";
        cout << "Error: " << noFile + tryAgain << endl;
    }
    else{
        // Information window is displayed containing selected folder
        cout << "File Selected: " <<  file_name << endl;

        ifstream inputFile("StopWords.txt");        // https://countwordsfree.com/stopwords
        string stopWordString;

        while(inputFile >> stopWordString){
            stopWordString.erase(remove_if(stopWordString.begin(),stopWordString.end(), [] (char it){
                return !((it >= 'a' && it <= 'z') || it == '\'');
            }), stopWordString.end());
            makeLowerCase(stopWordString);
            stopWords.emplace(stopWordString);
        }
        allFileLocations = setFileLocations(file_name);
        index.printTree();
    }
}

list<string> Parser::setFileLocations(string fileName){
    list<string> allFileLocations;

    filesystem::directory_iterator end;
    for(filesystem::directory_iterator theIterator(fileName) ; theIterator!= end; ++theIterator){
        // directory iterator is first converted to a path
        filesystem::path dirToPath = *theIterator;

        // path directory is converted to a string
        string pathToString = dirToPath.string();

        parseJSON(pathToString);

        // string is appended to end of vector
        allFileLocations.push_back(pathToString);

        // string is parsed to filename, and added to vector
        setFileNames(pathToString);
    }
    return allFileLocations;
}

void Parser::parseJSON(string pathString){
        FILE* fp = fopen(pathString.c_str() ,"rb"); // non-Windows use "r"

        char readBuffer[65536];
        FileReadStream is(fp, readBuffer, 65536);

        Document document;// document;
        document.ParseStream(is);
        fclose(fp);


        int documentID = document["id"].GetInt();

        string caseTitle = getCaseTitle(document["absolute_url"].GetString());
        string author = document["author_str"].GetString();
        string htmlString,htmlLawbox;
        if(document.HasMember("html") && document["html"].IsString()){
            htmlString = stripHTML(document["html"].GetString());
            htmlString = split2Word(htmlString);
        }

        if(document.HasMember("html_lawbox") && document["html_lawbox"].IsString()){
            htmlLawbox = stripHTML(document["html_lawbox"].GetString());
            htmlLawbox = split2Word(htmlLawbox);
        }

        string plainString = stripHTML(document["plain_text"].GetString());
        plainString = split2Word(plainString);


        if(htmlString != ""){
            cout << "\nCase[" << ++totNumNodes << "]: " << caseTitle;
            cout << " ********************************************************************" << endl;
            cout << "-->Document ID: " << documentID << endl;
            cout << "-->Author: " << author << endl;
            cout << "-->HTML: " <<  htmlString << endl;
            cout << "-->HTML_Lawbox: " << htmlLawbox << endl;
            cout << "-->Plain_Text: " << plainString << endl;
        }


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

string Parser::getCaseTitle(string absolute_string){
    string caseTitle;
    string opponent1;
    string opponent2;
    istringstream ss(absolute_string);

    for(int i = 0; i < 4; i++){
        getline(ss,opponent1,'/');
    }

    opponent1[0] = char(toupper(opponent1[0]));

    istringstream ss2(opponent1);
    while(getline(ss2,opponent2,'-')){
        if(opponent2 == "v"){
            caseTitle += "Vs.";
        }

        else{
            opponent2[0] = char(toupper(opponent2[0]));
            caseTitle += opponent2;
        }

        caseTitle += " ";
    }

    caseTitle.erase(caseTitle.size() - 1);

    return caseTitle;
}

void Parser::printStopWords(unordered_set<string> const& iterator){
    copy(iterator.begin(), iterator.end(), ostream_iterator<string>(cout,"|"));
}

string Parser::removeStopWords(string& aValue){
    string parsedString = aValue;

    if(parsedString.size() == 0){
        return parsedString;
    }

    makeLowerCase(parsedString);

    parsedString.erase(remove_if(parsedString.begin(),parsedString.end(), [] (char it){
        return !((it >= 'a' && it <= 'z') || it == '\'');
    }), parsedString.end());

    if(parsedString.size() == 0){
        return parsedString;
    }

    if(stopWords.count(parsedString) > 0){
        return "";
    }

    return parsedString;
}

string Parser::split2Word(string htmlString){
    istringstream stream(htmlString);
    string word;
    string newString;
    int count = 0;
    bool wordFoundInDoc = false;
    while(stream >> word){
        string rmStopWord = removeStopWords(word);

        if(rmStopWord == "certiorari" || rmStopWord == "petition"){
            count = 1;
        }
        else if((rmStopWord == "denied" || rmStopWord == "for") && count == 1){
            newString = "";
            return newString;
        }
        else{
            count = 0;
            if(rmStopWord.size() != 0){
                Porter2Stemmer::stem(rmStopWord);
                if(rmStopWord == currentWord){
                    ++totNumOfApperances;
                    if(wordFoundInDoc == false){
                        ++totDocsFound;
                        wordFoundInDoc = true;
                    }
                }
                index.insert(rmStopWord);
                newString += rmStopWord + "|";
            }
        }
    }

    return newString;
}

string& Parser::makeLowerCase(string& aWord){
    for(size_t aSize = 0; aSize < aWord.size(); aSize++){
        aWord[aSize] = char(tolower(aWord[aSize]));
    }
    return aWord;
}

bool Parser::checkIfstopWord(string& word){
    string tempWord = word;

    if(tempWord.size() == 0){
        return false;
    }

    return stopWords.count(tempWord) > 0;
}


void Parser::setFileNames(string fileName){
    fileName.erase(0,133);

    fileNamesOnly.push_back(fileName);
}

// returns vector of strings containing file locations
list<string> Parser::getFileNamesOnly(){
    return fileNamesOnly;
}

// returns vector of strings containing file locations
list<string> Parser::getFileLocations(){
    return allFileLocations;
}

size_t Parser::getTotNumNodes(){

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

void Parser::printFileNames(){
    int fileCounter = 0;
    for(auto const &v : fileNamesOnly){
        cout << "File[" << ++fileCounter << "]: " << v << "\n" ;
    }
}