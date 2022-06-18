#ifndef ENUMS_H
#define ENUMS_H

class Enums{

public:
    enum class  CoinType: unsigned int{
        DOLLAR = 36,
        CENT = 99,
        UNKNOWN
    };

    enum class MenuType: unsigned int{
        MONEY_ENTRANCE_MENU = 1,
        DRINK_CHOOSE_MENU = 2,
        FINISH_PROCESS_MENU = 3,
        MAINTAINCE_MENU = 4
    };
};

#endif // ENUMS_H
