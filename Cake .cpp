#include "Cake.h"


    void Cake::send_to(std::ostream & os) const {
        Item::send_to(os); // item properties

        os << csv_delimiter << _price
           << csv_delimiter << _flavor; // abstraction properties
    }


   /* void Cake::send_to(std::ostream & os) const // for cake attributes plus spec attb.
    {
        Item::send_to(os);
    }

    std::ostream & operator<<(std::ostream & os, const Cake & item) // make it easier to serialization instead of sento func
    {
    item.send_to(os);
    return os;


    }




    std::istream & operator>>(std::istream & is, Cake & item) // to desr.
    {
        item.recv_from(is);
        return is;
    }

*/
    void Cake::recv_from(std::istream & is) // to desr.
    {
        Item::recv_from(is);

        if (is)
            (is >> _price).ignore();

        if (is)
            getline(is >> std::ws, _flavor, csv_delimiter); // also skips the delimiter

    }






