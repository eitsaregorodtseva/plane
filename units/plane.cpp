#include "plane.hpp"
#include "unit.hpp"
#include <iostream>
#include <sstream>

void Plane::registerFlightAttendants()
{
  if (this->flightAtt.count == this->flightAtt.capacity)
  {
    std::cout << "!!CANT REGISTER " << "FLIGHT_ATTENDANT" << " PASSENGER, ID = " << this->flightAtt.id << "!!" << std::endl;
  }
  else
  {
    this->flightAtt.count++;
  }
}

void Plane::registerPilots()
{
  if (this->pilot.count == this->pilot.capacity)
  {
    std::cout << "!!CANT REGISTER " << "PILOT" << " PASSENGER, ID = " << this->pilot.id << "!!" << std::endl;
  }
  else
  {
    this->pilot.count++;
  }
}

void Plane::setSegmentCapacity(const std::string &type, const int maxWeight)
{
  if (type == "FIRST_CLASS_SEGMENT")
  {
    this->first.maxWeight = maxWeight;
  }

  if (type == "BUSINESS_CLASS_SEGMENT")
  {
    this->business.maxWeight = maxWeight;
  }

  if (type == "ECONOMY_CLASS_SEGMENT")
  {
    this->economy.maxWeight = maxWeight;
  }
}

void Plane::registerPassengers(const std::string &type, const std::vector<int> luggage)
{
  std::cout << type << std::endl;
  if (type == "FIRST_CLASS")
  {
    if (this->first.count == this->first.capacity)
    {
      std::cout << "!!CANT REGISTER " << type << " PASSENGER, ID = " << this->first.id << "!!" << std::endl;
    }
    else
    {
      this->first.count++;
      for (int i : luggage)
    }
  }

  if (type == "BUSINESS")
  {
    if (this->business.count == this->business.capacity)
    {
      std::cout << "!!CANT REGISTER " << type << " PASSENGER, ID = " << this->business.id << "!!" << std::endl;
    }
    else
    {
      this->business.count++;
    }
  }

  if (type == "ECONOMY")
  {
    if (this->economy.count == this->economy.capacity)
    {
      std::cout << "!!CANT REGISTER " << type << " PASSENGER, ID = " << this->economy.id << "!!" << std::endl;
    }
    else
    {
      this->economy.count++;
    }
  }
}

void Aircraft::registerUnit(const std::string &type, const std::vector<int> &handLuggage, const std::vector<int> &luggage)
{
  Passenger passenger(handLuggage, luggage);
  AircraftSegment *segment = nullptr;

  if (type == "FIRST_CLASS")
  {
    segment = &firstClassSegment;
  }
  else if (type == "BUSINESS")
  {
    segment = &businessClassSegment;
  }
  else if (type == "ECONOMY")
  {
    segment = &economyClassSegment;
  }

  if (segment && segment->canAddPassenger(passenger))
  {
    segment->addPassenger(passenger);
  }
  else if (segment)
  {
    std::cout << "!!CANT REGISTER " << type << " PASSENGER, ID = " << "!!" << std::endl;
  }
}

void Plane::report() const
{
  std::cout << "First Class max: " << this->first.maxWeight
            << " id " << this->first.id << std::endl;
  std::cout << "Business Class max: " << this->business.maxWeight
            << " id " << this->business.id << std::endl;
  std::cout << "Economy Class max: " << this->economy.maxWeight
            << " id " << this->economy.id << std::endl;

  std::cout << "Pilots: " << this->pilot.capacity
            << " count " << this->pilot.count << std::endl;
  std::cout << "Atts: " << this->flightAtt.capacity
            << " count" << this->flightAtt.count << std::endl;

  std::cout << "Business Class: " << this->business.capacity
            << " count " << this->business.count << std::endl;
  std::cout << "Economy Class: " << this->economy.capacity 
            << " count " << this->economy.count << std::endl;
  std::cout << "First Class: " << this->first.capacity
            << " count " << this->first.count << std::endl;
}
