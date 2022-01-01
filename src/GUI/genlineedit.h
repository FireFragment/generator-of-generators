#ifndef GENLINEEDIT_H
#define GENLINEEDIT_H

#include "ui_genlineedit.h"

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
    
    void addItem();
private:
    QScopedPointer<Ui::GenLineEdit> m_ui;
    
    /** 
     * @return const QPushButton Button for adding new items to the line
     */
    QPushButton* getAddButton();
};

#endif // GENLINEEDIT_H
