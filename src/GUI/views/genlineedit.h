#ifndef GENLINEEDIT_H
#define GENLINEEDIT_H

#include "subgeninstedit.h"

#include "ui_genlineedit.h"

#include <QLineEdit>
#include <QPushButton>
#include <QSignalMapper>
#include <QDebug>
#include <QWidget>
#include <QScopedPointer>
#include <QDateTime>
#include <QAction>

#include "../models/generatorline.h"

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

    void setModel(GoG::GUI::Model::GeneratorLine* model);
    GoG::GUI::Model::GeneratorLine* model() { return m_model; };
    
public slots:
    
    /**
     * @brief Add a new item to the line
     */
    void addItem(QWidget* clickedButton, GoG::GUI::Model::GeneratorItem::Type type);
    void addTextItem(QWidget* clickedButton);
    void addSubgenItem(QWidget* clickedButton);

    /**
     * @brief Fired when any line edit in `GenLineEdit` has been edited.
     *
     * @warning You can't call this directly, you have to connect it to signal.
     *          The caller has to be `QLineEdit`
     *          Violating any of theese conditions may result in undefined behavior or crash.
     */
    void lineEditEdited(const QString& text);
    
    /**
     * @brief Delete an item
     * 
     * @param item Item to delete
     */
    void deleteItem(QWidget* item);

    void Update();
signals:
    /**
     * @brief Fired when the line should be deleted
     * 
     * **Possible causes:**
     *  - User deleted all items
     *  - PLANNED: User clicked the delete button
     */
    void deleted();
private:
    
    QScopedPointer<Ui::GenLineEdit> m_ui;
    
    /** 
     * @return const QPushButton Button for adding new items to the line
     */
    QPushButton* getAddButton() const ;
    QLineEdit* getLineEditItem(QString text = "") const;
    SubgenInstEdit* getSubgenInstItem() const;

    GoG::GUI::Model::GeneratorLine* m_model;
};

#endif // GENLINEEDIT_H
