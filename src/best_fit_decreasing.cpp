#include "best_fit_decreasing.hpp"
#include <algorithm>
#include <iostream>
#include <functional>
#include "Trolley.hpp"

unsigned int best_fit(std::vector<std::unique_ptr<CargoItem>> & items){
    // Maintain a list of trolleys
    std::vector<std::unique_ptr<Trolley>> trolleys;

    for(auto &item : items){
        // 1.a Find the trolley that is the most full already and can fit this item
        int bestIndex = 0;
        float leastSpaceRemaining = 1000000;

        for(int i = 0; i < trolleys.size(); i++){
            const float spaceRemaining = trolleys[i]->getSpaceRemaining();

            if(spaceRemaining < leastSpaceRemaining && spaceRemaining > item->getMass()){
                bestIndex = i;
                leastSpaceRemaining = spaceRemaining;
            }
        }

        // 1.b If no suitable trolleys were found, create a new one
        if(leastSpaceRemaining == 1000000){
            trolleys.push_back(std::make_unique<Trolley>());
            bestIndex = trolleys.size()-1;
        }

        // 2. Add the item to that trolley
        std::cout << "Adding to trolley " << std::to_string(bestIndex) << " with space remaining: " + std::to_string(trolleys[bestIndex]->getSpaceRemaining()) << " item of mass: " << std::to_string(item->getMass()) << std::endl;
        trolleys[bestIndex]->add(item.get());
        leastSpaceRemaining = trolleys[bestIndex]->getSpaceRemaining();
    }

    return trolleys.size();
}

unsigned int best_fit_decreasing(std::vector<std::unique_ptr<CargoItem>> & items){
    // Sort the items in decreasing order
    sort(items.begin( ), items.end( ), [ ]( const auto& lhs, const auto& rhs )
    {
        return lhs.get()->getMass() > rhs.get()->getMass();
    }); 

    // Then run best fit
    return best_fit(items);
}