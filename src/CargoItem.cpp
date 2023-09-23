#include "CargoItem.hpp"

CargoItem::CargoItem(unsigned int id, float mass, std::vector<float> dimensions){
    if(mass <= 0){
        throw std::invalid_argument("Mass must be positive");
    }

    if(mass >= MAX_MASS){
        throw std::invalid_argument("Mass must not exceed " + std::to_string(MAX_MASS) + "kg");
    }

    const float volume = dimensions[0]*dimensions[1]*dimensions[2];

    if(volume <= 0){
        throw std::invalid_argument("Volume must be positive");
    }

    if(volume > 2){
        throw std::invalid_argument("Volume must not exceed " + std::to_string(MAX_VOLUME) + "m^3");
    }

    this->id = id;
    this->mass = mass;
    this->dimensions = dimensions;
}

unsigned int CargoItem::getId(){
    return id;
}

float CargoItem::getMass(){
    return mass;
}

float CargoItem::getVolume(){
    return dimensions[0]*dimensions[1]*dimensions[2];
}