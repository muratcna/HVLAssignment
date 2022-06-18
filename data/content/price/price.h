#ifndef PRICE_H
#define PRICE_H

#include <string>
#include "common/Enums.h"
#include <iostream>
#include "common/utils/utils.h"

class Price
{
public:
    Price();

    bool deSerialize(std::string pPrice);

    float unit() const;

    Enums::CoinType priceType() const;

public:
    friend std::ostream &operator << (std::ostream &pOut, const Price &pPrice)
    {
        pOut << pPrice.unit();
        if(pPrice.priceType() == Enums::CoinType::DOLLAR){
            pOut <<Utils::DOLLAR_CHARACTER;
        }else if (pPrice.priceType() == Enums::CoinType::CENT) {
            pOut <<Utils::CENT_CHARACTER;
        }
        pOut << std::endl;
        return pOut;
    }

private:
    float mUnit;
    Enums::CoinType mPriceType;
};

#endif // PRICE_H
