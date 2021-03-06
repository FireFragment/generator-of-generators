#ifndef GENERATOREDIT_H
#define GENERATOREDIT_H

#include "ui_generatoredit.h"
#include "subgenedit.h"

#include <QWidget>
#include <QFrame>
#include <QString>
#include <QScopedPointer>
#include <QLineEdit>

#include "../models/generator.h"

/**
 * \brief Throught this widget, user can edit `generator`s
 */
class GeneratorEdit : public QWidget/*, public QDesignerCustomWidgetInterface*/
{
    Q_OBJECT

public:
    GeneratorEdit(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    void setModel(GoG::GUI::Model::Generator* model);
    GoG::GUI::Model::Generator* model() { return m_model; };
public slots:
    void addSubgen();
    /**
     * @brief Add option to currently selected subgenerator
     *
     */
    void addOpt();
    void debug();
    void dbgEnter();
    /**
     * @brief Updates the UI according to `model`
     *
     * This is called automatically when #model fires `Update` signal
     *
     */
    void Update();
    void tabClosed(int index);

    inline void regenerate() {
        m_ui->result->Regenerate();
    };
private:
    QScopedPointer<Ui::GeneratorEdit> m_ui;
    GoG::GUI::Model::Generator* m_model;
};

#endif // GENERATOREDIT_H
