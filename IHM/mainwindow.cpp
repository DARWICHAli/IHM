#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QChart>
#include <QAreaSeries>
#include <QLineSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>

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

    QObject::connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(on_pushButton_2_pressed()));
    QObject::connect(ui->pushButton, SIGNAL(released()), this, SLOT(on_pushButton_pressed()));
    QObject::connect(ui->pushButton_retour, SIGNAL(released()), this, SLOT(on_pushButton_retour_pressed()));



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


    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();

    ui->graphicsView->setChart(chart);


}
void MainWindow::refreshCharts()
{
    //on check les checkbox , check dates
    //get donner from bdd
    //set new data
}

void MainWindow::on_pushButton_pressed()
{

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

    return;
}


void MainWindow::on_pushButton_retour_pressed()
{
    ui->graphicsView_pret->hide();
    ui->graphicsView->show();
    ui->graphicsView_2->show();
    ui->graphicsView_3->show();
    ui->pushButton_2->show();
    ui->pushButton_retour->hide();
    //refresh chart

    return;
}





MainWindow::~MainWindow()
{
    delete ui;
}

