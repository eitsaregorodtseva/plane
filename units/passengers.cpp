#include "passengers.hpp"

void Passengers::addBaggage(int baggage) {
    this->baggage.push_back(baggage);
}

const std::vector<int>& Passengers::getBaggage() {
    return this->baggage;
}