#pragma once
#include "CargoItem.hpp"
#include <string>
#include <memory>

std::vector<std::unique_ptr<CargoItem>> parse_cargo_file(std::string filePath);