#include "Cake.h"
#include "Log.h"
#include "Drinks.h"
#include "Item.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// updated show func with new Item class

void show(const Item & item)
{
    cout << item << "\n";
}


/*Cake max_price(const Log &log) {
    size_t itemCount = log.get_count();
    if (itemCount == 0) {
        return Cake{}; //  default object = log is empty
    }

    const Item &firstItem = log.get_item(0);
    // Downcasting
    const Cake *maxPCake = dynamic_cast<const Cake*>(&firstItem);
    if (!maxPCake) {
        // default Cake object
        return Cake{};
    }

    double maxP = maxPCake->get_price();

    for (size_t i = 1; i < itemCount; ++i) {
        const Item &item = log.get_item(i);
        // Downcast
        const Cake *cake = dynamic_cast<const Cake*>(&item);
        if (cake) {
            double currentPrice = cake->get_price();
            if (currentPrice > maxP) {
                maxP = currentPrice;
                maxPCake = cake;
            }
        }
    }

    return *maxPCake;
}



double avg_price(const Log &log) {
    double total = 0.0;
    size_t count = log.get_count();

    if (count == 0) return 0.0;
    for (size_t i = 0; i < count; ++i) {
        const auto &item = log.get_item(i);
        // Downcast to the derived Cake type
        const auto &cake = dynamic_cast<const Cake&>(item);
        total += cake.get_price();
    }
    return total / count;
}
*/

int main() {
   /* Log log;


    auto cake_spec1{ std::make_shared<CakeSpec>(CakeSpec::Taste::CHOCOLATE, 2)};
    auto cake1 { std::make_shared<Cake>(1, 19.99, "Chocolate", cake_spec1)};
    log.add_item(cake1);


    auto cake2 { std::make_shared<Cake>(2, 15.99, "Caramel", std::make_shared<CakeSpec>(CakeSpec::Taste::CARAMEL, 3))};
    log.add_item(cake2);


    auto cake_spec3 {std::make_shared<CakeSpec>(CakeSpec::Taste::STRAWBERRY, 1)};
    log.add_item(std::make_shared<Cake>(3, 21.99, "Strawberry", cake_spec3));
    log.add_item(std::make_shared<Cake>(4, 18.99, "Blueberry", cake_spec3));

    show(log.find_item(CakeSpec{ CakeSpec::Taste::ANY, 20}));

    show(log.find_item(*cake_spec3));
    show(log.find_item(CakeSpec{}));

    show(log.find_item(CakeSpec{ CakeSpec::Taste::CHOCOLATE, 0}));


*/

    return 0;
}