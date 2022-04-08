#ifndef SHAREDIALOG_H
#define SHAREDIALOG_H

#include <qdialog.h>
#include <QScopedPointer>

#include "ui_sharedialog.h"

/**
 * @todo write docs
 */
class ShareDialog : public QDialog
{
    Q_OBJECT

public:
    ShareDialog(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    /**
     * @brief The share link
     *
     */
    QString link;

    int exec() override;
private:
    QScopedPointer<Ui::ShareDialog> m_ui;
};

#endif // SHAREDIALOG_H
