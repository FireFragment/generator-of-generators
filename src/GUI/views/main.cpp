#include <QApplication>
#include <QMainWindow>
#include <QLayout>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyleFactory>

using namespace GoG::GUI;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

#if defined(Q_OS_WIN32) || defined(Q_OS_MAC)
    QIcon::setThemeName("breeze");
#endif

    MainWindow w;
    w.show();

    return app.exec();
}
