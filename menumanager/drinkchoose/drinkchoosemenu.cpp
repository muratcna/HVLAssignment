#include "drinkchoosemenu.h"

DrinkChooseMenu::DrinkChooseMenu(std::vector<Content> pContents)
    : MenuBase()
    , mUserBalance(0)
    , mContents(pContents)
{

}

bool DrinkChooseMenu::manageProcess()
{
    while (true) {
        printDrink();
        unsigned int tCommand;
        std::cin >> tCommand;
        if(tCommand == 0){
            std::cout << "Drink choose process finished" << std::endl;
            break;
        }else if(tCommand <= mContents.size()) {
            checkIfBalanceEnough(tCommand);
        }else {
            std::cout << "Your command not valid" <<  std::endl;
        }
    }
    return true;
}

void DrinkChooseMenu::printDrink()
{
    std::cout << "Please choose your drink according to your balance, balance:" << (Utils::round(mUserBalance) - Utils::round(mCurrentSpend)) << "$" << std::endl;
    std::cout << "0 for Exit" << std::endl;
    for(int i = 0; i < mContents.size(); ++i){
        if(mContents.at(i).loadedDrinkCount() != 0){
            std::cout << (i + 1)  << " for " << mContents.at(i);
        }
    }
}

void DrinkChooseMenu::checkIfBalanceEnough(unsigned int pCommand)
{
    if(mContents.at(pCommand - 1).loadedDrinkCount() == 0){
        std::cout << "Your command not valid" <<  std::endl;
        return;
    }
    unsigned int  tIndex = mCustomerChoosedDrink.size();
    mCustomerChoosedDrink.push_back(std::make_pair(mContents.at(pCommand - 1).drinkName(), mContents.at(pCommand -1).price()));

    float tCurrentSpend = 0;
    for(int i = 0; i < mCustomerChoosedDrink.size(); ++i){
        if(mCustomerChoosedDrink.at(i).second.priceType()== Enums::CoinType::DOLLAR){
            tCurrentSpend += mCustomerChoosedDrink.at(i).second.unit();
        }else if (mCustomerChoosedDrink.at(i).second.priceType() == Enums::CoinType::CENT) {
            tCurrentSpend += Utils::convertCentToDollar(mCustomerChoosedDrink.at(i).second.unit());
        }
    }
    if(Utils::round(tCurrentSpend) > Utils::round(mUserBalance)){
        std::cout << "Your balance not enough" << std::endl;
        mCustomerChoosedDrink.erase(mCustomerChoosedDrink.begin() + tIndex);
        return;
    }

    std::cout << "Bought:" << mContents.at(pCommand - 1).drinkName() << " and price:" << mContents.at(pCommand -1).price() << "$" << std::endl;
    std::cout << "Your total spending money:" << Utils::round(tCurrentSpend) << std:: endl;
    std::cout << "Enjoy your meal" << std::endl;

    mContents.at(pCommand - 1).setLoadedDrinkCount((mContents.at(pCommand - 1).loadedDrinkCount() - 1));
    mCurrentSpend = tCurrentSpend;
}

float DrinkChooseMenu::currentSpend() const
{
    return mCurrentSpend;
}

void DrinkChooseMenu::setUserBalance(float userBalance)
{
    mUserBalance = userBalance;
}

std::vector<std::pair<std::string, Price> > DrinkChooseMenu::customerChoosedDrink() const
{
    return mCustomerChoosedDrink;
}
