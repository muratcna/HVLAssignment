#include "moneyentrancemenu.h"

MoneyEntranceMenu::MoneyEntranceMenu(std::vector<Coin> pCoins)
    : MenuBase()
    , mCoins(pCoins)
    , mCustomerBalance(0)
{

}

bool MoneyEntranceMenu::manageProcess()
{
    while (true) {
        manage();
        unsigned int tCommand = 0;

        while (std::cout << "Your wish:" && !(std::cin >> tCommand)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            std::cout << "Invalid input; please re-enter.\n";
        }

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
