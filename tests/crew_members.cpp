#include "../units/crew_members.hpp"
#include "../units/crew_members.cpp"
#include <assert.h>

int main() {
  CrewMembers crew_mems;
  crew_mems.setCapacity(1);

  crew_mems.setMaxWeight(2);
  crew_mems.setMaxItems(3);

  crew_mems.setMaxHandWeight(4);
  crew_mems.setMaxHandItems(5);

  crew_mems.setCurrHandWeight(6);
  crew_mems.setCurrWeight(7);

  crew_mems.incrementCount();
  crew_mems.incrementCount();

  assert(crew_mems.getCapacity() == 1);
  assert(crew_mems.getCount() == 2);

  assert(crew_mems.getMaxWeight() == 2);
  assert(crew_mems.getMaxItems() == 3);

  assert(crew_mems.getMaxHandWeight() == 4);
  assert(crew_mems.getMaxHandItems() == 5);

  assert(crew_mems.getCurrHandWeight() == 6);
  assert(crew_mems.getCurrWeight() == 7);

  return 0;
}