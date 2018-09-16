#include "xmlfinder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XMLFinder w;
    w.show();

    return a.exec();
}
