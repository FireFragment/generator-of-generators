#include "sharedialog.h"
#include "ui_sharedialog.h"


ShareDialog::ShareDialog(QWidget* parent, Qt::WindowFlags f):
    QDialog::QDialog(parent, f),
    m_ui(new Ui::ShareDialog)
{
    m_ui->setupUi(this);
}

int ShareDialog::exec()
{
    m_ui->linkView->setText(link);
    return QDialog::exec();
}
