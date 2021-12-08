#include "generatoredit.h"

GeneratorEdit::GeneratorEdit(QWidget* parent, Qt::WindowFlags f) :
    QWidget::QWidget(parent, f),
    m_ui(new Ui::GeneratorEdit) 
{
    m_ui->setupUi(this);
}

void GeneratorEdit::addSubgen()
{
    SubgenEdit* subg = new SubgenEdit();
    //SubgenEdit* subg = new SubgenEdit();
    m_ui->subgeneratorsView->addTab(subg, "Subgenerator");
    // TODO: Let user choose the name of the subgenerator.
}
