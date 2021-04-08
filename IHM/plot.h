#ifndef PLOT_H
#define PLOT_H

#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <iostream>

#include <QChart>
#include <QAreaSeries>
#include <QLineSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QPercentBarSeries>

#include <QTextDocument>

#include <QSqlQuery>

#include <QTextEdit>


using namespace QtCharts;
using namespace std;




void refreshCharts(int x, Ui::MainWindow *ui);
void percentchart(int x,Ui::MainWindow *ui);
void caCharts(int x,Ui::MainWindow *ui);

void func(QBarSet *set0 , QSqlQuery query);
void func_2(QBarSet *set0 , QSqlQuery query);


void setchartparam(QChart *chart , QBarSeries *series , const char* str1,const char * str2 , int range);
void setchartparam_2(QChart *chart , QPercentBarSeries *series , const char* str1,const char * str2 );



#endif // PLOT_H
