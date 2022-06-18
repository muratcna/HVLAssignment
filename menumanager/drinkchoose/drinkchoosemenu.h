#ifndef DRINKCHOOSEMENU_H
#define DRINKCHOOSEMENU_H

#include "menumanager/menubase/menubase.h"
#include <vector>
#include <data/content/content.h>

class DrinkChooseMenu : public MenuBase
{
public:
    DrinkChooseMenu(std::vector<Content> pContents);

    void setUserBalance(float userBalance);
    float currentSpend() const;


    // MenuBase interface
public:
    bool manageProcess() override;

    std::vector<std::pair<std::string, Price> > customerChoosedDrink() const;

private:
    void printDrink();
    void checkIfBalanceEnough(unsigned int pCommand);

private:
    float mUserBalance;
    float mCurrentSpend;
    std::vector<Content> mContents;
    std::vector<std::pair<std::string, Price>> mCustomerChoosedDrink;
};

#endif // DRINKCHOOSEMENU_H
