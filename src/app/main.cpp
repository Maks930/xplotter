#include <gui/MainWindow/mainwindow.h>
#include <core/Project/Project.h>
#include <core/Project/MetaInfo/MetaInfo.h>

#include <QApplication>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
