#ifndef GENERATORRESULTVIEW_H
#define GENERATORRESULTVIEW_H

#include <qwidget.h>
#include <QScopedPointer>
#include "../models/generator.h"

#include "ui_generatorresultview.h"

namespace Ui
{
class GeneratorResultView;
}

/**
 * @todo write docs
 */
class GeneratorResultView : public QWidget
{
    Q_OBJECT

public:

    GeneratorResultView(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    /**
     * Sets the model.
     *
     * @param model the new model
     */
    void setModel(GoG::GUI::Model::Generator* model);

    /**
     * @return the model
     */
    GoG::GUI::Model::Generator* model() const { return m_model; };

public Q_SLOTS:

    /**
     * @brief Regenerate text
     */
    void Regenerate();
private:
    GoG::GUI::Model::Generator* m_model;

private:
    QScopedPointer<Ui::GeneratorResultView> m_ui;
};

#endif // GENERATORRESULTVIEW_H
