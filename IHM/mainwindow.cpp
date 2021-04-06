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
#include <QPieSeries>

#include <QSound>
#include <QCoreApplication>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>


#include <QString>


//TODO create another file to include most of the func "not important"

using namespace QtCharts;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox_1->setChecked(true);
    ui->checkBox_2->setChecked(true);
    ui->checkBox_3->setChecked(true);
    ui->checkBox_4->setChecked(true);
    ui->checkBox_5->setChecked(true);

    ui->graphicsView_pret->hide();
    ui->pushButton_retour->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->lineEdit_pret->hide();
    ui->textEdit->hide();

    QObject::connect(ui->pushButton_retour, SIGNAL(released()), this, SLOT(on_pushButton_retour_pressed()));
    QObject::connect(ui->pushButton, SIGNAL(released()), this, SLOT(on_pushButton_pressed()));
    QObject::connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(on_pushButton_2_pressed()));
    QObject::connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(on_pushButton_3_pressed()));
    QObject::connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(on_pushButton_4_pressed()));
    QObject::connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(on_pushButton_5_pressed()));
    QObject::connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(on_pushButton_6_pressed()));
    QObject::connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(on_pushButton_7_pressed()));
    QObject::connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(on_pushButton_8_pressed()));
    QObject::connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(on_pushButton_9_pressed()));
    QObject::connect(ui->pushButton_10, SIGNAL(released()), this, SLOT(on_pushButton_10_pressed()));
    QObject::connect(ui->pushButton_11, SIGNAL(released()), this, SLOT(on_pushButton_11_pressed()));

    createConnection();
    refreshCharts(1);
    refreshCharts(2);
    refreshCharts(3);
    refreshCharts(-1);

}

//on traite ici les bdd et les conditions "date et nombre d'agence"
void MainWindow::refreshCharts(int x)
{
    QSqlQuery query;
    bool x1 ,x2 ,x3 ,x4 ,x5;
    std::string temp;
    int final =0;

    int y , m, d , y2 , m2 , d2;
    string sy1 ,sm1 ,sd1 ,sy2 ,sm2 ,sd2;

    QDate  time1 = ui->dateTimeEdit->date();
    QDate  time2 = ui->dateTimeEdit_2->date();
    time1.getDate(&y,&m,&d);
    time2.getDate(&y2 , &m2 ,&d2);


    x1 = ui->checkBox_1->isChecked();
    x2 = ui->checkBox_2->isChecked();
    x3 = ui->checkBox_3->isChecked();
    x4 = ui->checkBox_4->isChecked();
    x5 = ui->checkBox_5->isChecked();
    int count = 0;
    std::string str;
    std::string strtime = "";


    x1 ? str.append("nom_agence = 'agence_a' ") :str.append("");
    if(x1)
        count++;
    x2 ? count== 0? str.append("nom_agence = 'agence_b' ") : str.append(" OR nom_agence = 'agence_b' ") :str.append("");
    if(x2)
        count++;
    x3 ? count== 0? str.append("nom_agence = 'agence_c' ") : str.append(" OR nom_agence = 'agence_c' ") :str.append("");
    if(x3)
        count++;
    x4 ? count== 0? str.append("nom_agence = 'agence_d' ") : str.append(" OR nom_agence = 'agence_d' ") :str.append("");
    if(x4)
        count++;
    x5 ? count== 0? str.append("nom_agence = 'agence_e' ") : str.append(" OR nom_agence = 'agence_e' ") :str.append("");
    if(x4)
        count++;


//    if(m< 10 )
//    {
//        sm1.append("0"+to_string(m));
//    }
//    else
//    {
//       sm1.append(to_string(m));
//    }
//    if(d< 10 )
//    {
//        sd1.append("0"+to_string(d));
//    }
//    else
//    {
//       sd1.append(to_string(d));
//    }
//    if(m2< 10 )
//    {
//        sm2.append("0"+to_string(m2));
//    }
//    else
//    {
//       sm2.append(to_string(m2));
//    }
//    if(d2< 10 )
//    {
//        sd2.append("0"+to_string(d2));
//    }
//    else
//    {
//       sd2.append(to_string(d2));
//    }
//    sy1= to_string(y);
//    sy2 = to_string(y2);
    sy1 = y<10 ? "0"+ to_string(y) : to_string(y) ;
    sm1 = m<10 ? "0"+ to_string(m) : to_string(m) ;
    sd1 = d<10 ? "0"+ to_string(d) : to_string(d) ;
    sy2 = y2<10 ? "0"+ to_string(y2) : to_string(y2) ;
    sm2 = m2<10 ? "0"+ to_string(m2) : to_string(m2) ;
    sd2 = d2<10 ? "0"+ to_string(d2) : to_string(d2) ;

    if( (y != y2 || m != m2 || d != d2))
    {
        strtime.append(" date BETWEEN ");
        strtime.append(" '" + sy1 + "-"+ sm1 +"-"+ sd1 +"' ");
        strtime.append(" AND '" + sy2 + "-"+ sm2 +"-"+ sd2+"' ");
    }
    if(count)
        str.append(" ) ;");

    if(x == 1 )
    {

        QBarSet *set0 = new QBarSet("P_hab");
        QBarSet *set1 = new QBarSet("P_auto");
        QBarSet *set2 = new QBarSet("C_courant");
        QBarSet *set3 = new QBarSet("C_epargne");
        QBarSet *set4 = new QBarSet("autre");
        temp = "Select count(*) from canal_bancaire where type = 'pret_hab' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }
        if(count)
        {
            temp.append("AND ( ");
        }
        temp.append(str);

        QString tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set0  << prix ;
        }
        temp = "Select count(*) from canal_bancaire where type = 'pret_auto'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }
        if(count)
            temp.append("AND ( ");
        temp.append(str);

        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set1  << prix ;
        }
        temp = "Select count(*) from canal_bancaire where type = 'compte_courant'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set2  << prix ;
        }

        temp = "Select count(*) from canal_bancaire where type = 'compte_epargne'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
//        printf("%s\n",tmp1.toStdString().c_str());
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set3  << prix ;
        }
        temp = "Select count(*) from canal_bancaire where type = 'autre'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set4  << prix ;
        }


        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Produits bancaires");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories << "Volume";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,10);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->graphicsView->setChart(chart);

    }
    else if(x == 2)
    {
        QBarSet *set0 = new QBarSet("velo");
        temp = "Select count(*) from canal_assurance where type = 'assu_velo' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }
        if(count)
            temp.append("AND (");
        temp.append(str);
        QString tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set0  << prix ;
        }
        QBarSet *set1 = new QBarSet("ordi");
        temp = "Select count(*) from canal_assurance where type = 'assu_ordi' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }
        if(count)
            temp.append("AND (");
        temp.append(str);

        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set1  << prix ;
        }
        QBarSet *set2 = new QBarSet("autre");
        temp = "Select count(*) from canal_assurance where type = 'autre' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND (");
        temp.append(str);

        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set2  << prix ;
        }

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Produits assurances");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories << "volume";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,10);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->graphicsView_2->setChart(chart);


    }
    else if( x== 3 )
    {
        QBarSet *set0 = new QBarSet("Action");
        temp = "Select count(*) from canal_boursier where ";
        if(strtime.length() != 0)
        {
            temp.append(strtime);
            if(count)
                temp.append("AND ( ");

        }
        else if(count)
        {
            temp.append(" ( ");
        }


        temp.append(str);
                QString tmp1 = QString::fromStdString(temp);

        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set0  << prix ;
        }

        QBarSeries *series = new QBarSeries();
        series->append(set0);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Produits boursiers");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories << "Volume";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,10);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->graphicsView_3->setChart(chart);

    }
    else if (x == 4)
    {
        QBarSet *set0 = new QBarSet("P_hab");
        QBarSet *set1 = new QBarSet("p_auto");
        QBarSet *set2 = new QBarSet("C_courant");
        QBarSet *set3 = new QBarSet("C_epargne");
        QBarSet *set4 = new QBarSet("autre");
        temp = "Select prix from canal_bancaire where type = 'pret_hab' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        QString tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
             final += prix ;
        }
        *set0 << final;
        temp = "Select prix from canal_bancaire where type = 'pret_auto'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix ;
       }
       *set1 << final;
        temp = "Select prix from canal_bancaire where type = 'compte_courant'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix;
        }
        *set2  << final ;
        temp = "Select prix from canal_bancaire where type = 'compte_epargne'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix;
        }
        *set3  << final ;
        temp = "Select prix from canal_bancaire where type = 'autre'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix;
        }
        *set4  << final ;

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Produits bancaires");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories << "CA";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,50000);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->graphicsView->setChart(chart);

    }
    else if (x == 5)
    {
        QBarSet *set0 = new QBarSet("velo");
        temp = "Select prix from canal_assurance where type = 'assu_velo' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        QString tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix ;
       }
       *set0 << final;
        QBarSet *set1 = new QBarSet("ordi");
        temp = "Select prix from canal_assurance where type = 'assu_ordi' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);

        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix ;
       }
       *set1 << final;
        QBarSet *set2 = new QBarSet("autre");
        temp = "Select prix from canal_assurance where type = 'autre' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND (");
        temp.append(str);

        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix ;
       }
       *set2 << final;

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Produits assurances");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories << "CA";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,30000);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->graphicsView_2->setChart(chart);

    }
    else if (x == 6)
    {
        QBarSet *set0 = new QBarSet("action");
        temp = "Select prix from canal_boursier where ";
        if(strtime.length() != 0)
        {
            temp.append(strtime);
        }

        if(count)
            temp.append(" ( ");
        temp.append(str);

        QString tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final  += prix ;
        }
        *set0 << final ;

        QBarSeries *series = new QBarSeries();
        series->append(set0);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Produits boursiers");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories << "CA";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,100000);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->graphicsView_3->setChart(chart);
    }
    else
    {
        int f0=0,f1=0,f2=0,f3=0,f4=0,f5=0,f6=0,f7 =0,f8 =0 , f9 = 0;
        QBarSet *set0 = new QBarSet("P_hab");
        QBarSet *set1 = new QBarSet("P_auto");
        QBarSet *set2 = new QBarSet("C_courant");
        QBarSet *set3 = new QBarSet("C_epargne");
        QBarSet *set4 = new QBarSet("autre");

        temp = "Select prix from canal_bancaire where type = 'pret_hab' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }
        if(count)
        {
            temp.append("AND ( ");
        }
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        f0 = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
             f0 += prix ;
        }
        *set0 << f0;


        // pour Volume
        temp = "Select count(*) from canal_bancaire where type = 'pret_hab' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }
        if(count)
        {
            temp.append("AND ( ");
        }
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        f1 = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
             f1 += prix ;
        }





        temp = "Select prix from canal_bancaire where type = 'pret_auto'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        f2 = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            f2 += prix ;
       }
       *set1 << f2;

        temp = "Select count(*) from canal_bancaire where type = 'pret_auto'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        f3 = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            f3 += prix ;
       }


        temp = "Select prix from canal_bancaire where type = 'compte_courant'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        f4 = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            f4 += prix;
        }
        *set2  << f4 ;


        temp = "Select count(*) from canal_bancaire where type = 'compte_courant'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        f5 = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            f5 += prix;
        }





        temp = "Select prix from canal_bancaire where type = 'compte_epargne'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        f6 = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            f6 += prix;
        }
        *set3  << f6 ;



        temp = "Select count(*) from canal_bancaire where type = 'compte_epargne'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        f7 = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            f7 += prix;
        }



        temp = "Select prix from canal_bancaire where type = 'autre'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        f8 = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            f8 += prix;
        }
        *set4  << f8;


        temp = "Select count(*) from canal_bancaire where type = 'autre'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        f9 = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            f9 += prix;
        }

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("detail Canal bancaire");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories << "CA";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,50000);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        ui->graphicsView_pret->setChart(chart);
        ui->textEdit->clear();
        ui->textEdit->append("hello world!");
        ui->textEdit->append("On a Volume de  :"+ QString::fromUtf8(to_string(f1 + f3 + f5 +f7+ f9).c_str()));
        ui->textEdit->append("On a CA de  :"+ QString::fromUtf8(to_string(f0 + f2 + f4 +f6+ f8).c_str()));
        ui->textEdit->append("best agence");
        ui->textEdit->append("best client");
        ui->textEdit->append("best banquier");

    }



}

//traite aussi les conditions avant l'affichage.
void MainWindow::percentchart(int x)
{
    QSqlQuery query;
    bool x1 ,x2 ,x3 ,x4 ,x5;
    std::string temp;
    int final =0;

    int y , m, d , y2 , m2 , d2;
    string sy1 ,sm1 ,sd1 ,sy2 ,sm2 ,sd2;

    QDate  time1 = ui->dateTimeEdit->date();
    QDate  time2 = ui->dateTimeEdit_2->date();
    time1.getDate(&y,&m,&d);
    time2.getDate(&y2 , &m2 ,&d2);


    x1 = ui->checkBox_1->isChecked();
    x2 = ui->checkBox_2->isChecked();
    x3 = ui->checkBox_3->isChecked();
    x4 = ui->checkBox_4->isChecked();
    x5 = ui->checkBox_5->isChecked();
    int count = 0;
    std::string str;
    std::string strtime = "";


    x1 ? str.append("nom_agence = 'agence_a' ") :str.append("");
    if(x1)
        count++;
    x2 ? count== 0? str.append("nom_agence = 'agence_b' ") : str.append(" OR nom_agence = 'agence_b' ") :str.append("");
    if(x2)
        count++;
    x3 ? count== 0? str.append("nom_agence = 'agence_c' ") : str.append(" OR nom_agence = 'agence_c' ") :str.append("");
    if(x3)
        count++;
    x4 ? count== 0? str.append("nom_agence = 'agence_d' ") : str.append(" OR nom_agence = 'agence_d' ") :str.append("");
    if(x4)
        count++;
    x5 ? count== 0? str.append("nom_agence = 'agence_e' ") : str.append(" OR nom_agence = 'agence_e' ") :str.append("");
    if(x4)
        count++;

    sy1 = y<10 ? "0"+ to_string(y) : to_string(y) ;
    sm1 = m<10 ? "0"+ to_string(m) : to_string(m) ;
    sd1 = d<10 ? "0"+ to_string(d) : to_string(d) ;
    sy2 = y2<10 ? "0"+ to_string(y2) : to_string(y2) ;
    sm2 = m2<10 ? "0"+ to_string(m2) : to_string(m2) ;
    sd2 = d2<10 ? "0"+ to_string(d2) : to_string(d2) ;

    if( (y != y2 || m != m2 || d != d2))
    {
        strtime.append(" date BETWEEN ");
        strtime.append(" '" + sy1 + "-"+ sm1 +"-"+ sd1 +"' ");
        strtime.append(" AND '" + sy2 + "-"+ sm2 +"-"+ sd2+"' ");
    }
    if(count)
        str.append(" ) ;");
    if(x == 1 )
    {
        QBarSet *set0 = new QBarSet("P_hab");
        QBarSet *set1 = new QBarSet("P_auto");
        QBarSet *set2 = new QBarSet("C_courant");
        QBarSet *set3 = new QBarSet("C_epargne");
        QBarSet *set4 = new QBarSet("autre");

        temp = "Select prix from canal_bancaire where type = 'pret_hab' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        QString tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
             final += prix ;
        }
        *set0 << final;
        temp = "Select prix from canal_bancaire where type = 'pret_auto'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix ;
       }
       *set1 << final;
        temp = "Select prix from canal_bancaire where type = 'compte_courant'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix;
        }
        *set2  << final ;
        temp = "Select prix from canal_bancaire where type = 'compte_epargne'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix;
        }
        *set3  << final ;
        temp = "Select prix from canal_bancaire where type = 'autre'";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix;
        }
        *set4  << final ;





        QPercentBarSeries *series = new QPercentBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple percentbarchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories << "Volume";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
        QValueAxis *axisY = new QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);


        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        ui->graphicsView->setChart(chart);

    }
    else if (x== 2 )
    {


        QBarSet *set0 = new QBarSet("velo");
        temp = "Select prix from canal_assurance where type = 'assu_velo' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        QString tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix ;
       }
       *set0 << final;
        QBarSet *set1 = new QBarSet("ordi");
        temp = "Select prix from canal_assurance where type = 'assu_ordi' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND ( ");
        temp.append(str);

        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix ;
       }
       *set1 << final;
        QBarSet *set2 = new QBarSet("autre");
        temp = "Select prix from canal_assurance where type = 'autre' ";
        if(strtime.length() != 0)
        {
            temp.append("AND");
            temp.append(strtime);
        }

        if(count)
            temp.append("AND (");
        temp.append(str);

        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final += prix ;
       }
       *set2 << final;

        QPercentBarSeries *series = new QPercentBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple percentbarchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories << "Volume";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
        QValueAxis *axisY = new QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);


        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        ui->graphicsView_2->setChart(chart);








    }
    else
    {
        QBarSet *set0 = new QBarSet("action");
        temp = "Select prix from canal_boursier where ";
        if(strtime.length() != 0)
        {
            temp.append(strtime);
        }

        if(count)
            temp.append(" ( ");
        temp.append(str);

        QString tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        final = 0;
        while (query.next()) {
            int prix = query.value(0).toInt();
            final  += prix ;
        }
        *set0 << final ;

        QPercentBarSeries *series = new QPercentBarSeries();
        series->append(set0);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple percentbarchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories << "Volume";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
        QValueAxis *axisY = new QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);


        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        ui->graphicsView_3->setChart(chart);
    }

}

//ici on check le date et checkboxes et on met a jour les charts
void MainWindow::on_pushButton_pressed()
{

    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_2.wav");

    refreshCharts(1);
    refreshCharts(2);
    refreshCharts(3);
    refreshCharts(-1);
    return;
}


void MainWindow::on_pushButton_2_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_2.wav");
    ui->textEdit->show();
    ui->graphicsView_pret->show();
    ui->graphicsView->hide();
    ui->graphicsView_2->hide();
    ui->graphicsView_3->hide();
    ui->pushButton_retour->show();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->lineEdit_pret->show();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    return;
}

void MainWindow::on_pushButton_retour_pressed()
{

    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_2.wav");
    ui->textEdit->hide();
    ui->graphicsView_pret->hide();
    ui->graphicsView->show();
    ui->graphicsView_2->show();
    ui->graphicsView_3->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->pushButton_9->show();
    ui->pushButton_10->show();
    ui->pushButton_11->show();
    refreshCharts(1);
    refreshCharts(2);
    refreshCharts(3);
    ui->pushButton_retour->hide();
    ui->lineEdit_pret->hide();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    //refresh chart

    return;
}
void MainWindow::on_pushButton_3_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_3->hide();
    ui->pushButton_6->show();
    ui->pushButton_9->show();

    percentchart(1);
}
void MainWindow::on_pushButton_4_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_4->hide();
    ui->pushButton_7->show();
    ui->pushButton_10->show();

    percentchart(2);
}
void MainWindow::on_pushButton_5_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");

    ui->pushButton_5->hide();
    ui->pushButton_8->show();
    ui->pushButton_11->show();
    percentchart(3);
}
void MainWindow::on_pushButton_6_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");

    ui->pushButton_6->hide();
    ui->pushButton_3->show();
    ui->pushButton_9->show();
    refreshCharts(1);
}

void MainWindow::on_pushButton_7_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");

    ui->pushButton_7->hide();
    ui->pushButton_4->show();
    ui->pushButton_10->show();
    refreshCharts(2);
}

void MainWindow::on_pushButton_8_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_8->hide();
    ui->pushButton_5->show();
    ui->pushButton_11->show();
    refreshCharts(3);
}

void MainWindow::on_pushButton_9_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_9->hide();
    ui->pushButton_3->show();
    ui->pushButton_6->show();
    refreshCharts(4);

}
void MainWindow::on_pushButton_10_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_10->hide();
    ui->pushButton_4->show();
    ui->pushButton_7->show();
    refreshCharts(5);
}
void MainWindow::on_pushButton_11_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_11->hide();
    ui->pushButton_5->show();
    ui->pushButton_8->show();
    refreshCharts(6);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*##########################################################################################*/
bool MainWindow::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":IHM_db_AD:");
    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
        QObject::tr("Unable to establish a database connection.\n"
                "This example needs SQLite support. Please read "
                "the Qt SQL driver documentation for information how "
                "to build it.\n\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;
    query.exec("create table canal_bancaire (id int primary key, "
             "nom_agence varchar(20),"
             "type varchar(20),"
             "prix int,"
             "durée int,"
             "montant_an int,"
             "date DATE,"
             "banquier varchar(20),"
             "client varchar(20))");

    query.exec("insert into canal_bancaire values(1,'agence_a', 'pret_hab', 5000 , 2 , 1000 , '2021-03-04' , 'bob' , 'ali')");
    query.exec("insert into canal_bancaire values(2,'agence_b', 'pret_hab', 35000 , 5 , 2000 , '2021-02-04' , 'alice' , 'client_2')");
    query.exec("insert into canal_bancaire values(3,'agence_a', 'pret_hab', 6000 , 10 , 5000 , '2021-04-04' , 'bro' , ','client_3')");

    query.exec("insert into canal_bancaire values(4,'agence_b', 'pret_auto', 1000 , 4 , 500 , '2021-04-04' , 'bob' , 'ali')");
    query.exec("insert into canal_bancaire values(5,'agence_a', 'pret_auto', 8250 , 6 , 200 , '2021-04-01' , 'dude' , 'client_2')");
    query.exec("insert into canal_bancaire values(6,'agence_c', 'pret_auto', 5000 , 8 , 350 , '2021-04-06' , 'bob' , 'client_5')");

    query.exec("insert into canal_bancaire values(7,'agence_c', 'compte_courant', 1000 , 10 , 2340 , '2021-04-08' , 'alice' , 'bob')");
    query.exec("insert into canal_bancaire values(8,'agence_e', 'compte_courant', 2500 , 15 , 1234 , '2021-04-09' , 'bob' , 'mec')");
    query.exec("insert into canal_bancaire values(9,'agence_d', 'compte_courant', 10000 , 20 , 4132 , '2021-04-10' , 'bro' , 'darwich')");

    query.exec("insert into canal_bancaire values(10,'agence_d', 'compte_epargne', 1234 , 5 , 123 , '2021-04-21' , 'dude' , 'bob')");
    query.exec("insert into canal_bancaire values(11,'agence_c', 'compte_epargne', 4134 , 7 , 3121 , '2021-03-04' , 'bob' , 'ali')");
    query.exec("insert into canal_bancaire values(12,'agence_d', 'compte_epargne', 10034 , 9 , 3123 , '2021-02-04' , 'alice' , 'client_3')");
    query.exec("insert into canal_bancaire values(13,'agence_e', 'autre', 200 , 15 , 1234 , '2021-04-09' , 'bob' , 'mec')");
    query.exec("insert into canal_bancaire values(14,'agence_e', 'autre', 1200 , 15 , 1234 , '2021-04-09' , 'bob' , 'mec')");


    query.exec("create table canal_assurance(id int primary key,"
    "nom_agence varchar(20),"
    "prix int,"
    "type varchar(20),"
    "duree_min int ,"
    "date DATE,"
    "banquier varchar(20),"
    "client  varchar(20))");

    query.exec("insert into canal_assurance values(1, 'agence_a', 1000,'assu_velo', 1, '2021-03-04' ,'bob', 'ali' )");
    query.exec("insert into canal_assurance values(2, 'agence_a', 4000,'assu_ordi', 2,  '2021-03-04' ,'alice', 'client_2') ");
    query.exec("insert into canal_assurance values(3, 'agence_a', 1234,'assu_velo' ,12,  '2021-03-04','bro', 'mec') ");
    query.exec("insert into canal_assurance values(4, 'agence_b',  413,'assu_ordi', 3,  '2021-03-04','dude', 'darwich') ");
    query.exec("insert into canal_assurance values(5, 'agence_b',  324,'assu_velo', 4,  '2021-03-04','bob, 'ali' )");
    query.exec("insert into canal_assurance values(6, 'agence_b',  423,'assu_ordi', 5,  '2021-03-04','bro', 'client_4') ");
    query.exec("insert into canal_assurance values(7, 'agence_c', 5123,'assu_velo', 6,  '2021-03-04','alice', 'client_3') ");
    query.exec("insert into canal_assurance values(8, 'agence_c',10123,'assu_ordi', 8,  '2021-03-04','alice', 'client_3') ");
    query.exec("insert into canal_assurance values(9, 'agence_c',  123,'assu_velo', 9,  '2021-03-04','bro', 'client_5')");
    query.exec("insert into canal_assurance values(10, 'agence_d',1023,'assu_ordi', 2,  '2021-03-04','bob', 'ali') ");
    query.exec("insert into canal_assurance values(11, 'agence_d',1123,'assu_ordi', 3,  '2021-03-04','dude', 'client_3') ");
    query.exec("insert into canal_assurance values(12, 'agence_d',4131,'assu_ordi', 4,  '2021-03-04','bob', 'client_5')");
    query.exec("insert into canal_assurance values(13, 'agence_e', 213,'autre', 6,  '2021-03-04','bob', 'ali') ");
    query.exec("insert into canal_assurance values(14, 'agence_e',1232,'assu_ordi', 8,  '2021-03-04','alice', 'darwich') ");
    query.exec("insert into canal_assurance values(15, 'agence_e',4131,'autre', 9,  '2021-03-04','bob', 'client_3') ");




    query.exec("create table canal_boursier(id int primary key,"
              "prix int ,"
             "nom_agence varchar(20),"
               "date DATE,"
             "banquier varchar(20),"
             "client  varchar(20))");

    query.exec("insert into canal_boursier values(1,1234, 'agence_a',  '2021-03-04','bob', 'client_1') ");
    query.exec("insert into canal_boursier values(2,4311, 'agence_b',  '2021-03-04','bro', 'client_2') ");
    query.exec("insert into canal_boursier values(3,123, 'agence_c',  '2021-03-04','dude', 'client_3') ");
    query.exec("insert into canal_boursier values(4,4543, 'agence_d',  '2021-03-04','alice', 'ali') ");
    query.exec("insert into canal_boursier values(5,67353, 'agence_e',  '2021-03-04','bob', 'darwich') ");
    query.exec("insert into canal_boursier values(6,1234, 'agence_a',  '2021-03-04' ,'bro', 'mec') ");

      return true;
  }




