#include "price.h"
#include "common/utils/utils.h"

Price::Price()
    : mUnit(0)
    , mPriceType(Enums::CoinType::UNKNOWN)
{

}

bool Price::deSerialize(std::string pPrice)
{
    size_t tDollarPos = pPrice.find(Utils::DOLLAR_CHARACTER);
    size_t tCentPos = pPrice.find(Utils::CENT_CHARACTER);
    if (tDollarPos != std::string::npos){
        mUnit = stof(pPrice.substr(0, tDollarPos + 1));
        mPriceType = Enums::CoinType::DOLLAR;
    }
    else if(tCentPos != std::string::npos){
        mUnit = stof(pPrice.substr(0, tCentPos + 1));
        mPriceType = Enums::CoinType::CENT;
    }else {
        //TODO
        return false;
    }

    return true;
}

float Price::unit() const
{
    return mUnit;
}

Enums::CoinType Price::priceType() const
{
    return mPriceType;
}
