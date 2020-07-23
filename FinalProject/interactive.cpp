#include "interactive.h"
#include "ui_interactive.h"

Interactive::Interactive(QWidget *parent) : QDialog(parent), ui(new Ui::Interactive){
    ui->setupUi(this);

    QPixmap pix("/home/student/Pictures/image.jpg");
    int w = ui->picLabel->width();
    int h = ui->picLabel->height();
    ui->picLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPalette InteractiveLabel = ui->Interactive_Label->palette();
    InteractiveLabel.setColor(ui->Interactive_Label->backgroundRole(), Qt::white);
    InteractiveLabel.setColor(ui->Interactive_Label->foregroundRole(), Qt::white);
    ui->Interactive_Label->setPalette(InteractiveLabel);

    QPalette groupLabel = ui->groupBox->palette();
    groupLabel.setColor(ui->groupBox->backgroundRole(), Qt::white);
    groupLabel.setColor(ui->groupBox->foregroundRole(), Qt::white);
    ui->groupBox->setPalette(groupLabel);

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
        newQuery->theIndex = *&indexInterface;
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
        indexInterface = new AvlTree_Index;
        indexInterface->load_Index();
        QMessageBox::information(this,"Let's Search : Index Mode", "Selected Mode: AVL Tree");

    }
    else{
        // Turns AVL Tree Flag on --> AVL Tree is selected as Index Method
        avlTreeFlag = false;
        hashTableFlag = true;
        indexInterface = new HashTable_Index;
        indexInterface->load_Index();
        QMessageBox::information(this,"Let's Search : Index Mode", "Selected Mode: Hash Table");
    }
}

void Interactive::on_Statistics_clicked(){
    fstream persistentIndex("../Index.txt");
    if(persistentIndex.is_open() && (avlTreeFlag == true || hashTableFlag == true)){
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
        persistentIndex.close();
    }
    else{
        QMessageBox::warning(this,"Invalid", "Index Method has not been selected yet",QMessageBox::Ok);
    }
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

