#include <QMenu>
#include "genlineedit.h"
#include "clearlayout.h"
#include "../models/generatoritem.h"
#include "ui_genlineedit.h"

using namespace GoG;
using namespace GoG::GUI;

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

QLineEdit* GenLineEdit::getLineEditItem(QString text) const
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

    // ----- Update model on change -----
    connect(retVal, &QLineEdit::textEdited, this, &GenLineEdit::lineEditEdited);

    // Set text
    retVal->setText(text);

    return retVal;
}

SubgenInstEdit* GenLineEdit::getSubgenInstItem() const
{
    SubgenInstEdit* retVal = new SubgenInstEdit;

    // -------- Size policy ---------
    
    QSizePolicy::Policy horPol;
    horPol = QSizePolicy::Maximum;
    
    QSizePolicy::Policy vertPol;
    vertPol = QSizePolicy::Maximum;
    
    retVal->setSizePolicy(horPol, vertPol);
    
    // ----- Deleting -----
    
    // Map signals - `deleted()` -> `deleteItem(QWidget*)`
    QSignalMapper* mapper = new QSignalMapper();
    mapper->setMapping(retVal, retVal);
    connect(retVal, SIGNAL(deleted()), mapper, SLOT(map()));
    
    // Connect the action to `deleteItem`
    connect(mapper, &QSignalMapper::mappedWidget,
        this, &GenLineEdit::deleteItem);
    
    return retVal;
}

void GenLineEdit::addTextItem(QWidget* clickedButton)
{
    addItem(clickedButton, Model::GeneratorItem::CustomText);
}

void GenLineEdit::addSubgenItem(QWidget* clickedButton)
{
    addItem(clickedButton, Model::GeneratorItem::SubgenInst);
}

void GenLineEdit::lineEditEdited(const QString& text)
{
    QLineEdit* editedLineEdit = qobject_cast<QLineEdit*>(sender());

    /** Index of `lineEdit`, that was edited */
    unsigned int editedLineEditIndex = m_ui->content->indexOf(editedLineEdit);
    /** Index of item, that was edited*/
    unsigned int itemIndex = (editedLineEditIndex - 1) / 2;

    m_model->items[itemIndex]->SetCustomText(text.toStdString());

    qDebug() << "Added";
}

void GenLineEdit::addItem(QWidget* clickedButton, Model::GeneratorItem::Type type)
{
    Model::GeneratorItem* item = new Model::GeneratorItem;
    unsigned int index = m_ui->content->indexOf(clickedButton) / 2;
    switch (type) {
        case Model::GeneratorItem::CustomText: item->SetCustomText(""); break;
        case Model::GeneratorItem::SubgenInst: item->SetSubgenInst(NULL); break;
    }
    m_model->items.insert(index, item);
    m_model->Changed();

    m_ui->content->itemAt(index * 2 + 1)->widget()->setFocus(); // Set focus to the new added item
}

void GenLineEdit::deleteItem(QWidget* item)
{
    m_model->items.removeAt((m_ui->content->indexOf(item) - 1) / 2);
    
    // If there are no items anymore, let it remove itself
    if (m_model->items.size() == 0) deleted();

    m_model->Update();
}

void GenLineEdit::setModel(GoG::GUI::Model::GeneratorLine* model)
{
    m_model = model;
    connect(m_model, &Model::GeneratorLine::Update, this, &GenLineEdit::Update);
    Update();
}

void GenLineEdit::Update()
{
    ClearQLayout(m_ui->content);

    m_ui->content->addWidget(getAddButton());
    for (auto i : m_model->items) {
        QWidget* itemWgt;
        switch (i->type()) {
            case Model::GeneratorItem::CustomText:
                itemWgt = getLineEditItem(QString::fromStdString(i->getCustomText()));
                break;
            case Model::GeneratorItem::SubgenInst: itemWgt = getSubgenInstItem(); break;
        }
        m_ui->content->addWidget(itemWgt);
        m_ui->content->addWidget(getAddButton());
    }
}
