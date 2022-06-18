#include <iostream>

#include <controller/controller.h>

int main(int argc, char** argv)
{
    if(argc < 2){
        std::cout << "Error argument must contains location of Coin.txt and Prices.txt files" << std::endl;
        Controller tController("Prices.txt", "Coins.txt");
        tController.mainLoop();
    }else {
        Controller tController(argv[0], argv[1]);
        tController.mainLoop();
    }

    return 0;
}
