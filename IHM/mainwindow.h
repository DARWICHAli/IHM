#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void refreshCharts(int x);
    void percentchart(int x);


    bool createConnection();
private:
    Ui::MainWindow *ui;


private slots:
    void on_pushButton_retour_pressed();
    void on_pushButton_2_pressed();
    void on_pushButton_pressed();
    void on_pushButton_3_pressed();
    void on_pushButton_4_pressed();
    void on_pushButton_5_pressed();
    void on_pushButton_6_pressed();
    void on_pushButton_7_pressed();
    void on_pushButton_8_pressed();

};
#endif // MAINWINDOW_H
