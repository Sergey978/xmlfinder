#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_replaceButton_clicked()
{
    //there will be a cod  which we will  act when button pressed
    qDebug() << "reere";
}

void MainWindow::on_Open_triggered()
{

}
