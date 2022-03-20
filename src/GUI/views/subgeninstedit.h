#ifndef SUBGENINSTEDIT_H
#define SUBGENINSTEDIT_H

#include "ui_subgeninstedit.h"

#include <QWidget>
#include <QScopedPointer>
#include "../models/generator.h"

/**
 * @todo write docs
 */
class SubgenInstEdit : public QWidget
{
    Q_OBJECT

public:
    /**
     * Default constructor
     */
    SubgenInstEdit(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    
    void setModel(GoG::GUI::Model::Generator* model);
    GoG::GUI::Model::Generator* model() { return m_model; };
public slots:
    void deletePressed() {
        deleted();
    };
    
    void Update();
signals:
    /**
     * @brief Fired when the line should be deleted
     * Caused by clicking the thrash button
     */
    void deleted();
private:
    QScopedPointer<Ui::SubgenInstEdit> m_ui;

    GoG::GUI::Model::Generator* m_model;
};

#endif // SUBGENINSTEDIT_H
