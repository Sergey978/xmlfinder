#include "xmlreader.h"

XMLReader::XMLReader(const QString fileName)
{
 file.setFileName(fileName);
  if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file));

}

QDomDocument XMLReader::getXmlDoument()
{


            return doc;

}

