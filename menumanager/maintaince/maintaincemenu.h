#ifndef MAINTAINCEMENU_H
#define MAINTAINCEMENU_H

#include "menumanager/menubase/menubase.h"

class MaintainceMenu : public MenuBase
{
public:
    MaintainceMenu();

    float sellerBalance() const;
    void setSellerBalance(float sellerBalance);

    // MenuBase interface
public:
    bool manageProcess() override;

private:
    float mSellerBalance;
};

#endif // MAINTAINCEMENU_H
