#pragma once
#include <vector>
#include <memory>
#include "CargoItem.hpp"
unsigned int best_fit_decreasing(std::vector<std::unique_ptr<CargoItem>> & items);