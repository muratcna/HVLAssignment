#ifndef FILEREADERBASE_H
#define FILEREADERBASE_H

#include <fstream>

class FileReaderBase
{
public:
    FileReaderBase(std::string pFileName);

   virtual bool readFile() = 0;

protected:
    std::fstream mFileStream;

private:
    std::string mFileName;
};

#endif // FILEREADERBASE_H
