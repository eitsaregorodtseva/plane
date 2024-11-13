#include "passengers.hpp"

Passengers::Passengers(const std::vector<int>& baggage) {
    this->baggage = baggage;
}

const std::vector<int>& Passengers::getBaggage() {
    return this->baggage;
}