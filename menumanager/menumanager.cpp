#include "menumanager.h"
#include "moneyenterance/moneyentrancemenu.h"
#include "drinkchoose/drinkchoosemenu.h"
#include "finisprocess/finishprocessmenu.h"
#include "maintaince/maintaincemenu.h"
#include <iostream>

MenuManager::MenuManager(std::vector<Content> pContents, std::vector<Coin> pCoins)
{
    //    mMenuContainer.insert(std::make_pair(Enums::MenuType::MONEY_ENTRANCE_MENU, new MoneyEntranceMenu(pCoins)));
    //    mMenuContainer.insert(std::make_pair(Enums::MenuType::DRINK_CHOOSE_MENU, new DrinkChooseMenu()));
    //    mMenuContainer.insert(std::make_pair(Enums::MenuType::FINISH_PROCESS_MENU, new FinishProcessMenu()));
    //    mMenuContainer.insert(std::make_pair(Enums::MenuType::MAINTAINCE_MENU, new MaintainceMenu()));

    mMoneyEntranceMenu = new MoneyEntranceMenu(pCoins);
    mDrinkChooseMenu = new DrinkChooseMenu(pContents);
    mFinishProcessMenu = new FinishProcessMenu();
    mMaintainceMenu = new MaintainceMenu();
}

void MenuManager::manage()
{

    while (true) {
        std::cout << "------------------------Menu--------------------------" << std::endl;
        std::cout << "Please Choose Your wish" << std::endl;
        std::cout << "1 for Money Enterance" << std::endl;
        std::cout << "2 for Choose Drink" << std::endl;
        std::cout << "3 for Finish Process" << std::endl;
        std::cout << "4 for Maintaince" << std::endl;

        std::cout << "Your wish:";
        unsigned int tCommand;
        std::cin >> tCommand;

        if(tCommand == static_cast<int>(Enums::MenuType::MONEY_ENTRANCE_MENU)){
            mMoneyEntranceMenu->manageProcess();
        }else if (tCommand == static_cast<int>(Enums::MenuType::DRINK_CHOOSE_MENU)) {
            if(Utils::round(mMoneyEntranceMenu->customerBalance()) == 0){
                std::cout << "Your balance is not enough" << std::endl;
            }else {
                mDrinkChooseMenu->setUserBalance(mMoneyEntranceMenu->customerBalance());
                mDrinkChooseMenu->manageProcess();
                mMaintainceMenu->setSellerBalance(mMaintainceMenu->sellerBalance() + mDrinkChooseMenu->currentSpend());
                mMoneyEntranceMenu->setCustomerBalance(mMoneyEntranceMenu->customerBalance() - mDrinkChooseMenu->currentSpend());
            }
        }else if (tCommand == static_cast<int>(Enums::MenuType::FINISH_PROCESS_MENU)) {
            mFinishProcessMenu->giveChange(mMoneyEntranceMenu->customerBalance());
            mFinishProcessMenu->manageProcess();
        }else if (tCommand == static_cast<int>(Enums::MenuType::MAINTAINCE_MENU)) {
            mMaintainceMenu->manageProcess();
        }else {
            std::cout << "undefined command" << std::endl;
        }

    }

    //manage process acoording to command
    return;
}



//auto tIter = mMenuContainer.find(static_cast<Enums::MenuType>(tCommand));
//if(tIter == mMenuContainer.end()){
//    std::cout << "MenuManager::handle tCommand not found" << std::endl;
//    return;
//}

//tIter->second->manageProcess();
