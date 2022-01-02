#include "genlineedit.h"
#include "ui_genlineedit.h"

GenLineEdit::GenLineEdit(QWidget* parent, Qt::WindowFlags f):
    QWidget::QWidget(parent, f),
    m_ui(new Ui::GenLineEdit)
{
    m_ui->setupUi(this);

    m_ui->content->insertWidget(0, getAddButton());
    m_ui->content->insertWidget(2, getAddButton());
}



QPushButton* GenLineEdit::getAddButton() const 
{
    QPushButton* retVal = new QPushButton("+");
    retVal->setFlat(true);

    // Connect to `addItem`
    connect(retVal, SIGNAL(clicked()), this, SLOT(addItem()));

    return retVal;
} 

QLineEdit* GenLineEdit::getLineEditItem() const
{
    QLineEdit* retVal = new QLineEdit();
    retVal->setClearButtonEnabled(true);
    // TODO: Fire also on clear button press
    connect(retVal, SIGNAL(editingFinished()), this, SLOT(lineEditEdited()));
    return retVal;
}

void GenLineEdit::lineEditEdited()
{
    QLineEdit* lineEdit = dynamic_cast<QLineEdit*>(sender());
    if(lineEdit->text() == "")
        // TODO: Hide `lineEdit` properly and with plus button
        lineEdit->hide();
}


void GenLineEdit::addItem()
{
    QPushButton* clickedButton = dynamic_cast<QPushButton*>(sender());

 // QLineEdit* line = new QLineEdit(QTime::currentTime().toString()); // Good for debugging - you can see, which QLineEdits are new
    QLineEdit* line = getLineEditItem();
    m_ui->content->insertWidget(m_ui->content->indexOf(clickedButton), getAddButton());
    m_ui->content->insertWidget(m_ui->content->indexOf(clickedButton), line);
    line->setFocus();
}

