#include "parser.h"

Parser::Parser() : totNumFiles(0), totNumWordAppears(0), totNumOfApperances(0){
}

Parser::Parser(char* argv[]) : totNumFiles(0), totNumWordAppears(0), totNumOfApperances(0){
    string file_name;
    file_name = argv[1];

    // If no file was selected, display warning message
    if(file_name == ""){
        string noFile = "Nothing was selected!\n";
        string tryAgain = "Please select valid path to a folder";
        cout << "Error: " << noFile + tryAgain << endl;
    }
    else{
        // Information window is displayed containing selected folder
        cout << "File Selected: " <<  file_name << endl;

        ifstream inputFile("StopWords.txt");
        string stopWordString;

        while(inputFile >> stopWordString){
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
        totNumFiles++;
    }
    return allFileLocations;
}

void Parser::parseJSON(string pathString){
        FILE* fp = fopen(pathString.c_str(), "rb"); // non-Windows use "r"

        char readBuffer[65536];
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));

        Document document;
        document.ParseStream(is);
        fclose(fp);

        int documentID = document["id"].GetInt();
        string caseTitle = getCaseTitle(document["absolute_url"].GetString());
        string author = document["author_str"].GetString();

        string htmlString = stripHTML(document["html"].GetString());
        htmlString = split2Word(htmlString);

        string htmlLawbox = stripHTML(document["html_lawbox"].GetString());
        htmlLawbox = split2Word(htmlLawbox);

        string plainString = stripHTML(document["plain_text"].GetString());
        plainString = split2Word(plainString);

        if(htmlString != ""){
            cout << "\nCase[" << totNumFiles + 1 << "]: " << caseTitle;
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
                index.insert(rmStopWord);
                newString += rmStopWord + "|";
            }
        }
    }

    return newString;
}

//string Parser::stem(string& aValue){

//}

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

size_t Parser::getSizeOfFolder(){

    if(totNumFiles > 0){
        return totNumFiles;
    }

    return 0;
}

void Parser::printFileNames(){
    int fileCounter = 0;
    for(auto const &v : fileNamesOnly){
        cout << "File[" << ++fileCounter << "]: " << v << "\n" ;
    }
}
