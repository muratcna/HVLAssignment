#include "filereaderbase.h"
#include <iostream>

FileReaderBase::FileReaderBase(std::string pFileName)
    :mFileName(pFileName)
{
    mFileStream.open(pFileName, std::ios::in);
//    std::cout << "FileReaderBase::FileReaderBase open " <<  mFileName << "for parsing" << std::endl;
}
