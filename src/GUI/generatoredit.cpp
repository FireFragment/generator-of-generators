#include "generatoredit.h"
#include <QInputDialog>

GeneratorEdit::GeneratorEdit(QWidget* parent, Qt::WindowFlags f) :
    QWidget::QWidget(parent, f),
    m_ui(new Ui::GeneratorEdit) 
{
    m_ui->setupUi(this);
}

void GeneratorEdit::addSubgen()
{
    SubgenEdit* subg = new SubgenEdit();
    
    bool ok; // User clicked the OK button
    
    // Ask user for the name
    // FIXME: The window has a small size
    QString name = QInputDialog::getText(this, tr("New subgenerator"),
                                         tr("Subgenerator name:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !name.isEmpty())
        m_ui->subgeneratorsView->addTab(subg, name);
}
