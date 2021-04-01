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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_7;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBox_3;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox_4;
    QSpacerItem *horizontalSpacer_17;
    QCheckBox *checkBox_5;
    QSpacerItem *horizontalSpacer_18;
    QCheckBox *checkBox_11;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *verticalSpacer_5;
    QCalendarWidget *calendarWidget;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_5;
    QtCharts::QChartView *graphicsView;
    QSpacerItem *horizontalSpacer_2;
    QtCharts::QChartView *graphicsView_3;
    QSpacerItem *horizontalSpacer;
    QtCharts::QChartView *graphicsView_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_9;
    QtCharts::QChartView *graphicsView_7;
    QSpacerItem *verticalSpacer_8;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(802, 822);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_7 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_7);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_7->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_7);

        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_14->addWidget(checkBox_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_4);

        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_14->addWidget(checkBox_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_3);

        checkBox_4 = new QCheckBox(centralwidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        horizontalLayout_14->addWidget(checkBox_4);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_17);

        checkBox_5 = new QCheckBox(centralwidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        horizontalLayout_14->addWidget(checkBox_5);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_18);

        checkBox_11 = new QCheckBox(centralwidget);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));

        horizontalLayout_14->addWidget(checkBox_11);

        horizontalSpacer_19 = new QSpacerItem(28, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_19);


        verticalLayout_7->addLayout(horizontalLayout_14);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout_7->addWidget(calendarWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_7->addWidget(label_3);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

        graphicsView = new QtCharts::QChartView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout_13->addWidget(graphicsView);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);

        graphicsView_3 = new QtCharts::QChartView(centralwidget);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));

        horizontalLayout_13->addWidget(graphicsView_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);

        graphicsView_2 = new QtCharts::QChartView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));

        horizontalLayout_13->addWidget(graphicsView_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);


        verticalLayout_7->addLayout(horizontalLayout_13);

        verticalSpacer_6 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_6);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_6->addWidget(label_2);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_9);

        graphicsView_7 = new QtCharts::QChartView(centralwidget);
        graphicsView_7->setObjectName(QString::fromUtf8("graphicsView_7"));

        verticalLayout_6->addWidget(graphicsView_7);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalSpacer_8 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_8);

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
        label->setText(QCoreApplication::translate("MainWindow", "                                                                                                      LA BANQUE ", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "agence 1", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "agence 2", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "agence 3", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "agence 4", nullptr));
        checkBox_11->setText(QCoreApplication::translate("MainWindow", "agence 5", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "                               ca                                                                            cb                                                              cas ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "                                                                                                            pr\303\252t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
