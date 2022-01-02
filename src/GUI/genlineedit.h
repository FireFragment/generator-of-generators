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
     * @brief Call, when lineEdit was edited. If it's empty, deletes it.
     */
    void lineEditEdited();
private:
    
    QScopedPointer<Ui::GenLineEdit> m_ui;
    
    /** 
     * @return const QPushButton Button for adding new items to the line
     */
    QPushButton* getAddButton() const ;
    QLineEdit* getLineEditItem() const;
};

#endif // GENLINEEDIT_H
