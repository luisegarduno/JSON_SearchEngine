#include "maintenance.h"
#include "ui_maintenance.h"

Maintenance::Maintenance(QWidget *parent) : QDialog(parent),  steps(0), ui(new Ui::Maintenance), totalNumberOfFiles(0), totalNumOfWords(0.0), totalNumOfValidDocs(0) {
    ui->setupUi(this);

    {
        ifstream inputFile("../ProgramParser/StopWords.txt");        // https://countwordsfree.com/stopwords
        string stopWordString;

        while(inputFile >> stopWordString){
        stopWordString.erase(remove_if(stopWordString.begin(),stopWordString.end(), [] (char it){
                return !(it == '\'' || (it >= 'a' && it <= 'z'));
                }), stopWordString.end());
            lowerCase(stopWordString);
            stopWords.emplace(stopWordString);
        }
    }
}

void Maintenance::on_MainMenu_Button_clicked(){
    // Closes current window.
    this->close();
}

void Maintenance::on_ClearFile_Button_clicked(){
    QMessageBox::StandardButton confirmation;

    // Warning window is displayed to confirm user selection
    confirmation = QMessageBox::warning(this, "Clear", "Are you sure?", QMessageBox::Yes| QMessageBox::No);

    // If user selects "Yes", AVL Tree & Hash Table & ~possibly~ index file is cleared
    if(confirmation == QMessageBox::Yes){
        if(words.size() != 0){
            words.clear();
        }
        QMessageBox::information(this, "Clear", "Index has been cleared");
        this->close();
    }

    else{

    }
}

void Maintenance::on_AddFolder_Button_clicked(){
    QString file_name;
    // Opens local file directory, user is able to navigate to select desired folder
    // file_name = QFileDialog::getExistingDirectory(this, "Open Folder", QDir::homePath());
    file_name = QFileDialog::getExistingDirectory(this,"Open Folder","/home/student/Desktop/MyProjects/CSE2341-F19-Luis-Garduno/FinalProject/build-FinalProgram-Desktop_Qt_5_10_0_GCC_64bit-Debug");

    // If no file was selected, display warning message
    if(file_name == ""){
        QString noFile = "Nothing was selected!\n";
        QString tryAgain = "Please select valid path to a folder";
        QMessageBox::warning(this,"Error", noFile + tryAgain);
    }
    else{

        // QString is converted and saved as a standard string
        string fileName = file_name.toStdString();
        int totalNumberOfFiles = getTotalNumberOfFiles(fileName);
        //cout << "Done counting total number of files: " << totalNumberOfFiles << endl;
        pd = new QProgressDialog("Selected Directory: " + parsePathName(fileName), "Cancel", 0, totalNumberOfFiles);
        pd->setWindowTitle("Parsing Index");
        connect(pd,&QProgressDialog::canceled, this, &Maintenance::cancel);

        // A vector is created containing every path name for each file in folder
        setFileLocations(fileName);

        QMessageBox::information(this, "Complete", "Index has been parsed succesfully");
    }
}

void Maintenance::parse(string fileName){
    Document currentDocument = parseJSON(fileName);

    string caseTitle, html_Section, htmlLawbox_Section, plainText_Section;

    int documentID = currentDocument["id"].GetInt();

    caseTitle = currentDocument["absolute_url"].GetString();
    getCaseTitle(caseTitle);

    if(currentDocument.HasMember("html") && currentDocument["html"].IsString()){
        html_Section = currentDocument["html"].GetString();
        parseHTML(html_Section);
        split2Word(html_Section);
    }

    if(currentDocument.HasMember("html_lawbox") && currentDocument["html_lawbox"].IsString()){
        htmlLawbox_Section = currentDocument["html_lawbox"].GetString();
        parseHTML(htmlLawbox_Section);
        split2Word(htmlLawbox_Section);
    }

     plainText_Section = currentDocument["plain_text"].GetString();
     split2Word(plainText_Section);

    if(html_Section != "" && isValidDoc){

        stringInMap tempMap;
        countWords(html_Section,tempMap);
        countWords(htmlLawbox_Section,tempMap);
        countWords(plainText_Section,tempMap);

        typedef std::function<bool(pair<string, int>, pair<string, int>)> Comparator;

        Comparator compFunctor =
                    [](pair<string, int> elem1, pair<string,int> elem2)
                    {
                        return elem1.second < elem2.second;
                    };
        set<pair<string, int>, Comparator> setOfWords(tempMap.begin(), tempMap.end(), compFunctor);

        for (pair<string, int> aIterator : setOfWords){
                printf("%d[%s]: %d\n", documentID, aIterator.first.c_str(), aIterator.second);
                //cout << documentID << element.first << " :: " << element.second << endl;
        }


        //for(stringInMap::iterator aIterator = tempMap.begin(); aIterator != tempMap.end(); ++aIterator){
          //  printf("%d[%s]: %d\n", documentID, aIterator->first.c_str(), aIterator->second);
        //}



        //printf("DocID: %d\n", documentID);
        //printf("case_title: %s\n", caseTitle.c_str());
        //printf("HTML: %s\n", html_Section.c_str());
        //printf("HTML_Lawbox: %s\n", htmlLawbox_Section.c_str());
        //printf("Plain Text: %s\n\n", plainText_Section.c_str());
    }
}

void Maintenance::countWords(string section, stringInMap& theMap){
    string aString;
    istringstream aStream(section);
    while(getline(aStream,aString,' ')){
        ++theMap[aString];
    }

}

Document Maintenance::parseJSON(string fileName){
    FILE* myFile = fopen(fileName.c_str() ,"rb"); // non-Windows use "r"

    char * readBuffer = new char[65536];
    FileReadStream readFile(myFile, readBuffer, 65536);

    Document currentDocument;
    currentDocument.ParseStream(readFile);
    fclose(myFile);

    delete [] readBuffer;

    return currentDocument;
}

string& Maintenance::parseHTML(string& section){
    for(size_t start = 0; start < section.size(); start++){
        if(section[start] == '<'){
            size_t end = start;

            while(section[end] != '>' && end < section.size()){
                end++;
            }
            section.erase(start, end - start + 1);
            start--;
        }
    }
    return section;
}

QString Maintenance::parsePathName(string section){
    for(size_t start = 0; start < section.size(); start++){
        if(section[start] == '/'){
            size_t end = start + 1;

            while(section[end] != '/' && end < section.size()){
                end++;
                if(end == section.size()){
                    return QString::fromStdString(section);
                }
            }
            section.erase(start, end - start);
            start--;
        }
    }

    return QString::fromStdString(section);
}


string& Maintenance::split2Word(string& section){
    string aWord;
    int flagCount = 0;
    istringstream stream(section);

    while(stream >> aWord){
        removeStopWords(aWord);

        if(aWord == "certiorari" || aWord == "petition"){
            flagCount = 1;
            words.insert(aWord);
        }
        else if((aWord == "denied" || aWord == "for") && flagCount == 1){
            if(aWord == "denied"){
                words.clear();
                isValidDoc = false;
                section = "";
                return section;
            }
            words.insert(aWord);
            flagCount = 2;
        }
        else if(aWord == "for" && flagCount == 2){
            words.insert(aWord);
            flagCount = 3;
        }
        else if(aWord == "reahearing" && flagCount == 3){
            words.clear();
            isValidDoc = false;
            section = "";
            return section;
        }

        else{
            flagCount = 0;
            isValidDoc = true;
            words.insert(aWord);
        }
    }


    if(isValidDoc == true){
        unordered_set<string>::iterator theIterator;
        string tempWord;
        section = "";
        for(theIterator = words.begin(); theIterator != words.end(); theIterator++){
            if((*theIterator).size() != 0){
                tempWord = *theIterator;
                Porter2Stemmer::stem(tempWord);
                section += tempWord + " ";
                ++totalNumOfWords;
            }
        }
        return section;
    }
    return section;

}

string& Maintenance::getCaseTitle(string& absolute_string){
    string caseTitle;
    string opponent1;
    string opponent2;
    istringstream stream1(absolute_string);

    for(int i = 0; i < 4; i++){
        getline(stream1,opponent1,'/');
    }

    opponent1[0] = char(toupper(opponent1[0]));

    istringstream stream2(opponent1);
    while(getline(stream2,opponent2,'-')){
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
    absolute_string = caseTitle;

    return absolute_string;
}

string& Maintenance::removeStopWords(string& word){

    if(word.size() == 0){
        return word;
    }

    lowerCase(word);

    word.erase(remove_if(word.begin(),word.end(), [] (char it){
        return !((it >= 'a' && it <= 'z') || it == '\'');
    }), word.end());

    if(word.size() == 0){
        return word;
    }

    if(stopWords.count(word) > 0){
        word = "";
        return word;
    }

    return word;
}

string& Maintenance::lowerCase(string& word){
    for(size_t aSize = 0; aSize < word.size(); aSize++){
        word[aSize] = char(tolower(word[aSize]));
    }
    return word;
}

bool Maintenance::isStopWord(string& word){
    if(word.size() == 0){
        return false;
    }

    return stopWords.count(word) > 0;
}

int Maintenance::getTotalNumberOfFiles(string& fileName){

    filesystem::directory_iterator end;
    for(filesystem::directory_iterator theIterator(fileName) ; theIterator != end; ++theIterator){
        ++totalNumberOfFiles;
    }

    return totalNumberOfFiles;
}

void Maintenance::setFileLocations(string& fileName){

    pd->setValue(steps);

    filesystem::directory_iterator end;
    for(filesystem::directory_iterator theIterator(fileName) ; theIterator != end; ++theIterator){

        QCoreApplication::processEvents();
        // directory iterator is first converted to a path
        filesystem::path dirToPath = *theIterator;
        // path directory is converted to a string
        string pathToString = dirToPath.string();

        parse(pathToString);

        if(isValidDoc == true){
            // string is appended to end of vector
            allFileLocations.push_back(pathToString);

            // string is parsed to filename, and added to vector
            totalNumOfValidDocs++;
        }
        steps++;
        pd->setValue(steps);
    }
    //avgNumOfWordsPerOpinion /= totalNumOfValidDocs;
}

vector<string> Maintenance::getFileLocations(){
        return allFileLocations;
}

int Maintenance::getTotalNumValidDocs(){
    if(totalNumOfValidDocs > 0){
        return totalNumOfValidDocs;
    }
    return 0;
}

double Maintenance::getTotalNumOfWords(){
    if(totalNumOfWords > 0.0){
        return totalNumOfWords;
    }

    return 0;
}

void Maintenance::cancel(){
    theTimer->stop();
}

// Destructor
Maintenance::~Maintenance(){
    delete ui;
}


