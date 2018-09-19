#ifndef XMLREPLACER_H
#define XMLREPLACER_H

#include <QDomDocument>
#include<QStringList>

class XMLReplacer
{
public:
    XMLReplacer(QDomDocument docum) ;

    void setTagList(const QString &strList);
    void setPropertyRepl(const QString &str);
    void setReplaceList(const QString &str);
    void replace();
private:
    QDomDocument  doc;
    QStringList  tagList;

    QString propertyRepl;
    QDomNodeList itemList;
    QStringList  replaceList;

};

#endif // XMLREPLACER_H
