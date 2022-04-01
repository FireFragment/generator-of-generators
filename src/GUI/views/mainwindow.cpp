#include "mainwindow.h"
#include <QJsonDocument>
#include <QFileDialog>

GoG::GUI::MainWindow::MainWindow() :
    QMainWindow::QMainWindow(), m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    Model::Generator* model = new Model::Generator;
    m_ui->centralWidget->setModel(model);
}

void GoG::GUI::MainWindow::file_open()
{
    QFile file(QFileDialog::getOpenFileName(this, "Open Generator", QString(), "Generators (*.gog)"));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    m_ui->centralWidget->model()->FromJSON(
        QJsonDocument::fromJson(
            file.readAll()).object());
    m_ui->centralWidget->model()->Changed();
}

void GoG::GUI::MainWindow::file_save()
{
    QFileDialog::saveFileContent((QByteArray)QJsonDocument(m_ui->centralWidget->model()->ToJSON()).toJson(), "New generator.gog");
}
