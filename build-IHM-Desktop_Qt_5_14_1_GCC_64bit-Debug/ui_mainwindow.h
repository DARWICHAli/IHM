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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_title;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_14;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_15;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_1;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3names;
    QGridLayout *gridLayout_4;
    QtCharts::QChartView *graphicsView;
    QtCharts::QChartView *graphicsView_2;
    QPushButton *pushButton_6;
    QtCharts::QChartView *graphicsView_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_pret;
    QtCharts::QChartView *graphicsView_pret;
    QPushButton *pushButton_2;
    QPushButton *pushButton_retour;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(868, 757);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_title = new QLineEdit(centralwidget);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));
        lineEdit_title->setEnabled(false);
        lineEdit_title->setInputMethodHints(Qt::ImhNone);

        verticalLayout->addWidget(lineEdit_title);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_14 = new QHBoxLayout(groupBox_3);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_15 = new QHBoxLayout(groupBox);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout_15->addWidget(dateEdit);

        dateEdit_2 = new QDateEdit(groupBox);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        horizontalLayout_15->addWidget(dateEdit_2);


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


        verticalLayout->addWidget(groupBox_3);

        lineEdit_3names = new QLineEdit(centralwidget);
        lineEdit_3names->setObjectName(QString::fromUtf8("lineEdit_3names"));
        lineEdit_3names->setEnabled(false);

        verticalLayout->addWidget(lineEdit_3names);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        graphicsView = new QtCharts::QChartView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout_4->addWidget(graphicsView, 0, 0, 1, 1);

        graphicsView_2 = new QtCharts::QChartView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        gridLayout_4->addWidget(graphicsView_2, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout_4->addWidget(pushButton_6, 1, 0, 1, 1);

        graphicsView_3 = new QtCharts::QChartView(centralwidget);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));

        gridLayout_4->addWidget(graphicsView_3, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_4->addWidget(pushButton_5, 2, 2, 1, 1);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout_4->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_4->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_4->addWidget(pushButton_4, 2, 1, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout_4->addWidget(pushButton_7, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        lineEdit_pret = new QLineEdit(centralwidget);
        lineEdit_pret->setObjectName(QString::fromUtf8("lineEdit_pret"));
        lineEdit_pret->setEnabled(false);

        verticalLayout->addWidget(lineEdit_pret);

        graphicsView_pret = new QtCharts::QChartView(centralwidget);
        graphicsView_pret->setObjectName(QString::fromUtf8("graphicsView_pret"));
        graphicsView_pret->setEnabled(true);
        graphicsView_pret->setInteractive(false);

        verticalLayout->addWidget(graphicsView_pret);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_retour = new QPushButton(centralwidget);
        pushButton_retour->setObjectName(QString::fromUtf8("pushButton_retour"));

        verticalLayout->addWidget(pushButton_retour);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_title->setText(QCoreApplication::translate("MainWindow", "                                                                                                               La Banque", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "modif_chart", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "modif_date", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "choisir_agneces", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "agence 4", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "agence 2", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "agence 5", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "agence 3", nullptr));
        checkBox_1->setText(QCoreApplication::translate("MainWindow", "agence 1", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "ok", nullptr));
        lineEdit_3names->setText(QCoreApplication::translate("MainWindow", "                        ca                                                                                       df                                                                                cb", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "bars", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "percent", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "bars", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "percent", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "percent", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "bars", nullptr));
        lineEdit_pret->setText(QCoreApplication::translate("MainWindow", "                                                                                                                 PR\303\212T", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "info_on_pr\303\252t", nullptr));
        pushButton_retour->setText(QCoreApplication::translate("MainWindow", "retour_sur_main", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
