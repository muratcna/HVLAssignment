#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cstddef>

class Utils
{
public:
    static unsigned int convertDollarToCent(float pDollar);
    static float convertCentToDollar(unsigned int pCent);
    static float round(float var);

public:
    inline const static std::string COMMA_CHARACTER = ",";
    inline const static std::string DOLLAR_CHARACTER = "$";
    inline const static std::string CENT_CHARACTER = "c";

private:
    Utils();

private:
    static const unsigned int A_DOLLAR_TO_CENT = 100;
};

#endif // UTILS_H
