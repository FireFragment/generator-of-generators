#ifndef SUBGENEDIT_H
#define SUBGENEDIT_H

#include "ui_subgenedit.h"
#include "genlineedit.h"

#include <QWidget>
#include <QLineEdit>
#include <QScopedPointer>

/**
 * @todo write docs
 */
class SubgenEdit : public QWidget
{
    Q_OBJECT
    using QWidget::QWidget;

public:
    /**
     * Constructor
     */
    SubgenEdit(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

public slots:
    void addOption();
private:
    QScopedPointer<Ui::SubgenEdit> m_ui;
};

#endif // SUBGENEDIT_H
