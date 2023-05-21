#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>
#include "Markup.h"

class XMLFile {

protected:
    const std::string FILE_NAME;
    const std::string MAIN_TAG;
    CMarkup xml;

public:
    XMLFile(std::string fileName) : FILE_NAME(fileName), MAIN_TAG(FILE_NAME.substr(0, FILE_NAME.length()-4)) {

        bool fileExists = xml.Load( FILE_NAME );
        if ( !fileExists )
        {
            xml.AddElem(FILE_NAME.substr(0, FILE_NAME.length()-4));
            xml.Save( FILE_NAME );
        }

    }

    bool fileIsEmpty()
    {
        bool isEmpty = true;
        std::fstream XMLFile;
        XMLFile.open(FILE_NAME, std::ios::app);

        if (XMLFile.good() == true)
        {
            XMLFile.seekg(0, std::ios::end);
            if (XMLFile.tellg() != 0)
                {isEmpty = false;}
        }

        XMLFile.close();
        return isEmpty;
    }
};

#endif
