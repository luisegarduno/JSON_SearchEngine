#include "interactive.h"
#include "ui_interactive.h"

Interactive::Interactive(QWidget *parent) : QDialog(parent), ui(new Ui::Interactive){
    ui->setupUi(this);

    avlTreeFlag = false;
    hashTableFlag = false;

    numberOfOpinions = 0;
    avgIndexedWords = 0;
}

void Interactive::on_MainMenu_Button_clicked(){
    // Closes current windows
    this->close();
}

void Interactive::on_Search_Button_clicked(){
    newQuery = new SearchQuery(this);

    string indexMethod;
    if(avlTreeSelected() == true && hashTableSelected() == false){
        indexMethod = "AVL Tree";
        newQuery->setIndexMethod(indexMethod);
        newQuery->show();
    }
    else if(avlTreeSelected() == false && hashTableSelected() == true){
        indexMethod = "Hash Table";
        newQuery->setIndexMethod(indexMethod);
        newQuery->show();
    }
    else{
        QMessageBox::warning(this,"Invalid", "Index Method has not been selected yet",QMessageBox::Ok);
    }

}

void Interactive::on_IndexMethod_Button_clicked(){
    QMessageBox selectIndexMethod;
    selectIndexMethod.setIcon(QMessageBox::Question);
    selectIndexMethod.setWindowTitle("Let's Search : Index Method");
    selectIndexMethod.setText(tr("Select a method to load/reload Index Data:"));
    QAbstractButton* avlTree_Button = selectIndexMethod.addButton(tr("AVL Tree"), QMessageBox::NoRole);
    selectIndexMethod.addButton(tr("Hash Table"), QMessageBox::YesRole);

    selectIndexMethod.exec();

    if (selectIndexMethod.clickedButton() == avlTree_Button) {
        // Turns AVL Tree Flag on --> AVL Tree is selected as Index Method
        avlTreeFlag = true;
        hashTableFlag = false;
        QMessageBox::information(this,"Let's Search : Index Mode", "Selected Mode: AVL Tree");
        indexInterface = new AvlTreeIndex;
        //indexInterface->load_Index();
        //indexInterface->print_Index();

    }
    else{
        // Turns AVL Tree Flag on --> AVL Tree is selected as Index Method
        avlTreeFlag = false;
        hashTableFlag = true;
        QMessageBox::information(this,"Let's Search : Index Mode", "Selected Mode: Hash Table");
        indexInterface = new HashTableIndex;
        //indexInterface->load_Index();
        //indexInterface->print_Index();
    }
}

void Interactive::on_Statistics_clicked(){
    string theNumOfOpinions = to_string(getNumOfOpinions());
    string theAvgNumIndexWords = to_string(getAvgNumIndexWords());
    string top50Print;

    for(size_t i = 1; i < 51; i++){
        if(i != 50){
            top50Print +=  "\t[" + to_string(i) + "]: " + top50Words.at(i - 1) + "\n";
        }
        else{
            top50Print += "\t[" + to_string(i) + "]: " + top50Words.at(i - 1);
        }
    }


    QString opinionsIndex = "[1]Total number of Opinions Index: " + QString::fromStdString(theNumOfOpinions) + "\n\n";
    QString averageIndexedWords = "[2]Average number of words indexed per opinion (after removal of stop words): " + QString::fromStdString(theAvgNumIndexWords) +  "\n\n";
    QString top50WordsFound = "[3]Top 50 most frequent words: \n" + QString::fromStdString(top50Print);

    QString theStatistics = opinionsIndex + averageIndexedWords + top50WordsFound;
    QMessageBox::information(this,"Let's Search : Statistics",theStatistics);
}

void Interactive::setFileDirectory(vector<string> providedVector){
    fileDirectory = providedVector;
}

int Interactive::getNumOfOpinions(){
    return numberOfOpinions;
}

double Interactive::getAvgNumIndexWords(){
    return avgIndexedWords;
}

bool Interactive::avlTreeSelected(){
    return avlTreeFlag;
}

bool Interactive::hashTableSelected(){
    return hashTableFlag;
}

Interactive::~Interactive(){
    delete ui;
}

