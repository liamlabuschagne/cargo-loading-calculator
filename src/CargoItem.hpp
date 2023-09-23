#pragma once
#include <vector>
#include <stdexcept>
#include <string>

class CargoItem {
    const float MAX_MASS = 200;
    const float MAX_VOLUME = 2;

    unsigned int id;
    float mass;
    std::vector<float> dimensions;

public:
    CargoItem(unsigned int id, float mass, std::vector<float> dimensions);

    unsigned int getId();

    float getMass();

    float getVolume();
};