#include "chart.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QtCharts/QChartView>
#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.showMaximized();

    return app.exec();
}
