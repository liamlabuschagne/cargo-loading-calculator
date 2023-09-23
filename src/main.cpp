#include <iostream>
#include <memory>
#include <cmath>
#include "parse_cargo_file.hpp"
#include "best_fit_decreasing.hpp"

int main(int argc, char** argv){
    // Show usage information if not correct number of arguments
    if(argc!=2){
        std::cout << "Usage: CargoLoadingCalculator <cargo.yaml>" << std::endl;
        return -1;
    }

    // Parse the file
    std::string file = argv[1];
    std::cout << "Loading yaml file: " << file << std::endl;
    std::vector<std::unique_ptr<CargoItem>> items;
    try {
        items = parse_cargo_file(file);
    }catch(std::invalid_argument e){
        std::cout << e.what() << std::endl;
        return -1;
    }

    // Print out parsed items
    for(auto &item : items){
        std::cout << std::to_string(item.get()->getId()) + ", ";
        std::cout << std::to_string(item.get()->getMass()) + ", ";
        std::cout << std::to_string(item.get()->getVolume());
        std::cout << std::endl;
    }

    std::cout << "Trolleys needed: "+ std::to_string(best_fit_decreasing(items)) << std::endl;

    // Compute some of masses
    float sum = 0;
    for(auto &item : items){
        sum+= item->getMass();
    }
    std::cout << "Total mass: " + std::to_string(sum) << "kg" << std::endl;
    std::cout << "Optimal trolleys needed: "+std::to_string((int)ceil(sum/2000)) << std::endl;

    return 0;
}