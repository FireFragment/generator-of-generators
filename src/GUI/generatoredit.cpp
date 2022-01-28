#include "generatoredit.h"
#include <QInputDialog>
#include <QMessageBox>

GeneratorEdit::GeneratorEdit(QWidget* parent, Qt::WindowFlags f) :
    QWidget::QWidget(parent, f),
    m_ui(new Ui::GeneratorEdit) 
{
    m_ui->setupUi(this);
    
    // Make delete buttons working
    connect(m_ui->subgeneratorsView->tabBar(), &QTabBar::tabCloseRequested, m_ui->subgeneratorsView->tabBar(), &QTabBar::removeTab);
}

void GeneratorEdit::addSubgen()
{
    bool ok; // User clicked the OK button
    
    // Ask user for the name
    // FIXME: The window has a small size
    QString name = QInputDialog::getText(this, tr("New subgenerator"),
                                         tr("The new generator will generate:"), QLineEdit::Normal,
                                         "", &ok);
    
    // When user didn't enter any name, warn him.
    if (name.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("No name entered");
        msgBox.setText("Subgenerator without name isn't possible.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        
        return;
    }
    
    // Create the subgenerator
    if (ok) {
        SubgenEdit* subg = new SubgenEdit();
        m_ui->subgeneratorsView->addTab(subg, name);
    }
}
