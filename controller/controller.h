#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string.h>

class MenuManager;
class CoinFileReader;
class ContentFileReader;

class Controller
{
public:
    Controller(std::string pPriceFile, std::string pCoinFile);

    void mainLoop();

private:
    MenuManager *mMenuManager;
    CoinFileReader *mCoinFileReader;
    ContentFileReader *mContentFileReader;
};

#endif // CONTROLLER_H
