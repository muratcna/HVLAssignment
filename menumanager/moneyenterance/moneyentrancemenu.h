#ifndef MONEYENTRANCEMENU_H
#define MONEYENTRANCEMENU_H

#include "menumanager/menubase/menubase.h"
#include "data/coin/coin.h"
#include <vector>

class MoneyEntranceMenu : public MenuBase
{
public:
    MoneyEntranceMenu(std::vector<Coin> pCoins);

    float customerBalance() const;
    void setCustomerBalance(float customerBalance);

    // MenuBase interface
public:
    bool manageProcess() override;


private:
    void manage();
    void calculateBalance(unsigned int pCommand);

private:
    float mCustomerBalance;

private:
    std::vector<Coin> mCoins;
};

#endif // MONEYENTRANCEMENU_H
