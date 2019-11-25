#include "maintenance.h"
#include "ui_maintenance.h"

Maintenance::Maintenance(QWidget *parent) :QDialog(parent), ui(new Ui::Maintenance){
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
            for(size_t count = 0; count < words.size(); count++){
                cout << words[count] << endl;
            }
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
    //file_name = QFileDialog::getExistingDirectory(this, "Open Folder", QDir::homePath());
    file_name = QFileDialog::getExistingDirectory(this,"Open Folder","/home/student/Desktop/MyProjects/CSE2341-F19-Luis-Garduno/FinalProject/build-FinalProgram-Desktop_Qt_5_10_0_GCC_64bit-Debug");

    // If no file was selected, display warning message
    if(file_name == ""){
        QString noFile = "Nothing was selected!\n";
        QString tryAgain = "Please select valid path to a folder";
        QMessageBox::warning(this,"Error", noFile + tryAgain);
    }
    else{
        // Information window is displayed containing selected folder
        QMessageBox::information(this, "File Selected", file_name);

        // QString is converted and saved as a standard string
        string fileName = file_name.toStdString();


        //parse(fileName);

        // A vector is created containing every path name for each file in folder
        allFileLocations = setFileLocations(fileName);
    }
}

void Maintenance::parse(string fileName){
    Document currentDocument = parseJSON(fileName);


    string html_Section, htmlLawbox_Section, plainText_Section;

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
        ++totalNumOfValidDocs;
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

void Maintenance::split2Word(string section){
    istringstream stream(section);
    string word;
    int flagCount = 0;
    //bool wordFoundInDoc = false;

    while(stream >> word){
        removeStopWords(word);

        if(word == "certiorari" || word == "petition"){
            flagCount = 1;
        }
        else if((word == "denied" || word == "for") && flagCount == 1){
            if(word == "denied"){
                isValidDoc = false;
                break;
            }
            flagCount = 2;
        }
        else if(word == "for" && flagCount == 2){
            isValidDoc = false;
            break;
        }
        else{
            flagCount = 0;
            isValidDoc = true;
            words.push_back(word);
        }
    }

    if(isValidDoc == true){
        for(size_t vecCount = 0; vecCount < words.size(); vecCount++){
            if(words[vecCount].size() != 0){
                Porter2Stemmer::stem(words[vecCount]);
                /*
                if(words[vecCount] == currentCorpus){
                    ++totNumOfFinds;
                    if(wordFoundInDoc == false){
                        ++totNumOfDocFinds;
                        wordFoundInDoc = true;
                    }
                }
                index->insert(words[vecCount]);
                */
            }
        }
    }
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

vector<string> Maintenance::setFileLocations(string fileName){
    vector<string> allFileLocations;

    filesystem::directory_iterator end;
    for(filesystem::directory_iterator theIterator(fileName) ; theIterator!= end; ++theIterator){
        // directory iterator is first converted to a path
        filesystem::path dirToPath = *theIterator;

        // path directory is converted to a string
        string pathToString = dirToPath.string();

        // string is appended to end of vector
        allFileLocations.push_back(pathToString);

        parse(pathToString);
        // string is parsed to filename, and added to vector
        totalNumOfValidDocs++;
    }

    return allFileLocations;
}

// returns vector of strings containing file locations
vector<string> Maintenance::getFileLocations(){
    return allFileLocations;
}

size_t Maintenance::getTotalNumValidDocs(){

    if(totalNumOfValidDocs > 0){
        return totalNumOfValidDocs;
    }

    return 0;
}

// Destructor
Maintenance::~Maintenance(){
    delete ui;
}


