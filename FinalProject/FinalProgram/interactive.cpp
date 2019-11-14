#include "interactive.h"
#include "ui_interactive.h"

Interactive::Interactive(QWidget *parent) : QDialog(parent), ui(new Ui::Interactive){
    ui->setupUi(this);
}

void Interactive::on_MainMenu_Button_clicked(){
    // Closes current windows
    this->close();
}


void Interactive::on_Search_Button_clicked(){
    if(ui->AVLTree_Button->isChecked()){
        // Open window containing inputted text & "AVL Tree" as window title
        QString qString_searchQuery = ui->SearchQuery_Line->text();
        QMessageBox::information(this,"Let's Search : AVL Tree", qString_searchQuery);

        // QString is converted and saved as string, the each word is added to a vector
        string searchQuery = qString_searchQuery.toStdString();
        vector<string> listOfWords = getWords(searchQuery);

    }

    else if(ui->HashTable_Button->isChecked()){
        // Open window containing inputted text & "Hash Table" as window title
        QString qString_searchQuery = ui->SearchQuery_Line->text();
        QMessageBox::information(this,"Let's Search : Hash Table", qString_searchQuery);

        string searchQuery = qString_searchQuery.toStdString();
        vector<string> listOfWords = getWords(searchQuery);

    }
}

vector<string> Interactive::getWords(string aString){
    string tempString;
    stringstream splitString(aString);
    vector<string> words;

    while(getline(splitString,tempString,' ')){
        words.push_back(tempString);
    }

    return words;
}

Interactive::~Interactive(){
    delete ui;
}
