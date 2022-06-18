#include "content.h"
#include "common/utils/utils.h"

Content::Content()
    : mDrinkName("")
    , mLoadedDrinkCount(0)
{

}

bool Content::deSerialize(std::string pLine)
{
    size_t tDrinkPos = pLine.find(Utils::COMMA_CHARACTER);
    if (tDrinkPos != std::string::npos)
        mDrinkName = pLine.substr(0, tDrinkPos);

    size_t tDrinkCountPos = pLine.find(Utils::COMMA_CHARACTER, tDrinkPos + 1);
    if (tDrinkCountPos != std::string::npos)
        mLoadedDrinkCount = stoi(pLine.substr(tDrinkPos + 1, tDrinkCountPos));

    if(mDrinkName == "" || !(mPrice.deSerialize(pLine.substr(tDrinkCountPos + 1, (pLine.size() - tDrinkCountPos + 1))))){
        return false;
    }

    return true;
}

std::string Content::drinkName() const
{
    return mDrinkName;
}


int Content::loadedDrinkCount() const
{
    return mLoadedDrinkCount;
}

void Content::setLoadedDrinkCount(int loadedDrinkCount)
{
    mLoadedDrinkCount = loadedDrinkCount;
}

Price Content::price() const
{
    return mPrice;
}
