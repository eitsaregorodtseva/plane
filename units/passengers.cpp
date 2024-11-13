#include "passengers.hpp"
#include <algorithm>

void Passengers::addBaggage(int baggage) {
    this->baggage.push_back(baggage);
}

const std::vector<int>& Passengers::getBaggage() {
    return this->baggage;
}

void Passengers::removeLastBaggage() {
    this->baggage.pop_back();
}

void Passengers::sortBaggage() {
    std::sort(this->baggage.begin(), this->baggage.end());
}