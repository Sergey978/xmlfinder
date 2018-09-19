#include "xmlreplacer.h"
#include "QDebug"

XMLReplacer::XMLReplacer(QDomDocument docum)
{
doc = docum;
}


void XMLReplacer::setTagList(const QString &strList)
{
    tagList = strList.split(",");
}

void XMLReplacer::setPropertyRepl(const QString &str)
{
    propertyRepl = str;
}

void XMLReplacer::setReplaceList(const QString &str)
{
    QString tmp = str;
    tmp.remove("\n");
    replaceList =  tmp.split(",");
    qDebug() << replaceList;
}

void XMLReplacer::replace()
{
    itemList = doc.elementsByTagName(tagList[0]);
    for (int i = 0; i <itemList.size(); i++)
    {
        QDomNode itemNode = itemList.item(i);
        QDomElement secondTag = itemNode.firstChildElement(tagList[1]);
        if (secondTag.isNull() )
            continue;
        else
        {
            if (  replaceList.contains(secondTag.text()))
            {
                QDomElement replaceTag =  itemNode.firstChildElement("name");
                QString text =replaceTag.text();
                replaceTag.setNodeValue(propertyRepl + text);
            }
        }
    }
}
