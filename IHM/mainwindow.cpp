#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QChart>
#include <QAreaSeries>
#include <QLineSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QPercentBarSeries>
#include <QPieSeries>
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
        QPieSlice *slice = series->append("Fat 15.6%", 15.6);
        slice->setExploded();
        slice->setLabelVisible();
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

    refreshCharts(1);
    refreshCharts(2);
    refreshCharts(3);
    refreshCharts(4);
    return;
}


void MainWindow::on_pushButton_2_pressed()
{
//    QPushButton* pushButtonSender = qobject_cast<QPushButton*>(sender()); //To retrieve the pushed button.
//    CardButton* cardButtonSender = dynamic_cast<CardButton*>(pushButtonSender);
    //This ^ is a dynamic cast: it checks in real time if pushButtonSender is cast-able into a CardButton*.
    //If you were to use this cast on a QPushButton that isn't also a CardButton, it would return nullptr.
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
    ui->graphicsView_pret->hide();
    ui->graphicsView->show();
    ui->graphicsView_2->show();
    ui->graphicsView_3->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->pushButton_6->show();
    ui->pushButton_7->show();
    ui->pushButton_8->show();
    ui->pushButton_retour->hide();
    ui->lineEdit_pret->hide();
    ui->lineEdit_3names->show();
    //refresh chart

    return;
}
void MainWindow::on_pushButton_3_pressed()
{
    ui->pushButton_3->hide();
    ui->pushButton_6->show();
    percentchart(1);
}
void MainWindow::on_pushButton_4_pressed()
{
    ui->pushButton_4->hide();
    ui->pushButton_7->show();
    percentchart(2);
}
void MainWindow::on_pushButton_5_pressed()
{
    ui->pushButton_5->hide();
    ui->pushButton_8->show();
    percentchart(3);
}
void MainWindow::on_pushButton_6_pressed()
{
    ui->pushButton_6->hide();
    ui->pushButton_3->show();
    refreshCharts(1);
}

void MainWindow::on_pushButton_7_pressed()
{
    ui->pushButton_7->hide();
    ui->pushButton_4->show();
    refreshCharts(2);
}

void MainWindow::on_pushButton_8_pressed()
{
    ui->pushButton_8->hide();
    ui->pushButton_5->show();
    refreshCharts(3);
}


MainWindow::~MainWindow()
{
    delete ui;
}

