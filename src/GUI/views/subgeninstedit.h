#ifndef SUBGENINSTEDIT_H
#define SUBGENINSTEDIT_H

#include "ui_subgeninstedit.h"

#include <QWidget>
#include <QVector>
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
    
    void setParent(GoG::GUI::Model::Generator* generator);
    /**
     * @brief Index of currently selected generator
     *
     * Call `Update()` after chaging this
     */
    GoG::GUI::Model::Subgenerator* model = NULL;

public slots:
    void deletePressed() {
        deleted();
    };
    
    void Update();
    void changedSlt(int newVal) {
        if (m_generator->subgenerators.size() > 0 && newVal != -1)
            changed(m_generator->subgenerators[newVal]);
    }
signals:
    /**
     * @brief Fired when the line should be deleted
     * Caused by clicking the thrash button
     */
    void deleted();
    /**
     * @brief Fired when user selected some subgenerator
     *
     * @param newVal The selected subgenerator
     */
    void changed(GoG::GUI::Model::Subgenerator* newVal);
private:
    QScopedPointer<Ui::SubgenInstEdit> m_ui;

    GoG::GUI::Model::Generator* m_generator;
};

#endif // SUBGENINSTEDIT_H
