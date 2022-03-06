#include <QApplication>
#include <QMainWindow>
#include <QLayout>
#include "ui_mainwindow.h"

using namespace GoG::GUI;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QMainWindow w;
    Ui::MainWindow main;
    main.setupUi(&w);

    GoG::GUI::Model::Generator model("Old name");
    main.centralWidget->setModel(&model);

    model.name = "Testing generator";

    model.subgenerators.push_back(Model::Subgenerator("Subgenerator no. 1"));
    model.Changed();
    model.subgenerators.push_back(Model::Subgenerator("Subgenerator no. 2"));
    model.subgenerators.push_back(Model::Subgenerator("Subgenerator no. 3"));
    model.Changed();

    w.show();

    qDebug() << "Done";

    return app.exec();
}
