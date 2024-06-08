//
// Created by gizem güllü on 29.04.2024.
//

#include "Drinks.h"

#include "Drinks.h"

void Drinks::send_to(std::ostream & os) const {
    Item::send_to(os);

    os << ';' << _price;
}

void Drinks::recv_from(std::istream & is)
{
    Item::recv_from(is);

    if (is)
        (is >> _price).ignore();
}