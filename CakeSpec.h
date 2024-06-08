#pragma once

#ifndef CAKE_SPEC
#define CAKE_SPEC

#include "ItemSpec.h"
#include <cstddef>
#include <string>
#include <iostream>
#include "ItemSpec.h"

#include <memory>



class CakeSpec: public ItemSpec  {
public:

    enum class Taste { ANY, BANANA, CHOCOLATE, CARAMEL, STRAWBERRY };
    static constexpr std::string_view Taste_str[] { "Any", "Banana", "Chocolate", "Caramel", "Strawberry" };


    CakeSpec() = default;

    CakeSpec(Taste taste, unsigned short candle_number)
            : _taste{ taste }
            , _candle_number{ candle_number }
    { }


    Taste get_taste() const { return _taste; }
    unsigned short get_candle_number() const { return _candle_number; }

    void send_to(std::ostream & os) const override; // takes the parameter to make it easier
    void recv_from(std::istream & is) override;

    bool matches(const ItemSpec & itemSpec) const override; // check same obj



private:
    Taste _taste;
    unsigned short _candle_number;
};

std::ostream & operator<<(std::ostream & os, CakeSpec::Taste taste);
std::istream & operator>>(std::istream & is, CakeSpec::Taste & taste);


#endif
