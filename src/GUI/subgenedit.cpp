#include "subgenedit.h"

SubgenEdit::SubgenEdit(QWidget* parent, Qt::WindowFlags f):
    QWidget::QWidget(parent, f),
    m_ui(new Ui::SubgenEdit)
{
    m_ui->setupUi(this);
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
