TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        common/utils/utils.cpp \
        controller/controller.cpp \
        data/coin/coin.cpp \
        data/content/content.cpp \
        data/content/price/price.cpp \
        filereader/coinfilereader/coinfilereader.cpp \
        filereader/filereaderbase.cpp \
        filereader/contentfilereader/contentfilereader.cpp \
        main.cpp \
        menumanager/drinkchoose/drinkchoosemenu.cpp \
        menumanager/finisprocess/finishprocessmenu.cpp \
        menumanager/maintaince/maintaincemenu.cpp \
        menumanager/menumanager.cpp \
        menumanager/moneyenterance/moneyentrancemenu.cpp

HEADERS += \
    common/Enums.h \
    common/utils/utils.h \
    controller/controller.h \
    data/coin/coin.h \
    data/content/content.h \
    data/content/price/price.h \
    filereader/coinfilereader/coinfilereader.h \
    filereader/filereaderbase.h \
    filereader/contentfilereader/contentfilereader.h \
    menumanager/drinkchoose/drinkchoosemenu.h \
    menumanager/finisprocess/finishprocessmenu.h \
    menumanager/maintaince/maintaincemenu.h \
    menumanager/menubase/menubase.h \
    menumanager/menumanager.h \
    menumanager/moneyenterance/moneyentrancemenu.h
