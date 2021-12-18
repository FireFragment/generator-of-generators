#include "genlineedit.h"
#include "ui_genlineedit.h"

GenLineEdit::GenLineEdit(QWidget* parent, Qt::WindowFlags f):
    QWidget::QWidget(parent, f),
    m_ui(new Ui::GenLineEdit)
{
    m_ui->setupUi(this);
}
