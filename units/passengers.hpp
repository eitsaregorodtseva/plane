#ifndef PASS_HPP
#define PASS_HPP

#include <vector>
#include "crew_members.hpp"

class Passengers : public CrewMembers {
private:
  std::vector<int> baggage;

public:
  Passengers() {};
  ~Passengers() {};

  const std::vector<int>& getBaggage();
  void addBaggage(int baggage);
  void removeLastBaggage();
  void sortBaggage();
};

#endif