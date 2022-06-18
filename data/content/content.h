#ifndef CONTENT_H
#define CONTENT_H

#include <string>
#include "price/price.h"
#include <iostream>

class Content
{
public:
    Content();

    bool deSerialize(std::string pLine);

    std::string drinkName() const;

    Price price() const;

    int loadedDrinkCount() const;

    void setLoadedDrinkCount(int loadedDrinkCount);

public:
    friend std::ostream &operator << (std::ostream &pOut, const Content &pContent)
    {
        pOut << pContent.drinkName() << ",";
        pOut << pContent.loadedDrinkCount() << ",";
        pOut << pContent.price();
        return pOut;
    }

private:
    std::string mDrinkName;
    Price mPrice;
    int mLoadedDrinkCount;
};

#endif // CONTENT_H
