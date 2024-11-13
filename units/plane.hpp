#ifndef PLANE_HPP
#define PLANE_HPP

#include "unit.hpp"
#include "crew_members.hpp"
#include <vector>
#include <string>
#include <map>

enum UnitTypes { 
    FIRST_CLASS, 
    BUSINESS, 
    ECONOMY,
    PILOT,
    FLIGHT_ATTENDANT
};

static std::map<UnitTypes, std::string> UnitToString = { 
    { FIRST_CLASS, "FIRST_CLASS" },
    { BUSINESS, "BUSINESS" },
    { ECONOMY, "ECONOMY" },
    { PILOT, "PILOT" }, 
    { FLIGHT_ATTENDANT, "FLIGHT_ATTENDANT" }, 
};
class Plane {
  public:
    Plane() {};
    ~Plane() {};

    void setUnitCapacity(const std::string& type, const int maxWeight);
    void registerUnit(const UnitTypes& type, const std::vector<int> allBaggage);

    Unit getUnit(const UnitTypes& type);
    int getTotalWeight();
    int getHandWeightOfUnit(const UnitTypes& type);
    int getWeightOfUnit(const UnitTypes& type);
    int getTotalWeightOfUnit(const UnitTypes& type);

    // void report();a

    private:
        std::map<UnitTypes, Unit> planeUnit = {
            {FIRST_CLASS, Unit(1, 4, 2, 60, 2, 100000000)}, 
            {BUSINESS, Unit(2, 10, 2, 24, 2, 40)}, 
            {ECONOMY, Unit(3, 200, 1, 10, 1, 24)}, 
            {PILOT, Unit(4, 2, 0, 0, 0, 0)}, 
            {FLIGHT_ATTENDANT, Unit(5, 6, 0, 0, 0, 0)},
        };
};

#endif