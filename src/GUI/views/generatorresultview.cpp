#include "generatorresultview.h"
#include <QDebug>
#include "generate.h"

using namespace GoG;
using namespace GoG::GUI;

GeneratorResultView::GeneratorResultView(QWidget* parent, Qt::WindowFlags f) :
    QWidget::QWidget(parent, f),
    m_ui(new Ui::GeneratorResultView)
{
    m_ui->setupUi(this);
}

void GeneratorResultView::setModel(GoG::GUI::Model::Generator* model)
{
    m_model = model;
    Regenerate();
}

void GeneratorResultView::Regenerate()
{
    m_ui->textView->setText(Generate(m_model));
}
