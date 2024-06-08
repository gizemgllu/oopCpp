#include "DrinksSpec.h"

#include <string> // for std::getline()

#ifdef _MSC_VER // Visual C++ ?
#define strcasecmp _stricmp // then use the function _stricmp()
#else
#include <strings.h> // for strcasecmp() function in POSIX C++
#endif

bool DrinksSpec::matches(const ItemSpec& itemSpec) const
{
    if (this == &itemSpec)
        return true;  // if comparing to self

    bool result{ true };

    // try to downcast to the required derived specification type
    auto temp{ dynamic_cast<const DrinksSpec*>(&itemSpec) };
    if (nullptr == temp)
        return false; // if itemSpec doesn't refer to GuitarSpec (or derived) class instance

    // cast to reference type for actual comparison of properties
    const DrinksSpec& otherSpec{ *temp };

    if (otherSpec.get_sugarType() != ""
        && otherSpec.get_sugarType() != this->_sugarType)
        result = false;

    if (otherSpec.get_type() != DrinksSpec::Type::ANY
        && otherSpec.get_type() != this->_type)
        result = false;

    return result;
}

void DrinksSpec::send_to(std::ostream & os) const {
    os << "Type: " << _type << ", Sugar Type: " << (_sugarType);
}

void DrinksSpec::recv_from(std::istream & is)
{
    if (is)
        getline(is >> std::ws, _sugarType, ';'); // also skips the delimiter

    if (is)
        is >> _type;
}


std::ostream & operator<<(std::ostream & os, DrinksSpec::Type type) {
    os << DrinksSpec::Type_str[static_cast<std::size_t>(type)];
    return os;
    }



std::istream & operator>>(std::istream & is, DrinksSpec::Type & type)
{
    if (is)
    {
        std::string tmp;
        getline(is, tmp, ';');

        if (is)
        {
            bool found{ false };

            for (size_t i{ 0 }; i < sizeof(DrinksSpec::Type_str)/sizeof(DrinksSpec::Type_str[0]); i++)
            {
                if (tmp.length() == DrinksSpec::Type_str[i].length()
                    && 0 == strcasecmp(tmp.c_str(), std::string(DrinksSpec::Type_str[i]).c_str())) // case insensitive comparison
                {
                    type = static_cast<DrinksSpec::Type>(i);
                    found = true;
                    break;
                }
            }

            if (!found)
                type = DrinksSpec::Type::ANY;
        }
    }
    return is;
}


