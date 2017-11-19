#include "mainwindow.h"
#include "chart.h"
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Chart *chart = new Chart;
    chart->setTitle("Dynamic spline chart");
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView chartView(chart);
    chartView.setRenderHint(QPainter::Antialiasing);
    this->setCentralWidget(&chartView);
}

MainWindow::~MainWindow()
{

}
