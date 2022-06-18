#include "utils.h"

unsigned int Utils::convertDollarToCent(float pDollar)
{
    return pDollar * A_DOLLAR_TO_CENT;
}

float Utils::convertCentToDollar(unsigned int pCent)
{
    return (static_cast<float>(pCent) / A_DOLLAR_TO_CENT);
}

float Utils::round(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

Utils::Utils()
{

}
