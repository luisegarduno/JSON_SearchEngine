#include "searchquery.h"
#include "ui_searchquery.h"

SearchQuery::SearchQuery(QWidget *parent) : QDialog(parent), ui(new Ui::SearchQuery){
    ui->setupUi(this);
}

void SearchQuery::on_Search_Button_clicked(){

    // Open window containing inputted text & "AVL Tree"/"HashTable as window title
    QString qString_searchQuery = ui->SearchQuery_Line->text();
    string searchQuery = qString_searchQuery.toStdString();
    vector<string> listOfWords = getWords(searchQuery);

    if(getIndexMethod() == "AVL Tree"){
        if(listOfWords.size() == 1){
            string finResults;
            Porter2Stemmer::stem(searchQuery);
            word tempWord(searchQuery,finResults);
            tempWord = theIndex->search_Index(tempWord);
            map<string,int> tempMap = tempWord.getDocumentNames();
            finResults = searchQuery + " was found in: \n";
            int counter = 0;
            map<string,int>::iterator theIterator;
            for(theIterator = tempMap.begin(); theIterator != tempMap.end() && counter < 15; ++theIterator){
                finResults += "[" + std::to_string(counter + 1) + "] --> File: " + theIterator->first + " --> Frequency " + std::to_string(theIterator->second) + " times\n";
                counter++;
            }
            QMessageBox::information(this,"Let's Search : AVL Tree", QString::fromStdString(finResults));
        }
        else if(listOfWords.size() == 3 && listOfWords[0] == "AND"){
            string finResults;
            Porter2Stemmer::stem(listOfWords[1]);
            word tempWord1(listOfWords[1],finResults);
            tempWord1 = theIndex->search_Index(tempWord1);
            map<string,int> tempMap1 = tempWord1.getDocumentNames();

            Porter2Stemmer::stem(listOfWords[2]);
            word tempWord2(listOfWords[2],finResults);
            tempWord2 = theIndex->search_Index(tempWord2);
            map<string,int> tempMap2 = tempWord2.getDocumentNames();

            int counter = 0;
            map<string,int>::iterator theIterator;
            for(theIterator = tempMap1.begin(); theIterator != tempMap1.end() && counter < 15; ++theIterator){
                map<string,int>::iterator theIterator2;
                for(theIterator2 = tempMap2.begin(); theIterator2 != tempMap2.end() && counter < 15; ++theIterator2){
                    if(theIterator->first == theIterator2->first){
                        string first = theIterator->first + "(" + std::to_string(theIterator->second) + ") & ";
                        string second = theIterator2->first + "(" + std::to_string(theIterator2->second) + ") ";
                        finResults += "[" + std::to_string(counter + 1) + "] --> File/s: " + first + second + "\n";
                        counter++;
                    }
                }
            }
            QMessageBox::information(this,"Let's Search : AVL Tree", QString::fromStdString(finResults));

        }
        else if(listOfWords.size() == 4 && listOfWords[0] == "AND"){
            string finResults;

            Porter2Stemmer::stem(listOfWords[1]);
            word tempWord1(listOfWords[1],finResults);
            tempWord1 = theIndex->search_Index(tempWord1);
            map<string,int> tempMap1 = tempWord1.getDocumentNames();

            Porter2Stemmer::stem(listOfWords[2]);
            word tempWord2(listOfWords[2],finResults);
            tempWord2 = theIndex->search_Index(tempWord2);
            map<string,int> tempMap2 = tempWord2.getDocumentNames();

            Porter2Stemmer::stem(listOfWords[3]);
            word tempWord3(listOfWords[3],finResults);
            tempWord3 = theIndex->search_Index(tempWord3);
            map<string,int> tempMap3 = tempWord3.getDocumentNames();

            int counter = 0;
            map<string,int>::iterator theIterator;
            for(theIterator = tempMap1.begin(); theIterator != tempMap1.end() && counter < 15; ++theIterator){
                map<string,int>::iterator theIterator2;
                for(theIterator2 = tempMap2.begin(); theIterator2 != tempMap2.end() && counter < 15; ++theIterator2){
                    map<string,int>::iterator theIterator3;
                    for(theIterator3 = tempMap3.begin(); theIterator3 != tempMap3.end() && counter < 15; ++theIterator3){
                        if(theIterator->first == theIterator2->first && theIterator2->first == theIterator3->first){
                            string first = theIterator->first + "(" + std::to_string(theIterator->second) + ") & ";
                            string second = theIterator2->first + "(" + std::to_string(theIterator2->second) + ") & ";
                            string third = theIterator3->first + "(" + std::to_string(theIterator3->second) + ") ";
                            finResults += "[" + std::to_string(counter + 1) + "] --> File/s: " + first + second + third + "\n";
                            counter++;
                        }
                    }
                }
            }

            QMessageBox::information(this,"Let's Search : AVL Tree", QString::fromStdString(finResults));
        }
        else if(listOfWords.size() == 3 && listOfWords[0] == "OR"){
            string finResults;

            Porter2Stemmer::stem(listOfWords[1]);
            word tempWord1(listOfWords[1],finResults);
            tempWord1 = theIndex->search_Index(tempWord1);
            map<string,int> tempMap1 = tempWord1.getDocumentNames();

            Porter2Stemmer::stem(listOfWords[2]);
            word tempWord2(listOfWords[2],finResults);
            tempWord2 = theIndex->search_Index(tempWord2);
            map<string,int> tempMap2 = tempWord2.getDocumentNames();
            int counter = 0;
            map<string,int>::iterator theIterator;
            for(theIterator = tempMap1.begin(); theIterator != tempMap1.end() && counter < 15; ++theIterator){
                map<string,int>::iterator theIterator2;
                for(theIterator2 = tempMap2.begin(); theIterator2 != tempMap2.end() && counter < 15; ++theIterator2){
                    if(theIterator->first == theIterator2->first){
                        if(theIterator->second == theIterator2->second){
                            string one1 = "(" + std::to_string(theIterator->second) + ")";
                            string two2 = "(" + std::to_string(theIterator2->second) + ")";
                            finResults += "[" + std::to_string(counter + 1) + "]: File: " + theIterator->first + one1 + two2 + "contains both\n";
                            counter++;
                        }
                        else{
                            string one1 = "(" + std::to_string(theIterator->second) + ")";
                            string two2 = "(" + std::to_string(theIterator2->second) + ")";
                            finResults += "[" + std::to_string(counter + 1) + "]: File/s: " + theIterator->first + one1 + " & " + theIterator2->first + two2 + " contain both";
                            counter++;
                        }

                    }
                    else{
                        string word_1 = listOfWords[1] + "{" + theIterator->first + "(" + std::to_string(theIterator->second) + ")} & ";
                        string word_2 = listOfWords[2] + "{" + theIterator2->first + "(" + std::to_string(theIterator2->second) + ")} \n";
                        finResults +=  "[" + std::to_string(counter + 1) + "]: " + word_1 + word_2;
                        counter++;
                    }
                }
            }
            QMessageBox::information(this,"Let's Search : AVL Tree", QString::fromStdString(finResults));
        }

        else if(listOfWords.size() == 5 && listOfWords[0] == "AND" && listOfWords[3] == "NOT"){
            string finResults;

            Porter2Stemmer::stem(listOfWords[1]);
            word tempWord1(listOfWords[1],finResults);
            tempWord1 = theIndex->search_Index(tempWord1);
            map<string,int> tempMap1 = tempWord1.getDocumentNames();

            Porter2Stemmer::stem(listOfWords[2]);
            word tempWord2(listOfWords[2],finResults);
            tempWord2 = theIndex->search_Index(tempWord2);
            map<string,int> tempMap2 = tempWord2.getDocumentNames();

            Porter2Stemmer::stem(listOfWords[4]);
            word tempWord3(listOfWords[4],finResults);
            tempWord3 = theIndex->search_Index(tempWord3);
            map<string,int> tempMap3 = tempWord3.getDocumentNames();
            int counter = 0;
            map<string,int>::iterator theIterator;
            for(theIterator = tempMap1.begin(); theIterator != tempMap1.end() && counter < 15; ++theIterator){
                map<string,int>::iterator theIterator2;
                for(theIterator2 = tempMap2.begin(); theIterator2 != tempMap2.end() && counter < 15; ++theIterator2){
                    map<string,int>::iterator theIterator3;
                    for(theIterator3 = tempMap3.begin(); theIterator3 != tempMap3.end() && counter < 15; ++theIterator3){
                        if((theIterator->first == theIterator2->first) && (theIterator2->first != theIterator3->first) && (theIterator->first != theIterator3->first)){

                            string word_1 = listOfWords[1] + "{" + theIterator->first + "(" + std::to_string(theIterator->second) + ")} & ";
                            string word_2 = listOfWords[2] + "{" + theIterator2->first + "(" + std::to_string(theIterator2->second) + ")} \n";
                            finResults +=  "[" + std::to_string(counter + 1) + "]: " + word_1 + word_2;
                            counter++;
                        }
                    }
                }
            }
            QMessageBox::information(this,"Let's Search : AVL Tree", QString::fromStdString(finResults));
        }
        else if(listOfWords.size() == 3 && listOfWords[1] == "NOT"){
            string finResults;

            Porter2Stemmer::stem(listOfWords[0]);
            word tempWord1(listOfWords[0],finResults);
            tempWord1 = theIndex->search_Index(tempWord1);
            map<string,int> tempMap1 = tempWord1.getDocumentNames();

            Porter2Stemmer::stem(listOfWords[2]);
            word tempWord2(listOfWords[2],finResults);
            tempWord2 = theIndex->search_Index(tempWord2);
            map<string,int> tempMap2 = tempWord2.getDocumentNames();

            int counter = 0;
            map<string,int>::iterator theIterator;
            for(theIterator = tempMap1.begin(); theIterator != tempMap1.end() && counter < 15; ++theIterator){
                map<string,int>::iterator theIterator2;
                for(theIterator2 = tempMap2.begin(); theIterator2 != tempMap2.end() && counter < 15; ++theIterator2){
                    if(theIterator->first != theIterator2->first){
                        string word_1 = listOfWords[1] + "{" + theIterator->first + "(" + std::to_string(theIterator->second) + ")} ";
                        finResults += "[" + std::to_string(counter + 1) + "] --> File/s: " + word_1 + "\n";
                        counter++;
                    }
                }
            }
            QMessageBox::information(this,"Let's Search : AVL Tree", QString::fromStdString(finResults));

        }

        else{
            cout << "Invalid Operation" << endl;
        }
    }

    else if(getIndexMethod() == "Hash Table"){
        if(listOfWords.size() == 1){
                    string finResults;
                    Porter2Stemmer::stem(searchQuery);
                    word tempWord(searchQuery,finResults);
                    tempWord = theIndex->search_Index(tempWord);
                    map<string,int> tempMap = tempWord.getDocumentNames();
                    finResults = searchQuery + " was found in: \n";
                    int counter = 0;
                    map<string,int>::iterator theIterator;
                    for(theIterator = tempMap.begin(); theIterator != tempMap.end() && counter < 15; ++theIterator){
                        finResults += "[" + std::to_string(counter + 1) + "] --> File: " + theIterator->first + " --> Frequency " + std::to_string(theIterator->second) + " times\n";
                        counter++;
                    }
                    QMessageBox::information(this,"Let's Search : Hash Table", QString::fromStdString(finResults));
                }
                else if(listOfWords.size() == 3 && listOfWords[0] == "AND"){
                    string finResults;
                    Porter2Stemmer::stem(listOfWords[1]);
                    word tempWord1(listOfWords[1],finResults);
                    tempWord1 = theIndex->search_Index(tempWord1);
                    map<string,int> tempMap1 = tempWord1.getDocumentNames();

                    Porter2Stemmer::stem(listOfWords[2]);
                    word tempWord2(listOfWords[2],finResults);
                    tempWord2 = theIndex->search_Index(tempWord2);
                    map<string,int> tempMap2 = tempWord2.getDocumentNames();

                    int counter = 0;
                    map<string,int>::iterator theIterator;
                    for(theIterator = tempMap1.begin(); theIterator != tempMap1.end() && counter < 15; ++theIterator){
                        map<string,int>::iterator theIterator2;
                        for(theIterator2 = tempMap2.begin(); theIterator2 != tempMap2.end() && counter < 15; ++theIterator2){
                            if(theIterator->first == theIterator2->first){
                                string first = theIterator->first + "(" + std::to_string(theIterator->second) + ") & ";
                                string second = theIterator2->first + "(" + std::to_string(theIterator2->second) + ") ";
                                finResults += "[" + std::to_string(counter + 1) + "] --> File/s: " + first + second + "\n";
                                counter++;
                            }
                        }
                    }
                    QMessageBox::information(this,"Let's Search : Hash Table", QString::fromStdString(finResults));

                }
                else if(listOfWords.size() == 4 && listOfWords[0] == "AND"){
                    string finResults;

                    Porter2Stemmer::stem(listOfWords[1]);
                    word tempWord1(listOfWords[1],finResults);
                    tempWord1 = theIndex->search_Index(tempWord1);
                    map<string,int> tempMap1 = tempWord1.getDocumentNames();

                    Porter2Stemmer::stem(listOfWords[2]);
                    word tempWord2(listOfWords[2],finResults);
                    tempWord2 = theIndex->search_Index(tempWord2);
                    map<string,int> tempMap2 = tempWord2.getDocumentNames();

                    Porter2Stemmer::stem(listOfWords[3]);
                    word tempWord3(listOfWords[3],finResults);
                    tempWord3 = theIndex->search_Index(tempWord3);
                    map<string,int> tempMap3 = tempWord3.getDocumentNames();

                    int counter = 0;
                    map<string,int>::iterator theIterator;
                    for(theIterator = tempMap1.begin(); theIterator != tempMap1.end() && counter < 15; ++theIterator){
                        map<string,int>::iterator theIterator2;
                        for(theIterator2 = tempMap2.begin(); theIterator2 != tempMap2.end() && counter < 15; ++theIterator2){
                            map<string,int>::iterator theIterator3;
                            for(theIterator3 = tempMap3.begin(); theIterator3 != tempMap3.end() && counter < 15; ++theIterator3){
                                if(theIterator->first == theIterator2->first && theIterator2->first == theIterator3->first){
                                    string first = theIterator->first + "(" + std::to_string(theIterator->second) + ") & ";
                                    string second = theIterator2->first + "(" + std::to_string(theIterator2->second) + ") & ";
                                    string third = theIterator3->first + "(" + std::to_string(theIterator3->second) + ") ";
                                    finResults += "[" + std::to_string(counter + 1) + "] --> File/s: " + first + second + third + "\n";
                                    counter++;
                                }
                            }
                        }
                    }

                    QMessageBox::information(this,"Let's Search : Hash Table", QString::fromStdString(finResults));
                }
                else if(listOfWords.size() == 3 && listOfWords[0] == "OR"){
                    string finResults;

                    Porter2Stemmer::stem(listOfWords[1]);
                    word tempWord1(listOfWords[1],finResults);
                    tempWord1 = theIndex->search_Index(tempWord1);
                    map<string,int> tempMap1 = tempWord1.getDocumentNames();

                    Porter2Stemmer::stem(listOfWords[2]);
                    word tempWord2(listOfWords[2],finResults);
                    tempWord2 = theIndex->search_Index(tempWord2);
                    map<string,int> tempMap2 = tempWord2.getDocumentNames();
                    int counter = 0;
                    map<string,int>::iterator theIterator;
                    for(theIterator = tempMap1.begin(); theIterator != tempMap1.end() && counter < 15; ++theIterator){
                        map<string,int>::iterator theIterator2;
                        for(theIterator2 = tempMap2.begin(); theIterator2 != tempMap2.end() && counter < 15; ++theIterator2){
                            if(theIterator->first == theIterator2->first){
                                if(theIterator->second == theIterator2->second){
                                    string one1 = "(" + std::to_string(theIterator->second) + ")";
                                    string two2 = "(" + std::to_string(theIterator2->second) + ")";
                                    finResults += "[" + std::to_string(counter + 1) + "]: File: " + theIterator->first + one1 + two2 + "contains both\n";
                                    counter++;
                                }
                                else{
                                    string one1 = "(" + std::to_string(theIterator->second) + ")";
                                    string two2 = "(" + std::to_string(theIterator2->second) + ")";
                                    finResults += "[" + std::to_string(counter + 1) + "]: File/s: " + theIterator->first + one1 + " & " + theIterator2->first + two2 + " contain both";
                                    counter++;
                                }

                            }
                            else{
                                string word_1 = listOfWords[1] + "{" + theIterator->first + "(" + std::to_string(theIterator->second) + ")} & ";
                                string word_2 = listOfWords[2] + "{" + theIterator2->first + "(" + std::to_string(theIterator2->second) + ")} \n";
                                finResults +=  "[" + std::to_string(counter + 1) + "]: " + word_1 + word_2;
                                counter++;
                            }
                        }
                    }
                    QMessageBox::information(this,"Let's Search : Hash Table", QString::fromStdString(finResults));
                }

                else if(listOfWords.size() == 5 && listOfWords[0] == "AND" && listOfWords[3] == "NOT"){
                    string finResults;

                    Porter2Stemmer::stem(listOfWords[1]);
                    word tempWord1(listOfWords[1],finResults);
                    tempWord1 = theIndex->search_Index(tempWord1);
                    map<string,int> tempMap1 = tempWord1.getDocumentNames();

                    Porter2Stemmer::stem(listOfWords[2]);
                    word tempWord2(listOfWords[2],finResults);
                    tempWord2 = theIndex->search_Index(tempWord2);
                    map<string,int> tempMap2 = tempWord2.getDocumentNames();

                    Porter2Stemmer::stem(listOfWords[4]);
                    word tempWord3(listOfWords[4],finResults);
                    tempWord3 = theIndex->search_Index(tempWord3);
                    map<string,int> tempMap3 = tempWord3.getDocumentNames();
                    int counter = 0;
                    map<string,int>::iterator theIterator;
                    for(theIterator = tempMap1.begin(); theIterator != tempMap1.end() && counter < 15; ++theIterator){
                        map<string,int>::iterator theIterator2;
                        for(theIterator2 = tempMap2.begin(); theIterator2 != tempMap2.end() && counter < 15; ++theIterator2){
                            map<string,int>::iterator theIterator3;
                            for(theIterator3 = tempMap3.begin(); theIterator3 != tempMap3.end() && counter < 15; ++theIterator3){
                                if((theIterator->first == theIterator2->first) && (theIterator2->first != theIterator3->first) && (theIterator->first != theIterator3->first)){

                                    string word_1 = listOfWords[1] + "{" + theIterator->first + "(" + std::to_string(theIterator->second) + ")} & ";
                                    string word_2 = listOfWords[2] + "{" + theIterator2->first + "(" + std::to_string(theIterator2->second) + ")} \n";
                                    finResults +=  "[" + std::to_string(counter + 1) + "]: " + word_1 + word_2;
                                    counter++;
                                }
                            }
                        }
                    }
                    QMessageBox::information(this,"Let's Search : Hash Table", QString::fromStdString(finResults));
                }
                else if(listOfWords.size() == 3 && listOfWords[1] == "NOT"){
                    string finResults;

                    Porter2Stemmer::stem(listOfWords[0]);
                    word tempWord1(listOfWords[0],finResults);
                    tempWord1 = theIndex->search_Index(tempWord1);
                    map<string,int> tempMap1 = tempWord1.getDocumentNames();

                    Porter2Stemmer::stem(listOfWords[2]);
                    word tempWord2(listOfWords[2],finResults);
                    tempWord2 = theIndex->search_Index(tempWord2);
                    map<string,int> tempMap2 = tempWord2.getDocumentNames();

                    int counter = 0;
                    map<string,int>::iterator theIterator;
                    for(theIterator = tempMap1.begin(); theIterator != tempMap1.end() && counter < 15; ++theIterator){
                        map<string,int>::iterator theIterator2;
                        for(theIterator2 = tempMap2.begin(); theIterator2 != tempMap2.end() && counter < 15; ++theIterator2){
                            if(theIterator->first != theIterator2->first){
                                string word_1 = listOfWords[1] + "{" + theIterator->first + "(" + std::to_string(theIterator->second) + ")} ";
                                finResults += "[" + std::to_string(counter + 1) + "] --> File/s: " + word_1 + "\n";
                                counter++;
                            }
                        }
                    }
                    QMessageBox::information(this,"Let's Search : Hash Table", QString::fromStdString(finResults));

                }

                else{
                    cout << "Invalid Operation" << endl;
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
