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
    
    // -------- Delete action ---------
    
    QAction *deleteAction = new QAction();
    deleteAction->setIcon(QIcon::fromTheme("delete"));
    
    // Map signals - `triggered()` -> `deleteItem(QWidget*)`
    QSignalMapper* mapper = new QSignalMapper();
    mapper->setMapping(deleteAction, retVal);
    connect(deleteAction, SIGNAL(triggered()), mapper, SLOT(map()));
    
    // Connect the action to `deleteItem`
    connect(mapper, &QSignalMapper::mappedWidget,
        this, &GenLineEdit::deleteItem);
    
    // Show the delete button
    retVal->addAction(deleteAction, QLineEdit::TrailingPosition);
    
    // ----- End of delete action -----
    
    return retVal;
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

void GenLineEdit::deleteItem(QWidget* item)
{
    // Remove the plus button before the item
    QLayoutItem* preceedingButton = m_ui->content->itemAt(m_ui->content->indexOf(item) - 1); // The plus button before the item 
    m_ui->content->removeItem(preceedingButton);
    // FIXME: This doesn't seem like correct way to do this
    delete preceedingButton->widget();
    delete preceedingButton;
    
    // Remove the item
    m_ui->content->removeWidget(item);
    delete item;
}

