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
#include <QtWidgets/QLabel>
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
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_14;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_15;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_4;
    QPushButton *pushButton;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_13;
    QtCharts::QChartView *graphicsView;
    QtCharts::QChartView *graphicsView_3;
    QtCharts::QChartView *graphicsView_2;
    QLabel *label_2;
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
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setInputMethodHints(Qt::ImhNone);

        verticalLayout_6->addWidget(lineEdit);

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
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_3->addWidget(checkBox_3, 0, 2, 1, 1);

        checkBox_1 = new QCheckBox(groupBox_2);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setEnabled(true);
        checkBox_1->setCheckable(true);
        checkBox_1->setChecked(false);

        gridLayout_3->addWidget(checkBox_1, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_3->addWidget(checkBox_2, 0, 1, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_3->addWidget(checkBox_5, 1, 1, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_3->addWidget(checkBox_4, 1, 0, 1, 1);


        horizontalLayout_14->addWidget(groupBox_2);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_14->addWidget(pushButton);


        verticalLayout_6->addWidget(groupBox_3);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_6->addWidget(label_3);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        graphicsView = new QtCharts::QChartView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout_13->addWidget(graphicsView);

        graphicsView_3 = new QtCharts::QChartView(centralwidget);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));

        horizontalLayout_13->addWidget(graphicsView_3);

        graphicsView_2 = new QtCharts::QChartView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        horizontalLayout_13->addWidget(graphicsView_2);


        verticalLayout_6->addLayout(horizontalLayout_13);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_6->addWidget(label_2);

        graphicsView_pret = new QtCharts::QChartView(centralwidget);
        graphicsView_pret->setObjectName(QString::fromUtf8("graphicsView_pret"));
        graphicsView_pret->setEnabled(true);
        graphicsView_pret->setInteractive(false);

        verticalLayout_6->addWidget(graphicsView_pret);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_6->addWidget(pushButton_2);

        pushButton_retour = new QPushButton(centralwidget);
        pushButton_retour->setObjectName(QString::fromUtf8("pushButton_retour"));

        verticalLayout_6->addWidget(pushButton_retour);

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
        lineEdit->setText(QCoreApplication::translate("MainWindow", "                                                                                                               La Banque", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "modif_chart", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "modif_date", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "choisir_agneces", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "agence 3", nullptr));
        checkBox_1->setText(QCoreApplication::translate("MainWindow", "agence 1", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "agence 2", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "agence 5", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "agence 4", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "ok", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "                               ca                                                                            cb                                                              cas ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "       pr\303\252t", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "info_on_pr\303\252t", nullptr));
        pushButton_retour->setText(QCoreApplication::translate("MainWindow", "retour_sur_main", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
