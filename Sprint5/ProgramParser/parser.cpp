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

        allFileLocations = setFileLocations(file_name);
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
    // 1. Parse a JSON text string to a document.
        FILE* fp = fopen(pathString.c_str(), "rb"); // non-Windows use "r"

        char readBuffer[65536];
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));

        Document document;
        document.ParseStream(is);
        fclose(fp);

    // 2. Access values in document.

        printf("\nAccess values in document:\n");
        printf("\tDocument ID: %d\n",document["id"].GetInt());
        printf("\tAuthor: %s\n", document["author_str"].GetString());
        printf("HTML: %s\n", document["html"].GetString());
        printf("HTML_Lawbox: %s\n", document["html_lawbox"].GetString());
        printf("Plain_Text: %s\n", document["plain_text"].GetString());

    // 3. Modify values in document.

        {
            string htmlString = document["html"].GetString();
            cout << "String size: " << htmlString.size() << endl;
            for(unsigned int start = 0; start < htmlString.size(); start++){
                cout << "HERE[" << start << "]: " << htmlString[start] << endl;
                cout << "\tHTML: " << htmlString << endl;
                if(htmlString[start] == '<'){
                    unsigned int end = start;

                    while(htmlString[end] != '>' && end < htmlString.size()){
                        end++;
                    }
                    htmlString.erase(start, end - start + 1);
                    start--;
                }
            }

            cout << "FINAL: " << htmlString << endl;
            rapidjson::SizeType theSize = rapidjson::SizeType(htmlString.size());
            document["html"].SetString(htmlString.c_str(), theSize);
        }

// 4. Stringify JSON

        printf("\nModified JSON with reformatting:\n");
        StringBuffer sb;
        PrettyWriter<StringBuffer> writer(sb);
        document.Accept(writer);    // Accept() traverses the DOM and generates Handler events.
        puts(sb.GetString());
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
