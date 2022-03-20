#include "subgenedit.h"
#include "clearlayout.h"

using namespace GoG;
using namespace GoG::GUI;

SubgenEdit::SubgenEdit(QWidget* parent, Qt::WindowFlags f):
    QWidget::QWidget(parent, f),
    m_ui(new Ui::SubgenEdit)
{
    m_ui->setupUi(this);
    m_ui->instShowcase->setText(name);
    m_ui->subgenHeader->hide();
}

void SubgenEdit::addOption()
{
    m_model->options.push_back(new Model::GeneratorLine);
    m_model->Update();
}

void SubgenEdit::removeOpt()
{
    QWidget* wgt = dynamic_cast<QWidget*>(sender());
    
    wgt->hide();
    m_ui->options->removeWidget(wgt);
    delete wgt;
}

void SubgenEdit::setName(QString _name)
{
    name = _name;
    m_ui->subgenHeader->setVisible(name != "");
    m_ui->subgenNoHeader->setVisible(name == "");
    m_ui->instShowcase->setText(name);
}

void SubgenEdit::setModel(GoG::GUI::Model::Subgenerator* model)
{
    m_model = model;
    connect(m_model, &Model::Subgenerator::Update, this, &SubgenEdit::Update);
    Update();
}

void SubgenEdit::Update()
{
    setName(m_model->name);

    ClearQLayout(m_ui->options);

    for (auto i : m_model->options) {
        GenLineEdit* le = new GenLineEdit();
        le->parent = parent;
        le->setModel(i);

        connect(le, SIGNAL(deleted()), this, SLOT(removeOpt()));
        m_ui->options->addWidget(le);
    }
}

