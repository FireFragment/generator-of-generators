#include "genlineedit.h"
#include "ui_genlineedit.h"

GenLineEdit::GenLineEdit(QWidget* parent, Qt::WindowFlags f):
    QWidget::QWidget(parent, f),
    m_ui(new Ui::GenLineEdit)
{
    m_ui->setupUi(this);
    
    m_ui->content->insertWidget(2, getAddButton(1));
}



QPushButton* GenLineEdit::getAddButton(unsigned int index)
{
    QPushButton* retVal = new QPushButton("+");
    retVal->setFlat(true);
    
    signalMapper = new QSignalMapper(this);
    connect(retVal, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(retVal, index);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(addItem(int)));
    
    
    return retVal;
}

void GenLineEdit::addItem(int index)
{
    // TODO: Implement
    qDebug() << "Added | index =" << index;
}
