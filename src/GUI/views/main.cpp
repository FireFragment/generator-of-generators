#include <QApplication>
#include <QMainWindow>
#include <QLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace GoG::GUI;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MainWindow w;

    w.show();

    return app.exec();
}
