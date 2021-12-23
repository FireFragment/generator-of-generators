#ifndef GENLINEEDIT_H
#define GENLINEEDIT_H

#include "ui_genlineedit.h"

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
    
private:
    QScopedPointer<Ui::GenLineEdit> m_ui;
};

#endif // GENLINEEDIT_H
