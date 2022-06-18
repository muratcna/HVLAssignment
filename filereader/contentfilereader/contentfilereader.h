#ifndef CONTENTFILEREADER_H
#define CONTENTFILEREADER_H

#include <vector>
#include "data/content/content.h"
#include "filereader/filereaderbase.h"
#include <iostream>

class ContentFileReader : public FileReaderBase
{
public:
    ContentFileReader(std::string pFileName);

    std::vector<Content> contents() const;


public:
    friend std::ostream &operator << (std::ostream &pOut, const ContentFileReader &pContentFileReader)
    {
        pOut << "-------------------------------CONTENTS------------------------------" << std::endl;
        for(int i = 0; i < pContentFileReader.contents().size(); ++i){
            pOut << (i + 1) << ":" <<   pContentFileReader.contents().at(i);
        }
        pOut << "-------------------------------------------------------------" << std::endl;
        pOut << std::endl;
        return pOut;
    }

    // FileReaderBase interface
public:
    bool readFile() override;

private:
    std::vector<Content> mContents;
};

#endif // CONTENTFILEREADER_H
