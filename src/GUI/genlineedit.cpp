#include <QMenu>
#include "genlineedit.h"
#include "ui_genlineedit.h"

GenLineEdit::GenLineEdit(QWidget* parent, Qt::WindowFlags f):
    QWidget::QWidget(parent, f),
    m_ui(new Ui::GenLineEdit)
{
    m_ui->setupUi(this);

    // Fill with inital contents
    m_ui->content->addWidget(getAddButton());
    m_ui->content->addWidget(getLineEditItem());
    m_ui->content->addWidget(getAddButton());
}



QPushButton* GenLineEdit::getAddButton() const 
{
    QPushButton* retVal = new QPushButton();
    retVal->setIcon(QIcon::fromTheme("list-add"));
    retVal->setFlat(true);

    // Connect to `addItem`
    connect(retVal, SIGNAL(clicked()), this, SLOT(addItem()));
    
    QMenu* menu = new QMenu();
    
    // ======= CONTEXT MENU ========
    
    // ----- Custom text -----
    QAction* customTextAction = new QAction(QIcon::fromTheme("edit-entry"), tr("Custom text"));
    menu->addAction(customTextAction);
    
    // Create signal mapper - `triggered()` -> `addItem(retVal)`
    QSignalMapper* customTextMapper = new QSignalMapper();
    customTextMapper->setMapping(customTextAction, retVal);
    connect(customTextAction, SIGNAL(triggered()), customTextMapper, SLOT(map()));
    
    connect(customTextMapper, &QSignalMapper::mappedWidget, this, &GenLineEdit::addTextItem);
    
    // ----- Subgenerator -----  
    QAction* subgenAction = new QAction(QIcon::fromTheme("view-list-tree"), tr("Subgenerator"));
    menu->addAction(subgenAction);
    
    // Create signal mapper - `triggered()` -> `addItem(retVal)`
    QSignalMapper* subgenMapper = new QSignalMapper();
    subgenMapper->setMapping(subgenAction, retVal);
    connect(subgenAction, SIGNAL(triggered()), subgenMapper, SLOT(map()));
    
    connect(subgenMapper, &QSignalMapper::mappedWidget, this, &GenLineEdit::addSubgenItem);
    
    // ===== END OF CONTEXT MENU =====
    
    retVal->setMenu(menu);   
    retVal->setStyleSheet("::menu-indicator{ image: none; }"); // Hide the arrow
        
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

SubgenInstEdit* GenLineEdit::getSubgenInstItem() const
{
    SubgenInstEdit* retVal = new SubgenInstEdit;

    QSizePolicy::Policy horPol;
    horPol = QSizePolicy::Maximum;
    
    QSizePolicy::Policy vertPol;
    vertPol = QSizePolicy::Maximum;
    
    retVal->setSizePolicy(horPol, vertPol);
    
    return retVal;
}

void GenLineEdit::addTextItem(QWidget* clickedButton)
{
    addItem(clickedButton, ItemType::CustomText);
}

void GenLineEdit::addSubgenItem(QWidget* clickedButton)
{
    addItem(clickedButton, ItemType::Subgen);
}

void GenLineEdit::addItem(QWidget* clickedButton, ItemType type)
{

 // QLineEdit* line = new QLineEdit(QTime::currentTime().toString()); // Good for debugging - you can see, which QLineEdits are new
    QWidget* item;
    if (type == ItemType::CustomText) {
        item = getLineEditItem();
    } else {
        item = getSubgenInstItem();
    }
    m_ui->content->insertWidget(m_ui->content->indexOf(clickedButton), getAddButton());
    m_ui->content->insertWidget(m_ui->content->indexOf(clickedButton), item);
    item->setFocus();
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
    
    // If there are not any items anymore, let it remove itself
    if (m_ui->content->count() <= 1) deleted();
}

