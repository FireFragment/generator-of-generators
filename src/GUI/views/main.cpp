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
    std::cout << "QStyleFactory::keys\n";
    std::cout << QStyleFactory::keys().join(" ").toStdString();
    
    std::cout << "Original QIcon::themeName: " << QIcon::themeName().toStdString();
    std::cout << "QIcon::themeSearchPaths\n";
    std::cout << QIcon::themeSearchPaths().join(" ").toStdString();
    QIcon::setThemeName( "breeze" );
    std::cout << "QIcon::themeName after changing to breeze: " << QIcon::themeName().toStdString();
    
    MainWindow w;

    w.show();

    return app.exec();
}
