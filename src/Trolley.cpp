#include "CargoItem.hpp"

class Trolley {
    const float MAX_MASS = 2000;
    float mass = 0;
public:
    void add(CargoItem *item){
        if(mass + item->getMass() > MAX_MASS)
            throw std::overflow_error("Trolley mass must not exceed " + std::to_string(MAX_MASS) + "kg");
        mass+=item->getMass();
    }

    float getSpaceRemaining(){
        return MAX_MASS-mass;
    }
};