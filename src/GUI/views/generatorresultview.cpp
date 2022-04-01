#include "generatorresultview.h"
#include <QDebug>
#include <QMessageBox>
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
    unsigned int retryCount = 0;
    while (retryCount < 32) {
        try {
            m_ui->textView->setText(Generate(m_model));
            return;
        } catch (RecursiveGenerator) {
            retryCount++;
        }
    };

    QMessageBox::critical(this, "Error", "Your generator is recursive; that means, that some subgenerator contains itself or there is cycle in them which would result in infinitely large outputs.\nFix it to make your generator working agin.");
}
