#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plot.h"




#include <iostream>

#include <QSound>
//#include <QCoreApplication>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>


//#include <QString>


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

    ui->widget_2->hide();

//    ui->graphicsView_pret->hide();
//    ui->pushButton_retour->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
//    ui->lineEdit_pret->hide();
//    ui->textEdit->hide();

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
    refreshCharts(1 , ui);
    refreshCharts(2 , ui);
    refreshCharts(3, ui);
    refreshCharts(-1, ui);

}

//ici on check le date et checkboxes et on met a jour les charts
void MainWindow::on_pushButton_pressed()
{

    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_2.wav");


    on_pushButton_6_pressed();
    on_pushButton_7_pressed();
    on_pushButton_8_pressed();

    refreshCharts(1, ui);
    refreshCharts(2, ui);
    refreshCharts(3, ui);
    refreshCharts(-1, ui);
    return;
}


void MainWindow::on_pushButton_2_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_2.wav");

    ui->widget->hide();
    ui->widget_2->show();
    ui->pushButton_2->hide();


    return;
}

void MainWindow::on_pushButton_retour_pressed()
{

    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_2.wav");

    ui->widget->show();
    ui->widget_2->hide();
    ui->pushButton_2->show();

    return;
}

void MainWindow::on_pushButton_3_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_3->hide();
    ui->pushButton_6->show();
    ui->pushButton_9->show();

    percentchart(1, ui);
}
void MainWindow::on_pushButton_4_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_4->hide();
    ui->pushButton_7->show();
    ui->pushButton_10->show();

    percentchart(2, ui);
}
void MainWindow::on_pushButton_5_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");

    ui->pushButton_5->hide();
    ui->pushButton_8->show();
    ui->pushButton_11->show();
    percentchart(3, ui);
}
void MainWindow::on_pushButton_6_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");

    ui->pushButton_6->hide();
    ui->pushButton_3->show();
    ui->pushButton_9->show();
    refreshCharts(1, ui);
}

void MainWindow::on_pushButton_7_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");

    ui->pushButton_7->hide();
    ui->pushButton_4->show();
    ui->pushButton_10->show();
    refreshCharts(2, ui);
}

void MainWindow::on_pushButton_8_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_8->hide();
    ui->pushButton_5->show();
    ui->pushButton_11->show();
    refreshCharts(3, ui);
}

void MainWindow::on_pushButton_9_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_9->hide();
    ui->pushButton_3->show();
    ui->pushButton_6->show();
    caCharts(1, ui);

}
void MainWindow::on_pushButton_10_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_10->hide();
    ui->pushButton_4->show();
    ui->pushButton_7->show();
    caCharts(2, ui);
}
void MainWindow::on_pushButton_11_pressed()
{
    QSound::play(QCoreApplication::applicationDirPath() + "/../IHM/mysounds/button_1.wav");
    ui->pushButton_11->hide();
    ui->pushButton_5->show();
    ui->pushButton_8->show();
    caCharts(3, ui);
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




