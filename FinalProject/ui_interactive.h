/********************************************************************************
** Form generated from reading UI file 'interactive.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERACTIVE_H
#define UI_INTERACTIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interactive
{
public:
    QLabel *Interactive_Label;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *IndexMethod_Button;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *Search_Button;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_18;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *Statistics;
    QHBoxLayout *horizontalLayout_20;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *MainMenu_Button;
    QVBoxLayout *verticalLayout_19;
    QLabel *picLabel;

    void setupUi(QDialog *Interactive)
    {
        if (Interactive->objectName().isEmpty())
            Interactive->setObjectName(QStringLiteral("Interactive"));
        Interactive->resize(500, 300);
        Interactive->setMinimumSize(QSize(500, 300));
        Interactive->setMaximumSize(QSize(500, 300));
        Interactive_Label = new QLabel(Interactive);
        Interactive_Label->setObjectName(QStringLiteral("Interactive_Label"));
        Interactive_Label->setGeometry(QRect(120, 20, 350, 80));
        Interactive_Label->setMinimumSize(QSize(350, 80));
        Interactive_Label->setMaximumSize(QSize(350, 80));
        QFont font;
        font.setPointSize(25);
	font.setBold(true);
	font.setUnderline(true);
        Interactive_Label->setFont(font);
        groupBox = new QGroupBox(Interactive);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(75, 125, 351, 150));
        QFont font1;
        font1.setPointSize(15);
        groupBox->setFont(font1);
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 30, 331, 111));
        verticalLayout_10 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        IndexMethod_Button = new QPushButton(verticalLayoutWidget_2);
        IndexMethod_Button->setObjectName(QStringLiteral("IndexMethod_Button"));
        IndexMethod_Button->setMinimumSize(QSize(150, 35));
        IndexMethod_Button->setMaximumSize(QSize(150, 35));
        IndexMethod_Button->setFont(font1);

        horizontalLayout_15->addWidget(IndexMethod_Button, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_13->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        Search_Button = new QPushButton(verticalLayoutWidget_2);
        Search_Button->setObjectName(QStringLiteral("Search_Button"));
        Search_Button->setMinimumSize(QSize(150, 35));
        Search_Button->setMaximumSize(QSize(150, 35));
        Search_Button->setFont(font1);

        horizontalLayout_14->addWidget(Search_Button, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_13->addLayout(horizontalLayout_14);


        verticalLayout_11->addLayout(horizontalLayout_13);


        verticalLayout_10->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        Statistics = new QPushButton(verticalLayoutWidget_2);
        Statistics->setObjectName(QStringLiteral("Statistics"));
        Statistics->setMinimumSize(QSize(100, 30));
        Statistics->setMaximumSize(QSize(100, 30));
        QFont font2;
        font2.setPointSize(12);
        Statistics->setFont(font2);

        horizontalLayout_19->addWidget(Statistics, 0, Qt::AlignRight|Qt::AlignTop);


        horizontalLayout_17->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));

        horizontalLayout_17->addLayout(horizontalLayout_20);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        MainMenu_Button = new QPushButton(verticalLayoutWidget_2);
        MainMenu_Button->setObjectName(QStringLiteral("MainMenu_Button"));
        MainMenu_Button->setMinimumSize(QSize(100, 30));
        MainMenu_Button->setMaximumSize(QSize(100, 30));
        MainMenu_Button->setFont(font2);

        horizontalLayout_18->addWidget(MainMenu_Button, 0, Qt::AlignLeft|Qt::AlignTop);


        horizontalLayout_17->addLayout(horizontalLayout_18);


        verticalLayout_20->addLayout(horizontalLayout_17);


        verticalLayout_18->addLayout(verticalLayout_20);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));

        verticalLayout_18->addLayout(verticalLayout_19);


        verticalLayout_14->addLayout(verticalLayout_18);


        verticalLayout_12->addLayout(verticalLayout_14);


        verticalLayout_10->addLayout(verticalLayout_12);

	picLabel = new QLabel(Interactive);
        picLabel->setObjectName(QStringLiteral("picLabel"));
        picLabel->setGeometry(QRect(-10, 0, 871, 411));
        picLabel->raise();
	groupBox->raise();
	Interactive_Label->raise();
        retranslateUi(Interactive);

        QMetaObject::connectSlotsByName(Interactive);
    } // setupUi

    void retranslateUi(QDialog *Interactive)
    {
        Interactive->setWindowTitle(QApplication::translate("Interactive", "Let's Search: Interactive", nullptr));
        Interactive_Label->setText(QApplication::translate("Interactive", "Interactive Mode", nullptr));
        groupBox->setTitle(QApplication::translate("Interactive", "Select Option: ", nullptr));
        IndexMethod_Button->setText(QApplication::translate("Interactive", "Index Method", nullptr));
        Search_Button->setText(QApplication::translate("Interactive", "Search", nullptr));
        Statistics->setText(QApplication::translate("Interactive", "Statistics", nullptr));
        MainMenu_Button->setText(QApplication::translate("Interactive", "Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interactive: public Ui_Interactive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERACTIVE_H
