#ifndef GENLINEEDIT_H
#define GENLINEEDIT_H

#include "ui_genlineedit.h"

#include <QSignalMapper>
#include <QDebug>
#include <QWidget>
#include <QScopedPointer>

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
     * 
     * @param index Index of the new item, not yet implemented.
     *              TODO: Make it actually do something
     */
    void addItem(int index);
private:
    QScopedPointer<Ui::GenLineEdit> m_ui;
    
    /** 
     * @return const QPushButton Button for adding new items to the line
     * 
     * @param index The position of the button. Used to properly connect with `addItem` slot.
     */
    QPushButton* getAddButton(unsigned int index);
    
    QSignalMapper* signalMapper;
};

#endif // GENLINEEDIT_H
