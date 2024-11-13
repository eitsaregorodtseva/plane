#include "../units/plane.cpp"
#include "../units/plane.hpp"
#include <vector>
#include <assert.h>

int main() {
  std::vector<int> bus_vect = {10, 12, 20};
  std::vector<int> eco_vect = {10, 12};
  std::vector<int> first_vect = {30, 15, 200, 200};
  Plane plane;

  plane.setUnitCapacity("BUSINESS_CLASS_SEGMENT", 1000);
  plane.setUnitCapacity("ECONOMY_CLASS_SEGMENT", 20000);
  plane.setUnitCapacity("FIRST_CLASS_SEGMENT", 500);

  assert(plane.getUnit(UnitTypes::BUSINESS).getUnitCapacity() == 1000);
  assert(plane.getUnit(UnitTypes::ECONOMY).getUnitCapacity() == 20000);
  assert(plane.getUnit(UnitTypes::FIRST_CLASS).getUnitCapacity() == 500);

  plane.registerUnit(UnitTypes::BUSINESS, bus_vect);
  bus_vect.pop_back();
  plane.registerUnit(UnitTypes::BUSINESS, bus_vect);

  plane.registerUnit(UnitTypes::ECONOMY, eco_vect);
  plane.registerUnit(UnitTypes::FIRST_CLASS, first_vect);

  assert(plane.getHandWeightOfUnit(UnitTypes::BUSINESS) == 44);
  assert(plane.getWeightOfUnit(UnitTypes::BUSINESS) == 20);
  assert(plane.getTotalWeightOfUnit(UnitTypes::BUSINESS) == 64);

  assert(plane.getHandWeightOfUnit(UnitTypes::ECONOMY) == 10);
  assert(plane.getWeightOfUnit(UnitTypes::ECONOMY) == 12);
  assert(plane.getTotalWeightOfUnit(UnitTypes::ECONOMY) == 22);


  assert(plane.getHandWeightOfUnit(UnitTypes::FIRST_CLASS) == 45);
  assert(plane.getWeightOfUnit(UnitTypes::FIRST_CLASS) == 400);
  assert(plane.getTotalWeightOfUnit(UnitTypes::FIRST_CLASS) == 445);

  assert(plane.getTotalWeight() == 531);

  return 0;
}