#include "passengers.hpp"
#include "unit.hpp"

Passenger::Passenger(const std::vector<int>& handLuggage, const std::vector<int>& luggage)
{
  this->handLuggage = handLuggage;
  this->luggage = luggage;
}
// : handLuggage(handLuggage), luggage(luggage) {}

const std::vector<int>& Passenger::getHandLuggage() const {
    return handLuggage;
}

const std::vector<int>& Passenger::getLuggage() const {
    return luggage;
}

int Passenger::totalHandLuggageWeight() const {
    int total = 0;
    for (int weight : handLuggage) total += weight;
    return total;
}

int Passenger::totalLuggageWeight() const {
    int total = 0;
    for (int weight : luggage) total += weight;
    return total;
}