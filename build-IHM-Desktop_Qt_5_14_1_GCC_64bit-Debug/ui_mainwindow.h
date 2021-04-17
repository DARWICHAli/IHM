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
    QGridLayout *gridLayout_5;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit_2;
    QtCharts::QChartView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QtCharts::QChartView *graphicsView_3;
    QLineEdit *lineEdit;
    QtCharts::QChartView *graphicsView_2;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_11;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_retour;
    QtCharts::QChartView *graphicsView_pret;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_pret;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_15;
    QDateTimeEdit *dateTimeEdit;
    QDateTimeEdit *dateTimeEdit_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_3;
    QLineEdit *lineEdit_title;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1388, 776);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setDocumentMode(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);\n"
"background-color: rgb(186, 189, 182);"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        horizontalLayout->addWidget(pushButton_9);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_2, 0, 0, 1, 1);

        graphicsView = new QtCharts::QChartView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_2->addWidget(pushButton_7);

        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        horizontalLayout_2->addWidget(pushButton_10);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        graphicsView_3 = new QtCharts::QChartView(widget);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));

        gridLayout->addWidget(graphicsView_3, 1, 2, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 0, 2, 1, 1);

        graphicsView_2 = new QtCharts::QChartView(widget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        gridLayout->addWidget(graphicsView_2, 1, 1, 1, 1);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_3, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_3->addWidget(pushButton_5);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        horizontalLayout_3->addWidget(pushButton_11);


        gridLayout->addLayout(horizontalLayout_3, 2, 2, 1, 1);


        gridLayout_5->addWidget(widget, 3, 0, 1, 3);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8(""));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_retour = new QPushButton(widget_2);
        pushButton_retour->setObjectName(QString::fromUtf8("pushButton_retour"));
        pushButton_retour->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));

        gridLayout_4->addWidget(pushButton_retour, 3, 0, 1, 2);

        graphicsView_pret = new QtCharts::QChartView(widget_2);
        graphicsView_pret->setObjectName(QString::fromUtf8("graphicsView_pret"));
        graphicsView_pret->setEnabled(true);
        graphicsView_pret->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        graphicsView_pret->setInteractive(false);

        gridLayout_4->addWidget(graphicsView_pret, 1, 0, 1, 1);

        textEdit = new QTextEdit(widget_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));

        gridLayout_4->addWidget(textEdit, 1, 1, 1, 1);

        lineEdit_pret = new QLineEdit(widget_2);
        lineEdit_pret->setObjectName(QString::fromUtf8("lineEdit_pret"));
        lineEdit_pret->setEnabled(false);
        lineEdit_pret->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        lineEdit_pret->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_pret, 0, 0, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(988, 22, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 2, 0, 1, 1);


        gridLayout_5->addWidget(widget_2, 4, 0, 1, 3);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        horizontalLayout_15 = new QHBoxLayout(groupBox);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        dateTimeEdit = new QDateTimeEdit(groupBox);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        horizontalLayout_15->addWidget(dateTimeEdit);

        dateTimeEdit_2 = new QDateTimeEdit(groupBox);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));

        horizontalLayout_15->addWidget(dateTimeEdit_2);


        gridLayout_2->addWidget(groupBox, 1, 1, 1, 1);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 3, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_3->addWidget(checkBox_4, 0, 3, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_3->addWidget(checkBox_2, 0, 1, 1, 1);

        checkBox_1 = new QCheckBox(groupBox_2);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setEnabled(true);
        checkBox_1->setCheckable(true);
        checkBox_1->setChecked(false);

        gridLayout_3->addWidget(checkBox_1, 0, 0, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_3->addWidget(checkBox_5, 0, 4, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_3->addWidget(checkBox_3, 0, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 2, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 2, 0, 1, 3);

        lineEdit_title = new QLineEdit(centralwidget);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));
        lineEdit_title->setEnabled(false);
        lineEdit_title->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        lineEdit_title->setInputMethodHints(Qt::ImhNone);
        lineEdit_title->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_title, 1, 0, 1, 3);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));

        gridLayout_5->addWidget(pushButton_2, 5, 0, 1, 3);

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
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "percent", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "bars", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "CA", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "canal bancaire", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "percent", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "bars", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "CA", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "canal boursier", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "canal assurance", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "percent", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "bars", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "CA", nullptr));
        pushButton_retour->setText(QCoreApplication::translate("MainWindow", "retour_sur_main", nullptr));
        lineEdit_pret->setText(QCoreApplication::translate("MainWindow", "PR\303\212T", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "modif_chart", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "modif_date", nullptr));
        dateTimeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "dd/MM/yyyy", nullptr));
        dateTimeEdit_2->setDisplayFormat(QCoreApplication::translate("MainWindow", "dd/MM/yyyy", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "ok", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "choisir_agneces", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "agence 4", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "agence 2", nullptr));
        checkBox_1->setText(QCoreApplication::translate("MainWindow", "agence 1", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "agence 5", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "agence 3", nullptr));
        lineEdit_title->setText(QCoreApplication::translate("MainWindow", " La Banque", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "info_on_pr\303\252t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
