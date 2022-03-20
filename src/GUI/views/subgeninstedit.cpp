#include "subgeninstedit.h"
#include "ui_subgeninstedit.h"

#include <QDebug>

using namespace GoG::GUI;

SubgenInstEdit::SubgenInstEdit(QWidget *parent, Qt::WindowFlags f)
    : QWidget::QWidget(parent, f), m_ui(new Ui::SubgenInstEdit)
{
    m_ui->setupUi(this);
}

void SubgenInstEdit::setModel(GoG::GUI::Model::Generator* model)
{
    m_model = model;
    connect(m_model, &Model::Generator::Update, this, &SubgenInstEdit::Update);
    Update();
}

void SubgenInstEdit::Update()
{
    m_ui->comboBox->clear();
    for (auto i : m_model->subgenerators)
        m_ui->comboBox->addItem(i->name);
}
