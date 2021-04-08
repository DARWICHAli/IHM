#include "plot.h"



void func(QBarSet *set0 ,   QSqlQuery query)
{
    while (query.next()) {
        int prix = query.value(0).toInt();
        *set0  << prix ;
    }
}
void func_2(QBarSet *set0 ,   QSqlQuery query)
{
    int x = 0;
    while (query.next()) {
        x += query.value(0).toInt();
    }
    *set0  << x ;

}
void setchartparam(QChart *chart , QBarSeries *series , const char* str1,const char * str2 ,int range)
{
    chart->addSeries(series);
    chart->setTitle(str1);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    categories << str2;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,range);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}
void setchartparam_2(QChart *chart , QPercentBarSeries *series , const char* str1,const char * str2 )
{
    chart->addSeries(series);
    chart->setTitle(str1);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << str2;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

}



//on traite ici les bdd et les conditions "date et nombre d'agence"
void refreshCharts(int x , Ui::MainWindow *ui)
{
    QSqlQuery query;
    bool x1 ,x2 ,x3 ,x4 ,x5;
    std::string temp;
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



        temp = "Select count(*) from canal_bancaire where type = 'pret_hab' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec( QString::fromStdString(temp));
        func(set0 , query);

        temp = "Select count(*) from canal_bancaire where type = 'pret_auto'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec( QString::fromStdString(temp));
        func(set1 , query);

        temp = "Select count(*) from canal_bancaire where type = 'compte_courant'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec( QString::fromStdString(temp));
        func(set2 , query);


        temp = "Select count(*) from canal_bancaire where type = 'compte_epargne'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec( QString::fromStdString(temp));
        func(set3 , query);

        temp = "Select count(*) from canal_bancaire where type = 'autre'";
        if(strtime.length() != 0)
        {
            temp.append("AND" + strtime);

        }
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec( QString::fromStdString(temp));
        func(set4 , query);



        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

        QChart *chart = new QChart();

        setchartparam(chart , series , "Produits bancaires" , "Volume" ,10);

        ui->graphicsView->setChart(chart);

    }
    else if(x == 2)
    {
        QBarSet *set0 = new QBarSet("velo");
        temp = "Select count(*) from canal_assurance where type = 'assu_velo' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND (");
        temp.append(str);
        query.exec(QString::fromStdString(temp));

        func(set0 , query);

        QBarSet *set1 = new QBarSet("ordi");
        temp = "Select count(*) from canal_assurance where type = 'assu_ordi' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);

        if(count)
            temp.append("AND (");
        temp.append(str);

        query.exec(QString::fromStdString(temp));
        func(set1 , query);

        QBarSet *set2 = new QBarSet("autre");
        temp = "Select count(*) from canal_assurance where type = 'autre' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND (");
        temp.append(str);

        query.exec(QString::fromStdString(temp));
        func(set2 , query);


        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);

        QChart *chart = new QChart();

        setchartparam(chart , series , "Produits assurances" , "Volume" ,10);


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
        query.exec(QString::fromStdString(temp));
        func(set0 , query);


        QBarSeries *series = new QBarSeries();
        series->append(set0);

        QChart *chart = new QChart();
        setchartparam(chart , series , "Produits boursiers" , "Volume" ,10);

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
            temp.append("AND" + strtime);

        if(count)
            temp.append("AND ( ");

        temp.append(str);
        query.exec(QString::fromStdString(temp));
        while (query.next()) {
             f0 += query.value(0).toInt() ;
        }
        *set0 << f0;


        // pour Volume
        temp = "Select count(*) from canal_bancaire where type = 'pret_hab' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);

        if(count)
            temp.append("AND ( ");

        temp.append(str);
        query.exec(QString::fromStdString(temp));
        while (query.next()) {
             f1 += query.value(0).toInt() ;
        }


        temp = "Select prix from canal_bancaire where type = 'pret_auto'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);


        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        while (query.next()) {
            f2 += query.value(0).toInt() ;
       }
       *set1 << f2;

        temp = "Select count(*) from canal_bancaire where type = 'pret_auto'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);


        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        while (query.next()) {
            f3 += query.value(0).toInt() ;
       }


        temp = "Select prix from canal_bancaire where type = 'compte_courant'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);


        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        while (query.next()) {
            f4 += query.value(0).toInt();
        }
        *set2  << f4 ;


        temp = "Select count(*) from canal_bancaire where type = 'compte_courant'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);


        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        while (query.next()) {
            int prix = query.value(0).toInt();
            f5 += prix;
        }


        temp = "Select prix from canal_bancaire where type = 'compte_epargne'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);


        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        while (query.next()) {
            f6 += query.value(0).toInt();
        }
        *set3  << f6 ;


        temp = "Select count(*) from canal_bancaire where type = 'compte_epargne'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        while (query.next()) {
            f7 += query.value(0).toInt();
        }

        temp = "Select prix from canal_bancaire where type = 'autre'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);


        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        while (query.next()) {
            f8 += query.value(0).toInt();
        }
        *set4  << f8;


        temp = "Select count(*) from canal_bancaire where type = 'autre'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        while (query.next()) {
            f9 += query.value(0).toInt();
        }

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

        QChart *chart = new QChart();
        setchartparam(chart , series , "Produits bancaire" , "CA" ,50000);
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


void caCharts(int x,Ui::MainWindow *ui)
{
    QSqlQuery query;
    bool x1 ,x2 ,x3 ,x4 ,x5;
    std::string temp;

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

    if (x == 1)
    {
        QBarSet *set0 = new QBarSet("P_hab");
        QBarSet *set1 = new QBarSet("p_auto");
        QBarSet *set2 = new QBarSet("C_courant");
        QBarSet *set3 = new QBarSet("C_epargne");
        QBarSet *set4 = new QBarSet("autre");
        temp = "Select prix from canal_bancaire where type = 'pret_hab' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);

        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set0 , query);
        temp = "Select prix from canal_bancaire where type = 'pret_auto'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set1 , query);

        temp = "Select prix from canal_bancaire where type = 'compte_courant'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set2 , query);

        temp = "Select prix from canal_bancaire where type = 'compte_epargne'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set3 , query);

        temp = "Select prix from canal_bancaire where type = 'autre'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);


        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set4 , query);


        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

        QChart *chart = new QChart();

        setchartparam(chart , series , "Produits bancaire" , "CA" ,50000);
        ui->graphicsView->setChart(chart);

    }
    else if (x == 2)
    {
        QBarSet *set0 = new QBarSet("velo");
        temp = "Select prix from canal_assurance where type = 'assu_velo' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);


        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set0 , query);

        QBarSet *set1 = new QBarSet("ordi");
        temp = "Select prix from canal_assurance where type = 'assu_ordi' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);


        if(count)
            temp.append("AND ( ");
        temp.append(str);

        query.exec(QString::fromStdString(temp));
        func_2(set1 , query);

        QBarSet *set2 = new QBarSet("autre");
        temp = "Select prix from canal_assurance where type = 'autre' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);


        if(count)
            temp.append("AND (");
        temp.append(str);

        query.exec(QString::fromStdString(temp));
        func_2(set2 , query);


        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);

        QChart *chart = new QChart();
        setchartparam(chart , series , "Produits assurances" , "CA" ,30000);

        ui->graphicsView_2->setChart(chart);

    }
    else if (x == 3)
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

        query.exec(QString::fromStdString(temp));
        func_2(set0 , query);


        QBarSeries *series = new QBarSeries();
        series->append(set0);

        QChart *chart = new QChart();
        setchartparam(chart , series , "Produits boursiers" , "CA" ,100000);

        ui->graphicsView_3->setChart(chart);
    }
}

//traite aussi les conditions avant l'affichage.
void percentchart(int x,Ui::MainWindow *ui)
{
    QSqlQuery query;
    bool x1 ,x2 ,x3 ,x4 ,x5;
    std::string temp;

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
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set0 ,query);


        temp = "Select prix from canal_bancaire where type = 'pret_auto'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set1 ,query);

        temp = "Select prix from canal_bancaire where type = 'compte_courant'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set2 ,query);

        temp = "Select prix from canal_bancaire where type = 'compte_epargne'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set3 ,query);

        temp = "Select prix from canal_bancaire where type = 'autre'";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set4 ,query);
        QPercentBarSeries *series = new QPercentBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

        QChart *chart = new QChart();
        setchartparam_2(chart , series, "Produits bancaires" ,"Percent");

        ui->graphicsView->setChart(chart);

    }
    else if (x== 2 )
    {


        QBarSet *set0 = new QBarSet("velo");
        temp = "Select prix from canal_assurance where type = 'assu_velo' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set0 ,query);

        QBarSet *set1 = new QBarSet("ordi");
        temp = "Select prix from canal_assurance where type = 'assu_ordi' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND ( ");
        temp.append(str);

        query.exec(QString::fromStdString(temp));
        func_2(set1 ,query);

        QBarSet *set2 = new QBarSet("autre");
        temp = "Select prix from canal_assurance where type = 'autre' ";
        if(strtime.length() != 0)
            temp.append("AND" + strtime);
        if(count)
            temp.append("AND (");
        temp.append(str);

        query.exec(QString::fromStdString(temp));
        func_2(set2 ,query);

        QPercentBarSeries *series = new QPercentBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);

        QChart *chart = new QChart();

        setchartparam_2(chart , series , "Produits assurances","Percent");

        ui->graphicsView_2->setChart(chart);

    }
    else
    {
        QBarSet *set0 = new QBarSet("action");
        temp = "Select prix from canal_boursier where ";
        if(strtime.length() != 0)
            temp.append(strtime);
        if(count)
            temp.append(" ( ");
        temp.append(str);
        query.exec(QString::fromStdString(temp));
        func_2(set0 ,query);
        QPercentBarSeries *series = new QPercentBarSeries();
        series->append(set0);
        QChart *chart = new QChart();
        setchartparam_2(chart , series , "Produits boursiers","Percent");
        ui->graphicsView_3->setChart(chart);
    }

}
