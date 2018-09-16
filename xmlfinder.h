#ifndef XMLFINDER_H
#define XMLFINDER_H

#include <QWidget>

namespace Ui {
class XMLFinder;
}

class XMLFinder : public QWidget
{
    Q_OBJECT

public:
    explicit XMLFinder(QWidget *parent = nullptr);
    ~XMLFinder();

private slots:
    void on_findButton_clicked();

private:
    Ui::XMLFinder *ui;
    void loadTextFile();

};

#endif // XMLFINDER_H
