#ifndef COIN_H
#define COIN_H

#include <iostream>
#include "common/Enums.h"
#include "common/utils/utils.h"

class Coin
{
public:
    Coin();

    bool deSerialize(std::string pLine);

    Enums::CoinType coinType() const;

    unsigned int unit() const;


public:
    friend std::ostream &operator << (std::ostream &pOut, const Coin &pCoin)
    {
        pOut << pCoin.unit();
        if(pCoin.coinType() == Enums::CoinType::DOLLAR){
            pOut <<Utils::DOLLAR_CHARACTER;
        }else if (pCoin.coinType() == Enums::CoinType::CENT) {
            pOut <<Utils::CENT_CHARACTER;
        }
        pOut << std::endl;
        return pOut;
    }


private:
    Enums::CoinType mCoinType;
    unsigned int mUnit;
};

#endif // COIN_H
