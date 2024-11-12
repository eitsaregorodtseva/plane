#ifndef PLANE_HPP
#define PLANE_HPP

#include "passengers.hpp"
#include "passengers.cpp"
#include "unit.hpp"
#include "crew_members.hpp"
#include "crew_members.cpp"
#include <vector>
#include <string>

class Plane: public Unit {
  public:
    enum UnitTypes {
        PILOT,
        FLIGHT_ATTENDANT,
        FIRST_CLASS,
        BUSINESS,
        ECONOMY
    };

    static const std::vector< std::string > ACCESS_MODIFIERS;
    Plane() {
        this->pilot.capacity = 2;
        this->flightAtt.capacity = 6;
        this->first.capacity = 4;
        this->business.capacity = 10;
        this->economy.capacity = 200;

        this->first.maxHandWeight = 60;
        this->business.maxHandWeight = 24;
        this->economy.maxHandWeight = 10;

        this->first.maxHandItems = 2;
        this->business.maxHandItems = 2;
        this->economy.maxHandItems = 1;

        this->first.maxItems = 2;
        this->business.maxItems = 2;
        this->economy.maxItems = 1;

        this->first.maxWeight = 100000000;
        this->business.maxWeight = 40;
        this->economy.maxWeight = 24;

        this->pilot.id = 1;
        this->flightAtt.id = 2;
        this->first.id = 3;
        this->business.id = 4;
        this->economy.id = 5;
    };
    ~Plane() {};
    void setSegmentCapacity(const std::string& type, const int maxWeight);
    void registerPassengers(const std::string& type, const std::vector<int> luggage);
    void registerPilots();
    void registerFlightAttendants();
    void report() const;

    private:
        CrewMember pilot;
        CrewMember flightAtt;

        Passenger first;
        Passenger business;
        Passenger economy;
};

#endif