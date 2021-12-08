#include "subgenedit.h"

SubgenEdit::SubgenEdit(QWidget* parent, Qt::WindowFlags f):
    QWidget::QWidget(parent, f),
    m_ui(new Ui::SubgenEdit)
{
    m_ui->setupUi(this);
}


void SubgenEdit::addOption()
{
    QLineEdit* le = new QLineEdit();
    m_ui->options->addWidget(le);
}
