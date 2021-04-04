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

    QObject::connect(ui->pushButton_retour, SIGNAL(released()), this, SLOT(on_pushButton_retour_pressed()));
    QObject::connect(ui->pushButton, SIGNAL(released()), this, SLOT(on_pushButton_pressed()));
    QObject::connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(on_pushButton_2_pressed()));
    QObject::connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(on_pushButton_3_pressed()));
    QObject::connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(on_pushButton_4_pressed()));
    QObject::connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(on_pushButton_5_pressed()));
    QObject::connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(on_pushButton_6_pressed()));
    QObject::connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(on_pushButton_7_pressed()));
    QObject::connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(on_pushButton_8_pressed()));

    createConnection();
    refreshCharts(1);
    refreshCharts(2);
    refreshCharts(3);
    refreshCharts(4);

}

//on traite ici les bdd et les conditions "date et nombre d'agence"
void MainWindow::refreshCharts(int x)
{
    QSqlQuery query;
    bool x1 ,x2 ,x3 ,x4 ,x5;
    std::string temp;

    x1 = ui->checkBox_1->isChecked();
    x2 = ui->checkBox_2->isChecked();
    x3 = ui->checkBox_3->isChecked();
    x4 = ui->checkBox_4->isChecked();
    x5 = ui->checkBox_5->isChecked();
    int count = 0;
     std::string str;


     x1 ? str.append("nom_agence = 'agence_a' ") :str.append("");
     if(x1)
         count++;
     x2 ? count== 0? str.append("nom_agence = 'agence_b'") : str.append("OR nom_agence = 'agence_b'") :str.append("");
     if(x2)
         count++;
     x3 ? count== 0? str.append("nom_agence = 'agence_c'") : str.append("OR nom_agence = 'agence_c'") :str.append("");
     if(x3)
         count++;
     x4 ? count== 0? str.append("nom_agence = 'agence_d'") : str.append("OR nom_agence = 'agence_d'") :str.append("");
     if(x4)
         count++;
     x5 ? count== 0? str.append("nom_agence = 'agence_e'") : str.append("OR nom_agence = 'agence_e'") :str.append("");
     if(x4)
         count++;
     str.append(";");

    if(x == 1 )
    {

        QBarSet *set0 = new QBarSet("pret_hab");
        QBarSet *set1 = new QBarSet("pret_auto");
        QBarSet *set2 = new QBarSet("compte_courant");
        QBarSet *set3 = new QBarSet("compte_epargne");
        QBarSet *set4 = new QBarSet("autre");
        temp = "Select prix from canal_bancaire where type = 'pret_hab' ";
        if(count)
            temp.append("AND ");
        temp.append(str);

//        printf("%s\n",temp.c_str());
        QString tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set0  << prix ;
        }
        temp = "Select prix from canal_bancaire where type = 'pret_auto'";
        if(count)
            temp.append("AND ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set1  << prix ;
        }
        temp = "Select prix from canal_bancaire where type = 'compte_courant'";
        if(count)
            temp.append("AND ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set2  << prix ;
        }

        temp = "Select prix from canal_bancaire where type = 'compte_epargne'";
        if(count)
            temp.append("AND ");
        temp.append(str);
        tmp1 = QString::fromStdString(temp);
        query.exec(tmp1);
        while (query.next()) {
            int prix = query.value(0).toInt();
            *set3  << prix ;
        }
        temp = "Select prix from canal_bancaire where type = 'autre'";
        if(count)
            temp.append("AND ");
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
        chart->setTitle("Simple barchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories << "one";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,1500);
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
        QBarSet *set0 = new QBarSet("assurance");
        temp = "Select prix from canal_assurance where ";
        temp.append(str);

//        printf("%s\n",temp.c_str());
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
        chart->setTitle("Simple barchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories << "one";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,1500);
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
        QBarSet *set0 = new QBarSet("bourse");
        temp = "Select count(*) from canal_boursier where ";
        temp.append(str);

//        printf("%s\n",temp.c_str());
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
        chart->setTitle("Simple barchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories << "one";
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
    else
    {

        QLineSeries *series0 = new QLineSeries();
        QLineSeries *series1 = new QLineSeries();
        *series0 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6) << QPointF(16, 7) << QPointF(18, 5);
        *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3) << QPointF(16, 4) << QPointF(18, 3);
        QAreaSeries *series2 = new QAreaSeries(series0, series1);
        series2->setName("Batman");
        QPen pen(0x059605);
        pen.setWidth(3);
        series2->setPen(pen);
        QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
        gradient.setColorAt(0.0, 0x3cc63c);
        gradient.setColorAt(1.0, 0x26f626);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        series2->setBrush(gradient);
        QChart *chart1 = new QChart();
        chart1->addSeries(series2);
        chart1->setTitle("Simple areachart example");
        chart1->createDefaultAxes();
        chart1->axes(Qt::Horizontal).first()->setRange(0, 20);
        chart1->axes(Qt::Vertical).first()->setRange(0, 10);

        ui->graphicsView_pret->setChart(chart1);
    }



}

//traite aussi les conditions avant l'affichage.
void MainWindow::percentchart(int x)
{
    if(x == 1 )
    {
//        QBarSet *set0 = new QBarSet("Jane");
//        QBarSet *set1 = new QBarSet("John");
//        QBarSet *set2 = new QBarSet("Axel");
//        QBarSet *set3 = new QBarSet("Mary");
//        QBarSet *set4 = new QBarSet("Samantha");

//        *set0 << 1 << 2 << 3 << 4 << 5 << 6;
//        *set1 << 5 << 0 << 0 << 4 << 0 << 7;
//        *set2 << 3 << 5 << 8 << 13 << 8 << 5;
//        *set3 << 5 << 6 << 7 << 3 << 4 << 5;
//        *set4 << 9 << 7 << 5 << 3 << 1 << 2;

//        QPercentBarSeries *series = new QPercentBarSeries();
//        series->append(set0);
//        series->append(set1);
//        series->append(set2);
//        series->append(set3);
//        series->append(set4);
//        QChart *chart = new QChart();
//        chart->addSeries(series);
//        chart->setTitle("Simple percentbarchart example");
//        chart->setAnimationOptions(QChart::SeriesAnimations);

//        QStringList categories;
//        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
//        QBarCategoryAxis *axisX = new QBarCategoryAxis();
//        axisX->append(categories);
//        chart->addAxis(axisX, Qt::AlignBottom);
//        series->attachAxis(axisX);
//        QValueAxis *axisY = new QValueAxis();
//        chart->addAxis(axisY, Qt::AlignLeft);
//        series->attachAxis(axisY);


//        chart->legend()->setVisible(true);
//        chart->legend()->setAlignment(Qt::AlignBottom);


        QPieSeries *series = new QPieSeries();
        series->setHoleSize(0.35);
        series->append("Protein 4.2%", 4.2);
//        QPieSlice *slice = series->append("Fat 15.6%", 15.6);
//        slice->setExploded();
//        slice->setLabelVisible();
        series->append("Fat 15.6%", 15.6);
        series->append("Other 23.8%", 23.8);
        series->append("Carbs 56.4%", 56.4);

        QChartView *chartView = new QChartView();
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->chart()->setTitle("Donut with a lemon glaze (100g)");
        chartView->chart()->addSeries(series);
        chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
        chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);
        chartView->chart()->legend()->setFont(QFont("Arial", 7));


        ui->graphicsView->setChart(chartView->chart());
    }
    else if (x== 2 )
    {

        QPieSeries *series = new QPieSeries();
        series->append("Jane", 1);
        series->append("Joe", 2);
        series->append("Andy", 3);
        series->append("Barbara", 4);
        series->append("Axel", 5);

        QPieSlice *slice = series->slices().at(1);
        slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setBrush(Qt::green);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple piechart example");
        chart->legend()->hide();

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);


        ui->graphicsView_2->setChart(chart);



    }
    else
    {
        QPieSeries *series = new QPieSeries();

        series->append("C++", 80);
        series->append("Python", 70);
        series->append("Java", 50);
        series->append("C#", 40);
        series->append("PHP", 30);


//        QPieSlice *slice = series->slices().at(1);
//        slice->setExploded(true);
//        slice->setLabelVisible(true);
//        slice->setPen(QPen(Qt::darkGreen, 2));
//        slice->setBrush(Qt::green);


        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Qt5 Pie Chart Example");


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
    refreshCharts(4);
    return;
}


void MainWindow::on_pushButton_2_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_2.wav");

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
    ui->lineEdit_pret->show();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    return;
}

void MainWindow::on_pushButton_retour_pressed()
{

    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_2.wav");
    ui->graphicsView_pret->hide();
    ui->graphicsView->show();
    ui->graphicsView_2->show();
    ui->graphicsView_3->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
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
    percentchart(1);
}
void MainWindow::on_pushButton_4_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_4->hide();
    ui->pushButton_7->show();
    percentchart(2);
}
void MainWindow::on_pushButton_5_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");

    ui->pushButton_5->hide();
    ui->pushButton_8->show();
    percentchart(3);
}
void MainWindow::on_pushButton_6_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");

    ui->pushButton_6->hide();
    ui->pushButton_3->show();
    refreshCharts(1);
}

void MainWindow::on_pushButton_7_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");

    ui->pushButton_7->hide();
    ui->pushButton_4->show();
    refreshCharts(2);
}

void MainWindow::on_pushButton_8_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_8->hide();
    ui->pushButton_5->show();
    refreshCharts(3);
}


MainWindow::~MainWindow()
{
    delete ui;
}


/*##########################################################################################*/
bool MainWindow::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":IHM_db_ali:");
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
    "duree_min int ,"
    "banquier varchar(20),"
    "client  varchar(20))");

    query.exec("insert into canal_assurance values(1, 'agence_a', 1000, 1,'bob', 'ali' )");
    query.exec("insert into canal_assurance values(2, 'agence_a', 4000, 2, 'alice', 'client_2') ");
    query.exec("insert into canal_assurance values(3, 'agence_a', 1234 ,12,'bro', 'mec') ");
    query.exec("insert into canal_assurance values(4, 'agence_b',  413, 3,'dude', 'darwich') ");
    query.exec("insert into canal_assurance values(5, 'agence_b',  324, 4,'bob, 'ali' )");
    query.exec("insert into canal_assurance values(6, 'agence_b',  423, 5,'bro', 'client_4') ");
    query.exec("insert into canal_assurance values(7, 'agence_c', 5123, 6,'alice', 'client_3') ");
    query.exec("insert into canal_assurance values(8, 'agence_c',10123, 8,'alice', 'client_3') ");
    query.exec("insert into canal_assurance values(9, 'agence_c',  123, 9,'bro', 'client_5')");
    query.exec("insert into canal_assurance values(10, 'agence_d',1023, 2,'bob', 'ali') ");
    query.exec("insert into canal_assurance values(11, 'agence_d',1123, 3,'dude', 'client_3') ");
    query.exec("insert into canal_assurance values(12, 'agence_d',4131, 4,'bob', 'client_5')");
    query.exec("insert into canal_assurance values(13, 'agence_e', 213, 6,'bob', 'ali') ");
    query.exec("insert into canal_assurance values(14, 'agence_e',1232, 8,'alice', 'darwich') ");
    query.exec("insert into canal_assurance values(15, 'agence_e',4131, 9,'bob', 'client_3') ");




    query.exec("create table canal_boursier(id int primary key,"
             "nom_agence varchar(20),"
             "banquier varchar(20),"
             "client  varchar(20))");

    query.exec("insert into canal_boursier values(1, 'agence_a','bob', 'client_1') ");
    query.exec("insert into canal_boursier values(2, 'agence_b','bro', 'client_2') ");
    query.exec("insert into canal_boursier values(3, 'agence_c','dude', 'client_3') ");
    query.exec("insert into canal_boursier values(4, 'agence_d','alice', 'ali') ");
    query.exec("insert into canal_boursier values(5, 'agence_e','bob', 'darwich') ");
    query.exec("insert into canal_boursier values(6, 'agence_a','bro', 'mec') ");



//        query.exec("Select * from items;");
////     //QString name = "/Users/macwaves/Desktop/copy to device2";
////      std::string text = query.lastQuery().toUtf8().constData();
////      std::cout<< text << std::endl;
////      std::cout << query.lastQuery().toStdString()  << std::endl;
////      //printf("%s\n" ,query.lastQuery().toStdString() );

//      while (query.next()) {
//          int name = query.value(0).toInt();
//          QString salary = query.value(2).toString();
//          std::cout << name << salary.toStdString() << std::endl;
//      }


//            query.exec("Select id , banquier from canal_bancaire;");
//      //     //QString name = "/Users/macwaves/Desktop/copy to device2";
//      //      std::string text = query.lastQuery().toUtf8().constData();
//      //      std::cout<< text << std::endl;
//      //      std::cout << query.lastQuery().toStdString()  << std::endl;
//      //      //printf("%s\n" ,query.lastQuery().toStdString() );

//          while (query.next()) {
//              int name = query.value(0).toInt();
//              QString salary = query.value(1).toString();
//              std::cout << name << " " << salary.toStdString() << std::endl;
//          }

      return true;
  }




