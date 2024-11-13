#ifndef PASS_HPP
#define PASS_HPP

#include <vector>
#include "crew_members.hpp"

class Passengers : public CrewMembers {
public:
  std::vector<int> baggage;

  Passengers() {};
  ~Passengers() {};
  const std::vector<int>& getBaggage();
  void addBaggage(int baggage);
};

#endif