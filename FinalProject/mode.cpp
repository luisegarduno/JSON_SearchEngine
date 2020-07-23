#include "mode.h"
#include "ui_mode.h"

Mode::Mode(QWidget *parent): QMainWindow(parent), ui(new Ui::Mode){
    ui->setupUi(this);

    QPalette welcomeLabel = ui->Welcome_Label->palette();
    welcomeLabel.setColor(ui->Welcome_Label->backgroundRole(), Qt::white);
    welcomeLabel.setColor(ui->Welcome_Label->foregroundRole(), Qt::white);
    ui->Welcome_Label->setPalette(welcomeLabel);

    QPalette selectModeLabel = ui->SelectMode_Group->palette();
    selectModeLabel.setColor(ui->SelectMode_Group->backgroundRole(), Qt::white);
    selectModeLabel.setColor(ui->SelectMode_Group->foregroundRole(), Qt::white);
    ui->SelectMode_Group->setPalette(selectModeLabel);


    QPixmap pix("/home/student/Pictures/image.jpg");
    int w = ui->picLabel->width();
    int h = ui->picLabel->height();
    ui->picLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    // Create new Maintenance window object on HEAP
    maintenanceMode = new Maintenance(this);

    // Create new Interactive window object on HEAP
    interactiveMode = new Interactive(this);

}

void Mode::on_Maintenance_Button_clicked(){

    maintenanceMode->setGeometry(
        QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    maintenanceMode->size(),
                    qApp->desktop()->availableGeometry()
        )
    );

    maintenanceMode->show();
}

void Mode::on_Interactive_Button_clicked(){
    fstream indexChecker("../Index.txt");
    if(maintenanceMode->getTotalNumValidDocs() != 0 || indexChecker.is_open()){
        indexChecker.close();
        interactiveMode->numberOfOpinions = maintenanceMode->getTotalNumValidDocs();
        interactiveMode->avgIndexedWords = maintenanceMode->getTotalNumOfWords() / maintenanceMode->getTotalNumValidDocs();
        interactiveMode->top50Words = maintenanceMode->getTop50Words();

        if(maintenanceMode->getTotalNumValidDocs() > 0){
            // Create new Interactive window object on HEAP
            opinionLocations = maintenanceMode->getFileLocations();

            interactiveMode->setGeometry(
                QStyle::alignedRect(
                            Qt::LeftToRight,
                            Qt::AlignCenter,
                            interactiveMode->size(),
                            qApp->desktop()->availableGeometry()
                )
            );
        }

        interactiveMode->show();
    }

    else if(!indexChecker.is_open()){
        QString noFile = "Index not found\n";
        QString tryAgain = "Please select valid path to a folder";
        QMessageBox::warning(this,"Error", noFile + tryAgain);
    }
}

Mode::~Mode(){

    fstream persistentIndex;
    persistentIndex.open("../Index.txt" , fstream::in | fstream::out | fstream::app);
    vector<string> indexVector = maintenanceMode->getIndex();
    for(size_t counter = 0; counter < indexVector.size(); counter++){
        persistentIndex << "--> "  << indexVector[counter] << " \n";
    }
    persistentIndex.close();


    delete ui;
}

