#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "xmlreader.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TagEdit->setText("item,code") ;
    ui->PropertyEdit->setText("***АКЦИЯ! РЮКЗАК В ПОДАРОК!***");
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
    if(xrepl == nullptr)
    {
         ui->logBrowser->append("Файл не был открыт , сначала надо открыть файл! ");
         return;
    }
    xrepl->setTagList(ui->TagEdit->text());
    xrepl->setPropertyRepl(ui->PropertyEdit->text());
    xrepl->setReplaceList(ui->listForReplace->toPlainText());

    ui->logBrowser->append( xrepl->replace());
}

// open file
void MainWindow::on_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open"), "",
                                                    tr("XML files (*.xml);;All Files (*)"));


    if (fileName.isEmpty())
        return;
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

    }
    xreader = new XMLReader(fileName);
    xrepl = new XMLReplacer(xreader->getXmlDoument());

    ui->logBrowser->append("file was opened");
}
