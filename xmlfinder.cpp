#include "xmlfinder.h"
#include "ui_xmlfinder.h"

#include <QtCore/QFile>
#include <QtCore/QTextStream>

XMLFinder::XMLFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::XMLFinder)
{
    ui->setupUi(this);
     loadTextFile();
}

XMLFinder::~XMLFinder()
{
    delete ui;
}

void XMLFinder::on_findButton_clicked()
{

         QString searchString = ui->lineEdit->text();
         ui->textEdit->find(searchString, QTextDocument::FindWholeWords);

}

void XMLFinder::loadTextFile()
{
    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);

}
