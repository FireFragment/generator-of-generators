#include "subgeninstedit.h"
#include "ui_subgeninstedit.h"

#include <QDebug>
#include <algorithm>

using namespace GoG::GUI;

SubgenInstEdit::SubgenInstEdit(QWidget *parent, Qt::WindowFlags f)
    : QWidget::QWidget(parent, f), m_ui(new Ui::SubgenInstEdit)
{
    m_ui->setupUi(this);
}

void SubgenInstEdit::setParent(GoG::GUI::Model::Generator* generator)
{
    m_generator = generator;
    connect(m_generator, &Model::Generator::Update, this, &SubgenInstEdit::Update);
    Update();
}

void SubgenInstEdit::Update()
{
    m_ui->comboBox->clear();
    for (auto i : m_generator->subgenerators)
        m_ui->comboBox->addItem(i->name);
    m_ui->comboBox->setCurrentIndex(std::find(m_generator->subgenerators.begin(), m_generator->subgenerators.end(), model) - m_generator->subgenerators.begin());
}

