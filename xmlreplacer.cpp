#include "xmlreplacer.h"
#include "QDebug"
#include <QFile>

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
}

QString XMLReplacer::replace()
{
    QDomElement	rootElement = doc.documentElement();
    for (auto code : replaceList)
    {
      itemList = rootElement.elementsByTagName(tagList[0]);
      for (int i =0; i < itemList.size(); i++ )
      {
          QDomNode itemNode = rootElement.elementsByTagName(tagList[0]).at(i);
          QDomElement secondTag = itemNode.firstChildElement(tagList[1]);
          if (secondTag.isNull() || secondTag.text() != code)
              continue;
          else
          {
              QDomElement replaceTag =  itemNode.firstChildElement("name");
              QString text =replaceTag.text();
              rootElement.elementsByTagName(tagList[0]).at(i).firstChildElement("name")
                       .firstChild().setNodeValue(propertyRepl + text);            
          }

      }
    }



    QFile file( "out.xml" );
    if( !file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
    return QString("Не получилось открыть файл для записи." );

    }
    QTextStream stream( &file );
    stream << doc.toString();
    file.close();
    return QString("Файл записан успешно." );
}
