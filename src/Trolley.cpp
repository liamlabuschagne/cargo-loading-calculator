#include "Trolley.hpp"

void Trolley::add(CargoItem *item){
    if(mass + item->getMass() > MAX_MASS)
        throw std::overflow_error("Trolley mass must not exceed " + std::to_string(MAX_MASS) + "kg");
    mass+=item->getMass();
}

float Trolley::getSpaceRemaining(){
    return MAX_MASS-mass;
}