#ifndef SUBGENINSTEDIT_H
#define SUBGENINSTEDIT_H

#include "ui_subgeninstedit.h"

#include <QWidget>
#include <QScopedPointer>

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
    
public slots:
    void deletePressed() {
        deleted();
    };
    
signals:
    /**
     * @brief Fired when the line should be deleted
     * Caused by clicking the thrash button
     */
    void deleted();

private:
    QScopedPointer<Ui::SubgenInstEdit> m_ui;
};

#endif // SUBGENINSTEDIT_H
