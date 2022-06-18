#include "contentfilereader.h"
#include <iostream>
#include <string>
#include "common/utils/utils.h"

ContentFileReader::ContentFileReader(std::string pFileName)
    : FileReaderBase(pFileName)
{

}

bool ContentFileReader::readFile()
{
    if (!mFileStream.is_open()) {
        std::cout << "ContentFileReader::readFile  can not open" << std::endl;
        return false;
    }

    std::string tContentString;
    while (mFileStream.good()) {
        getline(mFileStream, tContentString);
        Content tContent;
        if(tContent.deSerialize(tContentString)){
            mContents.push_back(tContent);
        }
    }

    return (mContents.size() > 0);
}

std::vector<Content> ContentFileReader::contents() const
{
    return mContents;
}
