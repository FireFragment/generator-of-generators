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
    /**
     * @brief Sets the name of the subgenerator and updates the UI accordingly
     * The name will be used in UI.
     * 
     * If name is unset, there will be no rename option nor `Every [name] will be replaced` header
     * 
     * @param[in] _name Name to set
     */
    void setName(QString _name);
public slots:
    void addOption();
    /**
     * @brief Remove the caller from options
     */
    void removeOpt();
private:
    QScopedPointer<Ui::SubgenEdit> m_ui;
    

    /**
     * @brief The name of the subgenerator
     * 
     */
    QString name;
};

#endif // SUBGENEDIT_H
