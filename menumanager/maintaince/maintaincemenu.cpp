#include "maintaincemenu.h"
#include <iostream>
#include <common/utils/utils.h>

MaintainceMenu::MaintainceMenu()
    : MenuBase()
{

}

bool MaintainceMenu::manageProcess()
{
    std::cout << "Till Balance:" << Utils::round(mSellerBalance) << std::endl;
    return true;
}

float MaintainceMenu::sellerBalance() const
{
    return mSellerBalance;
}

void MaintainceMenu::setSellerBalance(float sellerBalance)
{
    mSellerBalance = sellerBalance;
}
