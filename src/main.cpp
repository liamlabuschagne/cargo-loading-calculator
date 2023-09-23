#include <iostream>
#include <memory>
#include "parse_cargo_file.hpp"

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
    for(int i = 0; i < items.size(); i++){
        std::cout << std::to_string(items[i].get()->getId()) + ", ";
        std::cout << std::to_string(items[i].get()->getMass()) + ", ";
        std::cout << std::to_string(items[i].get()->getVolume());
        std::cout << std::endl;
    }

    return 0;
}