#include "genlineedit.h"
#include "ui_genlineedit.h"

GenLineEdit::GenLineEdit(QWidget* parent, Qt::WindowFlags f):
    QWidget::QWidget(parent, f),
    m_ui(new Ui::GenLineEdit)
{
    m_ui->setupUi(this);
    
    m_ui->content->addWidget(getAddButton());
}



QPushButton* GenLineEdit::getAddButton()
{
    QPushButton* retVal = new QPushButton("+");
    retVal->setFlat(true);
    QObject::connect(retVal, SIGNAL(clicked()), this, SLOT(addItem()));
    return retVal;
}

void GenLineEdit::addItem()
{
    // TODO: Implement
    qDebug() << "Added";
}
