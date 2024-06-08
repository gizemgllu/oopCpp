
#include "Item.h"
#include "DrinksSpec.h"
#include "CakeSpec.h"
#include <iostream>


void Item::send_to(std::ostream& os) const
{
    os << _id;

    if (_spec)
    {
        _spec->send_to(os);
    }
}


std::ostream & operator<<(std::ostream & os, const Item & item)
{
    item.send_to(os);
    os << "Item ID: " << item.get_id();
    return os;
}



void Item::recv_from(std::istream & is)
{
    if (is)
        is >> _id; // Deserialize the item ID

    // Deserialize type identifier
    std::string specType;
    if (is >> specType) {
        if (specType == "CakeSpec") {
            auto temp_spec{ std::make_shared<CakeSpec>() };
            temp_spec->recv_from(is);
            set_spec(temp_spec);
        } else if (specType == "DrinksSpec") {
            auto temp_spec{ std::make_shared<DrinksSpec>() };
            temp_spec->recv_from(is);
            set_spec(temp_spec);
        }
    }
}



std::istream& operator>>(std::istream & is, Item & item)
{
    item.recv_from(is);
    return is;
}

