#pragma once
#include "ItemSpec.h"


#include <cstddef> // for std::size_t
#include <iostream>

class DrinksSpec : public ItemSpec {
public:

    enum class Type { ANY, WATER, JUICE, SODA };
    static constexpr std::string_view Type_str[]{ "Any", "Water", "Juice", "Soda" };

    DrinksSpec() = default;
    DrinksSpec(const std::string & sugarType, Type type)
            : ItemSpec(), _sugarType(sugarType), _type(type) {}

    Type get_type() const { return _type; }
    std::string get_sugarType() const { return _sugarType; }

    void send_to(std::ostream & os) const override;
    void recv_from(std::istream & is) override ;

    bool matches(const ItemSpec & itemSpec) const override;



private:

    std::string _sugarType;
    Type _type = Type::ANY;

};

std::ostream & operator<<(std::ostream & os, DrinksSpec::Type type);
std::istream & operator>>(std::istream & is, DrinksSpec::Type & type);

