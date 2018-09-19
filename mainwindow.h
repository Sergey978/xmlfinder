#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"xmlreader.h"
#include"xmlreplacer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionExit_triggered();

    void on_replaceButton_clicked();

    void on_Open_triggered();

private:
    Ui::MainWindow *ui;
    XMLReader * xreader;
    XMLReplacer *xrepl = nullptr;
};


#endif // MAINWINDOW_H
