/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_14;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_15;
    QDateTimeEdit *dateTimeEdit;
    QDateTimeEdit *dateTimeEdit_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_1;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_title;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_retour;
    QtCharts::QChartView *graphicsView;
    QtCharts::QChartView *graphicsView_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_pret;
    QLineEdit *lineEdit_2;
    QtCharts::QChartView *graphicsView_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_11;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer_2;
    QtCharts::QChartView *graphicsView_pret;
    QTextEdit *textEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(893, 776);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setDocumentMode(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_14 = new QHBoxLayout(groupBox_3);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_15 = new QHBoxLayout(groupBox);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        dateTimeEdit = new QDateTimeEdit(groupBox);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout_15->addWidget(dateTimeEdit);

        dateTimeEdit_2 = new QDateTimeEdit(groupBox);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        horizontalLayout_15->addWidget(dateTimeEdit_2);


        horizontalLayout_14->addWidget(groupBox);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_3->addWidget(checkBox_4, 1, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_3->addWidget(checkBox_2, 0, 1, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_3->addWidget(checkBox_5, 1, 1, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_3->addWidget(checkBox_3, 0, 2, 1, 1);

        checkBox_1 = new QCheckBox(groupBox_2);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setEnabled(true);
        checkBox_1->setCheckable(true);
        checkBox_1->setChecked(false);

        gridLayout_3->addWidget(checkBox_1, 0, 0, 1, 1);


        horizontalLayout_14->addWidget(groupBox_2);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_14->addWidget(pushButton);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 3);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        lineEdit_title = new QLineEdit(centralwidget);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));
        lineEdit_title->setEnabled(false);
        lineEdit_title->setInputMethodHints(Qt::ImhNone);
        lineEdit_title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_title, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton_retour = new QPushButton(centralwidget);
        pushButton_retour->setObjectName(QString::fromUtf8("pushButton_retour"));

        gridLayout->addWidget(pushButton_retour, 8, 0, 1, 3);

        graphicsView = new QtCharts::QChartView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 3, 0, 1, 1);

        graphicsView_2 = new QtCharts::QChartView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        gridLayout->addWidget(graphicsView_2, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        horizontalLayout->addWidget(pushButton_9);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 7, 0, 1, 3);

        lineEdit_pret = new QLineEdit(centralwidget);
        lineEdit_pret->setObjectName(QString::fromUtf8("lineEdit_pret"));
        lineEdit_pret->setEnabled(false);
        lineEdit_pret->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_pret, 5, 0, 1, 3);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_2, 2, 0, 1, 1);

        graphicsView_3 = new QtCharts::QChartView(centralwidget);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));

        gridLayout->addWidget(graphicsView_3, 3, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_3->addWidget(pushButton_5);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        horizontalLayout_3->addWidget(pushButton_11);


        gridLayout->addLayout(horizontalLayout_3, 4, 2, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 2, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_2->addWidget(pushButton_7);

        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        horizontalLayout_2->addWidget(pushButton_10);


        gridLayout->addLayout(horizontalLayout_2, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        graphicsView_pret = new QtCharts::QChartView(centralwidget);
        graphicsView_pret->setObjectName(QString::fromUtf8("graphicsView_pret"));
        graphicsView_pret->setEnabled(true);
        graphicsView_pret->setInteractive(false);

        gridLayout->addWidget(graphicsView_pret, 6, 0, 1, 2);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);

        gridLayout->addWidget(textEdit, 6, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "La banque ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "modif_chart", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "modif_date", nullptr));
        dateTimeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "dd/MM/yyyy", nullptr));
        dateTimeEdit_2->setDisplayFormat(QCoreApplication::translate("MainWindow", "dd/MM/yyyy", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "choisir_agneces", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "agence 4", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "agence 2", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "agence 5", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "agence 3", nullptr));
        checkBox_1->setText(QCoreApplication::translate("MainWindow", "agence 1", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "ok", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "canal assurance", nullptr));
        lineEdit_title->setText(QCoreApplication::translate("MainWindow", " La Banque", nullptr));
        pushButton_retour->setText(QCoreApplication::translate("MainWindow", "retour_sur_main", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "percent", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "bars", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "CA", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "info_on_pr\303\252t", nullptr));
        lineEdit_pret->setText(QCoreApplication::translate("MainWindow", "PR\303\212T", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "canal bancaire", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "percent", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "bars", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "CA", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "canal boursier", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "percent", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "bars", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "CA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
