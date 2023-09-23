#include "CargoItem.hpp"

class Trolley {
    const float MAX_MASS = 2000;
    float mass = 0;
public:
    void add(CargoItem *item);

    float getSpaceRemaining();
};