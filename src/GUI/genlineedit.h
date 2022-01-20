#ifndef GENLINEEDIT_H
#define GENLINEEDIT_H

#include "ui_genlineedit.h"

#include <QLineEdit>
#include <QPushButton>
#include <QSignalMapper>
#include <QDebug>
#include <QWidget>
#include <QScopedPointer>
#include <QDateTime>
#include <QAction>

namespace Ui
{
class GenLineEdit;
}

/**
 * @todo write docs
 */
class GenLineEdit : public QWidget
{
    Q_OBJECT

public:
    /**
     * Constructor
     *
     * @param parent TODO
     * @param f TODO
     */
    GenLineEdit(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    
    
public slots:
    
    /**
     * @brief Add a new item to the line
     */
    void addItem();
    
    /**
     * @brief Delete an item
     * 
     * @param item Item to delete
     */
    void deleteItem(QWidget* item);
    
signals:
    /**
     * @brief Fired when the line should be deleted
     * 
     * **Possible causes:**
     *  - User deleted all items
     *  - PLANNED: User clicked the delete button
     */
    void deleted();
private:
    
    QScopedPointer<Ui::GenLineEdit> m_ui;
    
    /** 
     * @return const QPushButton Button for adding new items to the line
     */
    QPushButton* getAddButton() const ;
    QLineEdit* getLineEditItem() const;
};

#endif // GENLINEEDIT_H
