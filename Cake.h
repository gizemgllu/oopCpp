#pragma once
#ifndef CAKE
#define CAKE


#include "CakeSpec.h"
#include "Item.h"

#include <string>
#include <memory>
#include <iostream>


using namespace std;

class Cake : public Item
        {
public:

    Cake() = default; // default

    Cake(int id, double price, const std::string & flavor, std::shared_ptr<const CakeSpec> spec)
            : Item(id, spec), _price(price), _flavor(flavor)
            {}


    double get_price() const { return _price; }
    std::string get_flavor() const {  return _flavor;  }
   // spcCakeSpec get_spec() const { return _spec; } // getter for spec class


     // to serialization
    void send_to(std::ostream & os) const override; // new send func with item class
    void recv_from(std::istream & is) override; // to deserialization
   // friend std::istream & operator>>(std::istream & is, Cake & item); // uses recv_from


private:
    double _price;
    std::string _flavor;
};


// std::ostream& operator<<(std::ostream & os, const Cake & item); // to serialization cakes

#endif