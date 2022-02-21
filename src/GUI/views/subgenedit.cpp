#include "subgenedit.h"

SubgenEdit::SubgenEdit(QWidget* parent, Qt::WindowFlags f):
    QWidget::QWidget(parent, f),
    m_ui(new Ui::SubgenEdit)
{
    m_ui->setupUi(this);
    m_ui->instShowcase->setText(name);
    m_ui->subgenHeader->hide();
    addOption();
}

void SubgenEdit::addOption()
{
    GenLineEdit* le = new GenLineEdit();
    connect(le, SIGNAL(deleted()), this, SLOT(removeOpt()));
    m_ui->options->addWidget(le);
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
