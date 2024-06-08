#pragma once
#include "Item.h"
#include "DrinksSpec.h"

#include <memory>
#include <string>


class Drinks : public Item {
public:
    Drinks() = default;
    virtual ~Drinks() = default;
    Drinks(int id, double price, std::shared_ptr<const DrinksSpec> spec)
            : Item(id, spec), _price(price) {}

    double get_price() const { return _price; }

    void send_to(std::ostream & os) const override;
    void recv_from(std::istream & is) override;

private:
    double _price;
};
