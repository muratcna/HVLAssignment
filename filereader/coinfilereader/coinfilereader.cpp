#include "coinfilereader.h"
#include <string>

CoinFileReader::CoinFileReader(std::string pFileName)
    : FileReaderBase(pFileName)
{

}

bool CoinFileReader::readFile()
{
    if (!mFileStream.is_open()) {
        std::cout << "CoinFileReader::readFile  can not open" << std::endl;
        return false;
    }
    std::string tCoinString;
    while (mFileStream.good()) {
        getline(mFileStream, tCoinString, Utils::COMMA_CHARACTER.c_str()[0]);
        Coin tCoin;
        if(tCoin.deSerialize(tCoinString)){
            mCoins.push_back(tCoin);
        }
    }

    return (mCoins.size() > 0);
}

std::vector<Coin> CoinFileReader::coins() const
{
    return mCoins;
}
