#include "coin.h"
#include "common/utils/utils.h"
#include <iostream>

Coin::Coin()
    : mCoinType(Enums::CoinType::UNKNOWN)
    , mUnit(0)
{

}

bool Coin::deSerialize(std::string pLine)
{
    bool tPriceResult = true;
    size_t tDollarPos = pLine.find(Utils::DOLLAR_CHARACTER);
    size_t tCentPos = pLine.find(Utils::CENT_CHARACTER);
    if (tDollarPos != std::string::npos){
        mUnit = stoi(pLine.substr(0, tDollarPos));
        mCoinType = Enums::CoinType::DOLLAR;
    }
    else if(tCentPos != std::string::npos){
        mUnit = stoi(pLine.substr(0, tCentPos));
        mCoinType = Enums::CoinType::CENT;
    }else {
        tPriceResult = false;
    }

    return tPriceResult;
}

Enums::CoinType Coin::coinType() const
{
    return mCoinType;
}

unsigned int Coin::unit() const
{
    return mUnit;
}
