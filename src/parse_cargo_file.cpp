#include "parse_cargo_file.hpp"
#include <iostream>
#include <fstream>
#include <regex>

unsigned int parse_id_line(std::string line){
    
    bool isValid = std::regex_match(line, std::regex("[\\d]+:"));

    if(!isValid)
        throw std::invalid_argument("ID line is malformed");

    // Remove semicolon
    line = line.substr(0,line.length()-1);

    return stoi(line);
}

float parse_mass_line(std::string line){

    bool isValid = std::regex_match(line, std::regex("[ ]+mass: [\\d]+(\\.[\\d]*)?"));

    if(!isValid)
        throw std::invalid_argument("Mass line is malformed");

    const int startPos = line.find_last_of(' ');
    line = line.substr(startPos+1);

    return stof(line);
}

std::vector<float> parse_volume_line(std::string line){

    bool isValid = std::regex_match(line, std::regex("[ ]+volume: \\[[\\d]+(\\.[\\d]*)?,[ ]*[\\d]+(\\.[\\d]*)?,[ ]*[\\d]+(\\.[\\d]*)?\\]"));

    if(!isValid)
        throw std::invalid_argument("Volume line is malformed");

    // Substring up to the first square bracket
    int squareBracketPos = line.find_first_of('[');
    line = line.substr(squareBracketPos+1);

    // Remove all the spaces
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace),line.end());

    // Remove last square bracket
    line = line.substr(0,line.length()-1);

    // Extract x,y,z
    std::stringstream sstr(line);
    std::vector<float> dimensions = {0, 0, 0};
    
    int i = 0;
    while(sstr.good())
    {
        std::string substr;
        getline(sstr, substr, ',');
        dimensions[i] = stof(substr);
        i++;
    }

    return dimensions;
}

std::vector<std::unique_ptr<CargoItem>> parse_cargo_file(std::string filePath){
    std::ifstream cargoIfstream;
	cargoIfstream.open(filePath, std::ios::in);
    if(!cargoIfstream.is_open())
        throw std::invalid_argument("Cargo file does not exist");

    std::vector<std::unique_ptr<CargoItem>> cargoItems = {};
    std::string line;

    unsigned int id;
    float mass = 0;
    std::vector<float> dimensions;

    while(getline(cargoIfstream,line)){
        if(line.find("mass:") != std::string::npos){
            mass = parse_mass_line(line);
            continue;
        }

        if(line.find("volume:") != std::string::npos){
            dimensions = parse_volume_line(line);
            
            // We've finished parsing a cargo item
            cargoItems.push_back(std::make_unique<CargoItem>(id,mass,dimensions));
            continue;
        }

        // Otherwise it must be the id line
        id = parse_id_line(line);
    }

    return cargoItems;
}