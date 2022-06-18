#include "moneyentrancemenu.h"

MoneyEntranceMenu::MoneyEntranceMenu(std::vector<Coin> pCoins)
    : MenuBase()
    , mCoins(pCoins)
{

}

bool MoneyEntranceMenu::manageProcess()
{
    while (true) {
        manage();
        unsigned int tCommand;
        std::cin >> tCommand;
        if(tCommand == 0){
            std::cout << "Money enterance process finished" << std::endl;
            break;
        }else if(tCommand <= mCoins.size()) {
            calculateBalance(tCommand);
        }else {
            std::cout << "Your mone not valid" <<  std::endl;
        }
    }
    return true;
}

void MoneyEntranceMenu::manage()
{
    std::cout << "Please choose your money to inserting" << std::endl;
    std::cout << "0 for Exit" << std::endl;
    for(int i = 0; i < mCoins.size(); ++i){
        std::cout << (i + 1)  << " for " << mCoins.at(i);
    }
}

void MoneyEntranceMenu::calculateBalance(unsigned int pCommand)
{
    if(pCommand > mCoins.size()){
        return;
    }

    Coin tCoin = mCoins.at(pCommand - 1);

    if(tCoin.coinType() == Enums::CoinType::DOLLAR){
        mCustomerBalance += tCoin.unit();
    }else if (tCoin.coinType() == Enums::CoinType::CENT) {
        mCustomerBalance += Utils::convertCentToDollar(tCoin.unit());
    }

    std::cout << "Your Balance:" <<  Utils::round(mCustomerBalance) << "$" << std::endl;
}

void MoneyEntranceMenu::setCustomerBalance(float customerBalance)
{
    mCustomerBalance = customerBalance;
}

float MoneyEntranceMenu::customerBalance() const
{
    return mCustomerBalance;
}
