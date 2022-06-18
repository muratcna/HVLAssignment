#ifndef COINFILEREADER_H
#define COINFILEREADER_H

#include <vector>
#include "filereader/filereaderbase.h"
#include "data/coin/coin.h"
#include <iostream>

class CoinFileReader : public FileReaderBase
{
public:
    CoinFileReader(std::string pFileName);

    std::vector<Coin> coins() const;

public:
    friend std::ostream &operator << (std::ostream &pOut, const CoinFileReader &pCoinFileReader)
    {
        pOut << "-------------------------------COINS------------------------------" << std::endl;
        for(int i = 0; i < pCoinFileReader.coins().size(); ++i){
            pOut <<  pCoinFileReader.coins().at(i) << " ";
        }
        pOut << "-------------------------------------------------------------" << std::endl;
        pOut << std::endl;
        return pOut;
    }

    // FileReaderBase interface
public:
    bool readFile() override;

private:
    std::vector<Coin> mCoins;
};

#endif // COINFILEREADER_H
