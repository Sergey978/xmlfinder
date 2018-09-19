#ifndef XMLREADER_H
#define XMLREADER_H

#include <QDomDocument>
#include <QFile>

class XMLReader
{
public:
    XMLReader(const QString fileName);
    QDomDocument getXmlDoument();

   private:

    QDomDocument  doc;
    QFile file;


};

#endif //XMLREADER_H
