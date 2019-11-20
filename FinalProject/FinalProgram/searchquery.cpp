#include "searchquery.h"
#include "ui_searchquery.h"

SearchQuery::SearchQuery(QWidget *parent) : QDialog(parent), ui(new Ui::SearchQuery){
    ui->setupUi(this);
}

void SearchQuery::on_Search_Button_clicked(){

    if(getIndexMethod() == "AVL Tree"){
        // Open window containing inputted text & "AVL Tree" as window title
        QString qString_searchQuery = ui->SearchQuery_Line->text();
        QMessageBox::information(this,"Let's Search : AVL Tree", qString_searchQuery);

        // QString is converted and saved as string, the each word is added to a vector
        string searchQuery = qString_searchQuery.toStdString();
        vector<string> listOfWords = getWords(searchQuery);
    }

    else if(getIndexMethod() == "Hash Table"){
        // Open window containing inputted text & "Hash Table" as window title
        QString qString_searchQuery = ui->SearchQuery_Line->text();
        QMessageBox::information(this,"Let's Search : Hash Table", qString_searchQuery);

        string searchQuery = qString_searchQuery.toStdString();
        vector<string> listOfWords = getWords(searchQuery);
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
