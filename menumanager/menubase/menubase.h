#ifndef MENUBASE_H
#define MENUBASE_H

class MenuBase
{
public:
    MenuBase(){

    }

    virtual bool manageProcess() = 0;
};

#endif // MENUBASE_H
