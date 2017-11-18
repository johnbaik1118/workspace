#include "mainwindow.h"
#include "chart.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QFocusFrame>
#include <QLCDNumber>
#include <QLineEdit>
#include <QLabel>
#include <QtCharts/QChartView>
#include <QApplication>
#include <QDesktopWidget>
#include <QtCharts/QChartView>
#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    /* Migration Button */
    QPushButton *btn = new QPushButton("My Button", this);
    // set size and location of the button
    btn->setGeometry(QRect(QPoint(10,10), QSize(100,25)));
    // connect button signal to appropriate slot
    connect(btn, SIGNAL(released()),this,SLOT(handleButton()));

    /* Display migration time */
    QLCDNumber *lcd = new QLCDNumber(5,this);
    lcd->display("123:45");
    lcd->setGeometry(10,50,100,25);

    /* QLineEdit: Source input of IP PORT */
    QLabel *sip_lbl = new QLabel("Source IP:", this);
    QLineEdit *sip_in = new QLineEdit("192.168.122.232",this);
    QLineEdit *sport_in = new QLineEdit("4000",this);
    sip_lbl->setGeometry(10,90,120,25);
    sip_in->setGeometry(140,90,190,25);
    sport_in->setGeometry(350,90,70,25);
    connect(sip_in, SIGNAL(textChanged(QString)),this,SLOT(textChanged(QString)));
    connect(sport_in, SIGNAL(textChanged(QString)),this,SLOT(textChanged(QString)));

    /* QLineEdit: Destination input of IP PORT */
    QLabel *dip_lbl = new QLabel("Destination IP:", this);
    QLineEdit *dip_in = new QLineEdit("192.168.122.122",this);
    QLineEdit *dport_in = new QLineEdit("4000",this);
    dip_lbl->setGeometry(710,90,160,25);
    dip_in->setGeometry(890,90,190,25);
    dport_in->setGeometry(1100,90,70,25);
    connect(dip_in, SIGNAL(textChanged(QString)),this,SLOT(textChanged(QString)));
    connect(dport_in, SIGNAL(textChanged(QString)),this,SLOT(textChanged(QString)));

    /* Spline chart */
    Chart *chart = new Chart;
    chart->setTitle("Source chart");
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView chartView(chart);
    chartView.setRenderHint(QPainter::Antialiasing);
    chartView.setGeometry(QRect(QPoint(100,200),QSize(11,16)));
}

MainWindow::~MainWindow(){

}

