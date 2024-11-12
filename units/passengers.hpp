#ifndef PASS_HPP
#define PASS_HPP

#include "unit.hpp"
#include <vector>

class Passenger : public Unit {
private:
  int addWeight = 0;
  int addItems = 0;

  std::vector<int> handLuggage;
  std::vector<int> luggage;

public:

  Passenger() {};
  Passenger(const std::vector<int>& handLuggage, const std::vector<int>& luggage);
  const std::vector<int>& getHandLuggage() const;
  const std::vector<int>& getLuggage() const;
  int totalHandLuggageWeight() const;
  int totalLuggageWeight() const;
};

#endif