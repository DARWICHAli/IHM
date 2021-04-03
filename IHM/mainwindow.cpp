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


    printf("this is a  test %d\n",createConnection());


    refreshCharts(1);
    refreshCharts(2);
    refreshCharts(3);
    refreshCharts(4);

}

//on traite ici les bdd et les conditions "date et nombre d'agence"
void MainWindow::refreshCharts(int x)
{
    if(x == 1 )
    {
        //on check les checkbox , check dates
        //get donner from bdd
        //set new data
        QBarSet *set0 = new QBarSet("Jane");
        QBarSet *set1 = new QBarSet("John");
        QBarSet *set2 = new QBarSet("Axel");
        QBarSet *set3 = new QBarSet("Mary");
        QBarSet *set4 = new QBarSet("Samantha");

        *set0 << 1 << 2 << 3 << 4 << 5 << 6;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5;
        *set4 << 9 << 7 << 5 << 3 << 1 << 2;


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
        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,15);
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


    }
    else if( x== 3 )
    {

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
    bool x1 ,x2 ,x3 ,x4 ,x5;
    x1 = ui->checkBox_1->isChecked();
    x2 = ui->checkBox_2->isChecked();
    x3 = ui->checkBox_3->isChecked();
    x4 = ui->checkBox_4->isChecked();
    x5 = ui->checkBox_5->isChecked();
    (void)x1 ,(void)x2 ,(void)x3 ,(void)x4 ,(void)x5;
    //printf("%d %d %d %d %d\n", x1 , x2 ,x3 ,x4 ,x5);
    //printf("%d",ui->dateEdit->date());
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
    ui->lineEdit_3names->hide();
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
    ui->lineEdit_3names->show();
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
      db.setDatabaseName(":memory:");
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
      query.exec("create table person (id int primary key, "
                 "firstname varchar(20), lastname varchar(20))");
      query.exec("insert into person values(101, 'Danny', 'Young')");
      query.exec("insert into person values(102, 'Christine', 'Holand')");
      query.exec("insert into person values(103, 'Lars', 'Gordon')");
      query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
      query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");

      query.exec("create table items (id int primary key,"
                                               "imagefile int,"
                                               "itemtype varchar(20),"
                                               "description varchar(100))");
      query.exec("insert into items "
                 "values(0, 0, 'Qt',"
                 "'Qt is a full development framework with tools designed to "
                 "streamline the creation of stunning applications and  "
                 "amazing user interfaces for desktop, embedded and mobile "
                 "platforms.')");
      query.exec("insert into items "
                 "values(1, 1, 'Qt Quick',"
                 "'Qt Quick is a collection of techniques designed to help "
                 "developers create intuitive, modern-looking, and fluid "
                 "user interfaces using a CSS & JavaScript like language.')");
      query.exec("insert into items "
                 "values(2, 2, 'Qt Creator',"
                 "'Qt Creator is a powerful cross-platform integrated "
                 "development environment (IDE), including UI design tools "
                 "and on-device debugging.')");
      query.exec("insert into items "
                 "values(3, 3, 'Qt Project',"
                 "'The Qt Project governs the open source development of Qt, "
                 "allowing anyone wanting to contribute to join the effort "
                 "through a meritocratic structure of approvers and "
                 "maintainers.')");

      query.exec("create table images (itemid int, file varchar(20))");
      query.exec("insert into images values(0, 'images/qt-logo.png')");
      query.exec("insert into images values(1, 'images/qt-quick.png')");
      query.exec("insert into images values(2, 'images/qt-creator.png')");
      query.exec("insert into images values(3, 'images/qt-project.png')");

        query.exec("Select * from items;");
//     //QString name = "/Users/macwaves/Desktop/copy to device2";
//      std::string text = query.lastQuery().toUtf8().constData();
//      std::cout<< text << std::endl;
//      std::cout << query.lastQuery().toStdString()  << std::endl;
//      //printf("%s\n" ,query.lastQuery().toStdString() );

      while (query.next()) {
          int name = query.value(0).toInt();
          QString salary = query.value(2).toString();
          std::cout << name << salary.toStdString() << std::endl;
      }


      return true;
  }




