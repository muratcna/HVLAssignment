#ifndef FINISHPROCESSMENU_H
#define FINISHPROCESSMENU_H

#include "menumanager/menubase/menubase.h"

class FinishProcessMenu  : public MenuBase
{
public:
    FinishProcessMenu();

    void giveChange(float pBalance);

    // MenuBase interface
public:
    bool manageProcess() override;

};

#endif // FINISHPROCESSMENU_H
