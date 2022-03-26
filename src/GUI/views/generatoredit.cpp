#include "generatoredit.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QJsonDocument>

#include "../models/generator.h"

using namespace GoG::GUI;
using namespace GoG;

GeneratorEdit::GeneratorEdit(QWidget* parent, Qt::WindowFlags f) :
    QWidget::QWidget(parent, f),
    m_ui(new Ui::GeneratorEdit) 
{
    m_ui->setupUi(this);
    
    // Make delete buttons working
    connect(m_ui->subgeneratorsView->tabBar(), &QTabBar::tabCloseRequested, this, &GeneratorEdit::tabClosed);
}

void GeneratorEdit::addSubgen()
{
    bool ok; // User clicked the OK button
    
    // Ask user for the name
    // FIXME: The window has a small size
    QString name = QInputDialog::getText(this, tr("New subgenerator"),
                                         tr("The new generator will generate:"), QLineEdit::Normal,
                                         "", &ok);
    
    // When user didn't enter any name, warn him.
    if (name.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("No name entered");
        msgBox.setText("Subgenerator without name isn't possible.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        
        return;
    }
    
    // Create the subgenerator
    if (ok) {
        m_model->subgenerators.push_back(new Model::Subgenerator(name));
        m_model->Update();
    }
}

void GeneratorEdit::addOpt()
{
    /** Subgenerator option is added to */
    Model::Subgenerator* editedSubgenerator = m_model->subgenerators[m_ui->subgeneratorsView->currentIndex()];
    editedSubgenerator->options << new Model::GeneratorLine;
    editedSubgenerator->Update();
}


void GeneratorEdit::Update()
{
    m_ui->nameLbl->setText(model()->name);

    // Main generator
    m_ui->mainGenerator->parent = m_model;
    m_ui->mainGenerator->setModel(&model()->mainGenerator);

    // Subgenerators
    m_ui->subgeneratorsView->clear();
    for (auto& i : m_model->subgenerators) {
        SubgenEdit* subg = new SubgenEdit();
        subg->parent = m_model;
        subg->setModel(i);
        m_ui->subgeneratorsView->addTab(subg, i->name);
    }
}

void GeneratorEdit::setModel(GoG::GUI::Model::Generator* model)
{
    m_model = model;
    connect(m_model, &GUI::Model::Generator::Update, this, &GeneratorEdit::Update);
    m_ui->result->setModel(model);
    Update();

}

void GeneratorEdit::tabClosed(int index)
{
    m_model->subgenerators.removeAt(index);
    m_model->Update();
    qDebug() << "Deleted subgenerator no. " << index;
}

void GeneratorEdit::debug()
{
    QMessageBox msgBox;
    msgBox.setText("The JSON data");
    msgBox.setDetailedText(QJsonDocument(m_model->ToJSON()).toJson());
    msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowMaximizeButtonHint);
    msgBox.exec();
}




