//
// Created by gizem güllü on 29.04.2024.
//
#pragma once
#include <string>

#ifndef ITEM_SPEC
#include <iostream>

class ItemSpec
{
public:

    ItemSpec() = default;
    virtual ~ItemSpec() = default;

    virtual void send_to(std::ostream & os) const = 0;
    virtual void recv_from(std::istream & os) = 0;
    virtual bool matches(const ItemSpec & itemSpec) const = 0;
};

std::ostream& operator<<(std::ostream & os, const ItemSpec & spec);
std::istream& operator>>(std::istream & is, ItemSpec & item);

// helper constant
constexpr auto csv_delimiter { ';' };

#endif // !ITEM_SPEC
