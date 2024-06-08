
#include "CakeSpec.h"

#include <string> // for std::getline()

#ifdef _MSC_VER // Visual C++ ?
#define strcasecmp _stricmp // then use the function _stricmp()
#else
#include <strings.h> // for strcasecmp() function in POSIX C++
#endif


std::ostream & operator<<(std::ostream & os, CakeSpec:: Taste t)
{
    os << CakeSpec::Taste_str[static_cast<std::size_t>(t)];
    return os;
}



std::istream & operator>>(std::istream & is, CakeSpec::Taste & taste)
{
    if (is)
    {
        std::string tmp;
        getline(is, tmp, csv_delimiter);
        if (is)
        {
            bool found{ false };

            for (size_t i{ 0 }; i < sizeof(CakeSpec::Taste_str) / sizeof(CakeSpec::Taste_str[0]); i++)
            {
                if (tmp.length() == CakeSpec::Taste_str[i].length()
                    && 0 == strcasecmp(tmp.c_str(), std::string(CakeSpec::Taste_str[i]).c_str())) // case insensitive comparison
                {
                    taste = static_cast<CakeSpec::Taste>(i);
                    found = true;
                    break;
                }
            }

            if (!found)
                taste = CakeSpec::Taste::ANY;
        }
    }

    return is;
}



/*
std::ostream & operator<<(std::ostream & os, CakeSpec:: Proportions proportions)
{
    return os << CakeSpec::Proportions_str[static_cast<size_t>(proportions)];
}



std::ostream & operator<<(std::ostream & os, const CakeSpec & spec)  // uses send_to func
{
    spec.send_to(os);
    return os;
}

*/


void CakeSpec::send_to(std::ostream & os) const {

    os << csv_delimiter << _taste
       << csv_delimiter << _candle_number;
}




void CakeSpec::recv_from(std::istream & is)
{

    if (is)
        is >> _taste; // operator>>() processed csv_delimiter

    if (is)
        (is >> _candle_number).ignore(); // call ignore() to skip csv_delimiter

}





// cause itemspec will be used for insert opr.


bool CakeSpec::matches(const ItemSpec & itemSpec) const
{
    if (this == &itemSpec)
        return true;  // if comparing to self

    bool result{ true };

    // try to downcast to the required derived specification type
    auto temp{ dynamic_cast<const CakeSpec*>(&itemSpec) };
    if (nullptr == temp)
        return false; // if itemSpec doesn't refer to BicycleSpec (or derived) class instance

    // cast to reference type for actual comparison of properties
    const CakeSpec& otherSpec{ *temp };

    if (otherSpec.get_taste() != CakeSpec::Taste::ANY
        && otherSpec.get_taste() != this->_taste)
        result = false;

    if (otherSpec.get_candle_number() != 0
        && otherSpec.get_candle_number() != this->_candle_number)
        result = false;


    return result;
}








