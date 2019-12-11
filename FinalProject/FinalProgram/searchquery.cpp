#include "searchquery.h"
#include "ui_searchquery.h"

SearchQuery::SearchQuery(QWidget *parent) : QDialog(parent), ui(new Ui::SearchQuery){
    ui->setupUi(this);
}

void SearchQuery::on_Search_Button_clicked(){

    // Open window containing inputted text & "AVL Tree"/"HashTable as window title
    QString qString_searchQuery = ui->SearchQuery_Line->text();
    string searchQuery = qString_searchQuery.toStdString();
    Porter2Stemmer::stem(searchQuery);
    vector<string> listOfWords = getWords(searchQuery);

    if(getIndexMethod() == "AVL Tree"){
        if(listOfWords.size() == 1){
            string finResults;
            word tempWord(searchQuery,finResults);
            tempWord = theIndex->search_Index(tempWord);
            map<string,int> tempMap = tempWord.getDocumentNames();
            finResults = searchQuery + " was found in: \n";

            map<string,int>::iterator theIterator;
            for(theIterator = tempMap.begin(); theIterator != tempMap.end(); ++theIterator){
                finResults += theIterator->first + "\n";
                //cout << theIterator->first << endl;
            }
            QMessageBox::information(this,"Let's Search : AVL Tree", QString::fromStdString(finResults));
        }
        else{
            cout << "Actual Size: " << listOfWords.size() << endl;
        }
    }

    else if(getIndexMethod() == "Hash Table"){
        if(listOfWords.size() == 1){
            string finResults;
            word tempWord(searchQuery,finResults);
            tempWord = theIndex->search_Index(tempWord);
            map<string,int> tempMap = tempWord.getDocumentNames();
            finResults = searchQuery + " was found in: \n";

            map<string,int>::iterator theIterator;
            for(theIterator = tempMap.begin(); theIterator != tempMap.end(); ++theIterator){
                finResults += theIterator->first + "\n";
                //cout << theIterator->first << endl;
            }
            QMessageBox::information(this,"Let's Search : Hash Table", qString_searchQuery);
        }
        else{
            cout << "Actual Size: " << listOfWords.size() << endl;
        }
    }
}


vector<string> SearchQuery::getWords(string aString){
    string tempString;
    stringstream splitString(aString);
    vector<string> words;

    while(getline(splitString,tempString,' ')){
        words.push_back(tempString);
    }

    return words;
}

void SearchQuery::setIndexMethod(string indexMethod){
    this->indexMethod = indexMethod;
}

string SearchQuery::getIndexMethod(){
    return indexMethod;
}

void SearchQuery::on_MainMenu_Button_clicked(){
    this->close();
}

SearchQuery::~SearchQuery(){
    delete ui;
}
