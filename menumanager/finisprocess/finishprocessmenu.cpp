#include "finishprocessmenu.h"
#include <iostream>
#include <common/utils/utils.h>

FinishProcessMenu::FinishProcessMenu()
    : MenuBase()
{

}

void FinishProcessMenu::giveChange(float pBalance)
{
    std::cout << "You can get change:" << Utils::round(pBalance) << std::endl;
}

bool FinishProcessMenu::manageProcess()
{
    std::cout <<"Have a good day" << std::endl;
    return true;
}
