#ifndef GENERATOREDIT_H
#define GENERATOREDIT_H

#include "ui_generatoredit.h"
#include "subgenedit.h"

#include <QWidget>
#include <QFrame>
#include <QString>
#include <QScopedPointer>
#include <QLineEdit>

/**
 * \brief Throught this widget, user can edit `generator`s
 */
class GeneratorEdit : public QWidget/*, public QDesignerCustomWidgetInterface*/
{
    Q_OBJECT

public:
    GeneratorEdit(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    
public slots:
    void addSubgen();
private:
    QScopedPointer<Ui::GeneratorEdit> m_ui;
};

#endif // GENERATOREDIT_H
