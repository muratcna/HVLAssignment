#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <map>
#include <vector>
#include "data/content/content.h"
#include "data/coin/coin.h"
#include "common/Enums.h"
#include "menubase/menubase.h"

class MaintainceMenu;
class DrinkChooseMenu;
class MoneyEntranceMenu;
class FinishProcessMenu;

class MenuManager
{
public:
    MenuManager(std::vector<Content> pContents, std::vector<Coin> pCoins);

    void manage();

private:
//    std::map<Enums::MenuType, MenuBase*> mMenuContainer;

   MaintainceMenu *mMaintainceMenu;
   DrinkChooseMenu *mDrinkChooseMenu;
   MoneyEntranceMenu *mMoneyEntranceMenu;
   FinishProcessMenu *mFinishProcessMenu;
};

#endif // MENUMANAGER_H
