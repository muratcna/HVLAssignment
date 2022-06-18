#include "controller.h"

#include <filereader/coinfilereader/coinfilereader.h>

#include <filereader/contentfilereader/contentfilereader.h>

#include <menumanager/menumanager.h>

Controller::Controller(std::string pPriceFile, std::string pCoinFile)
    : mMenuManager(nullptr)
    , mCoinFileReader(nullptr)
    , mContentFileReader(nullptr)
{
    mCoinFileReader = new CoinFileReader(pCoinFile);
    mContentFileReader = new ContentFileReader(pPriceFile);
}

void Controller::mainLoop()
{
    if(!mCoinFileReader->readFile()){
        std::cout << "Error while reading Coins.txt" << std::endl;
        return;
    }

    if(!mContentFileReader->readFile()){
        std::cout << "Error while reading Prices.txt" << std::endl;
        return;
    }

    mMenuManager = new MenuManager(mContentFileReader->contents(), mCoinFileReader->coins());

//    std::cout << (*mCoinFileReader) <<  std::endl;
//    std::cout << (*mContentFileReader) <<  std::endl;

    mMenuManager->manage();
}
