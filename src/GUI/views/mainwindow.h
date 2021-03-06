#ifndef GOG_GUI_MAINWINDOW_H
#define GOG_GUI_MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"

namespace GoG::GUI {

/**
 * @todo write docs
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void file_open();
    void file_save();
    void file_share();
private:
    QScopedPointer<Ui::MainWindow> m_ui;
};

}

#endif // GOG_GUI_MAINWINDOW_H
