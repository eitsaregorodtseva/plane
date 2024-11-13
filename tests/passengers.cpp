#include "../units/passengers.hpp"
#include "../units/passengers.cpp"
#include "../units/crew_members.hpp"
#include "../units/crew_members.cpp"
#include <assert.h>
#include <vector>

int main() {
  std::vector<int> vect = {10, 20};

  Passengers passengers;
  passengers.setCapacity(1);

  passengers.setMaxWeight(2);
  passengers.setMaxItems(3);

  passengers.setMaxHandWeight(4);
  passengers.setMaxHandItems(5);

  passengers.setCurrHandWeight(6);
  passengers.setCurrWeight(7);

  passengers.incrementCount();
  passengers.incrementCount();

  assert(passengers.getCapacity() == 1);
  assert(passengers.getCount() == 2);

  assert(passengers.getMaxWeight() == 2);
  assert(passengers.getMaxItems() == 3);

  assert(passengers.getMaxHandWeight() == 4);
  assert(passengers.getMaxHandItems() == 5);

  assert(passengers.getCurrHandWeight() == 6);
  assert(passengers.getCurrWeight() == 7);

  passengers.addBaggage(10);
  passengers.addBaggage(30);
  passengers.addBaggage(20);

  passengers.sortBaggage();
  passengers.removeLastBaggage();

  assert(passengers.getBaggage() == vect);

  return 0;
}