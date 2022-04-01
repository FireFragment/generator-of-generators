#include "mainwindow.h"

GoG::GUI::MainWindow::MainWindow() :
    QMainWindow::QMainWindow(), m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    Model::Generator* model = new Model::Generator;
    m_ui->centralWidget->setModel(model);
}
