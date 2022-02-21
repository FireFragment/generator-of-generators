#include "subgeninstedit.h"
#include "ui_subgeninstedit.h"

SubgenInstEdit::SubgenInstEdit(QWidget *parent, Qt::WindowFlags f)
    : QWidget::QWidget(parent, f), m_ui(new Ui::SubgenInstEdit)
{
    m_ui->setupUi(this);
}
