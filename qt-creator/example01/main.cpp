#include <QApplication>
#include <QPushButton>
#include <QFocusFrame>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton *btn[3];

    int ypos = 30;

    for(int i = 0; i < 3; i++) {
        btn[i] = new QPushButton(QString("Frame's button %1").arg(i), this);
        btn[i]->setGeometry(10, ypos, 300, 40);
        ypos += 50;
    }

    //    MainWindow w;
    //    w.show();

    return app.exec();
}
