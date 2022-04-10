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
    app.setStyle(QStyleFactory::create("Breeze"));
    std::cout << QStyleFactory::keys().join(" ").toStdString();
    MainWindow w;

    w.show();

    return app.exec();
}
