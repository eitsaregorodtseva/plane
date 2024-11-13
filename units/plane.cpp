#include "plane.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>


int Plane::getHandWeightFromUnit(const UnitTypes &type)
{
  return this->planeUnit[type].getHandWeight();
};

int Plane::getWeightFromUnit(const UnitTypes &type)
{
  return this->planeUnit[type].getWeight();
};

int Plane::getTotalWeightFromUnit(const UnitTypes &type)
{
  return this->planeUnit[type].getWeight() + this->planeUnit[type].getHandWeight();
};

int Plane::getTotalWeight()
{
  return this->getTotalWeightFromUnit(FIRST_CLASS) + this->getTotalWeightFromUnit(BUSINESS) + this->getTotalWeightFromUnit(ECONOMY);
}

void Plane::setUnitCapacity(const std::string &type, const int maxWeight)
{
  if (type == "FIRST_CLASS_SEGMENT")
  {
    this->planeUnit[FIRST_CLASS].setUnitCapacity(maxWeight);
  }

  if (type == "BUSINESS_CLASS_SEGMENT")
  {
    this->planeUnit[BUSINESS].setUnitCapacity(maxWeight);
  }

  if (type == "ECONOMY_CLASS_SEGMENT")
  {
    this->planeUnit[ECONOMY].setUnitCapacity(maxWeight);
  }
}

void Plane::registerUnit(const UnitTypes &type, const std::vector<int> luggage)
{
  int handWeight = 0;
  int weight = 0;
  std::vector<int> baggage;
  std::vector<int> noFitBaggage;

  if (this->planeUnit[type].passengers.count < this->planeUnit[type].passengers.capacity)
  {
    for (int i = 0; i < luggage.size(); i++)
    {
      if (i <= this->planeUnit[type].passengers.maxHandItems - 1)
      {
        handWeight += luggage[i];
      }
      else
      {
        weight += luggage[i];
        baggage.push_back(luggage[i]);
      }
    }

    int currentWeight = this->getTotalWeightFromUnit(type);

    if (handWeight <= this->planeUnit[type].passengers.maxHandWeight && weight <= this->planeUnit[type].passengers.maxWeight && (currentWeight + handWeight) <= this->planeUnit[type].getUnitCapacity())
    {
      this->planeUnit[type].addPassanger();
      this->planeUnit[type].addHandWeight(handWeight);

      for (int i = 0; i < baggage.size(); i++)
      {
        currentWeight = this->getTotalWeightFromUnit(type);
        if (baggage[i] + currentWeight > this->planeUnit[type].getUnitCapacity())
        {
          noFitBaggage.push_back(baggage[i]);
        }
        else
        {
          this->planeUnit[type].addWeight(baggage[i]);
          this->planeUnit[type].addBaggage(baggage[i]);
        }
      }
      
      if (noFitBaggage.size() != 0)
      {
        if (type == UnitTypes::ECONOMY) {
          this->planeUnit[type].baggageError();
        } else {
          size_t size = noFitBaggage.size();

          while (size != 0) {
            std::sort(this->planeUnit[ECONOMY].passengers.baggage.begin(), this->planeUnit[ECONOMY].passengers.baggage.end());
            this->planeUnit[ECONOMY].removeWeight(this->planeUnit[ECONOMY].passengers.baggage.back());
            this->planeUnit[ECONOMY].passengers.baggage.pop_back();
            
            for (int i = 0; i < size; i++) {
              if (this->getTotalWeightFromUnit(UnitTypes::ECONOMY) + noFitBaggage[i] <= this->planeUnit[ECONOMY].getUnitCapacity()) {
                this->planeUnit[ECONOMY].addWeight(noFitBaggage[i]);
                this->planeUnit[ECONOMY].addBaggage(noFitBaggage[i]);
                noFitBaggage.erase(noFitBaggage.begin() + i);
                size--;
              }
            }
          }
        }
      }
    } 
    else 
    {
      this->planeUnit[type].registerError(UnitToString[type]);
    }
  }
  else
  {
    this->planeUnit[type].registerError(UnitToString[type]);
  }
}

  void Plane::report()
  {
    std::cout << "First Class max: " << this->planeUnit[FIRST_CLASS].passengers.maxWeight
              << " getId() " << this->planeUnit[FIRST_CLASS].getId() << std::endl;
    std::cout << "Business Class max: " << this->planeUnit[BUSINESS].passengers.maxWeight
              << " getId() " << this->planeUnit[BUSINESS].getId() << std::endl;
    std::cout << "Economy Class max: " << this->planeUnit[ECONOMY].passengers.maxWeight
              << " getId() " << this->planeUnit[ECONOMY].getId() << std::endl;

    std::cout << "Pilots: " << this->planeUnit[PILOT].passengers.capacity
              << " count " << this->planeUnit[PILOT].passengers.count << std::endl;
    std::cout << "Atts: " << this->planeUnit[FLIGHT_ATTENDANT].passengers.capacity
              << " count" << this->planeUnit[FLIGHT_ATTENDANT].passengers.count << std::endl;

    std::cout << "Business Class: " << this->planeUnit[BUSINESS].passengers.capacity
              << " count " << this->planeUnit[BUSINESS].passengers.count << std::endl;
    std::cout << "Economy Class: " << this->planeUnit[ECONOMY].passengers.capacity
              << " count " << this->planeUnit[ECONOMY].passengers.count << std::endl;
    std::cout << "First Class: " << this->planeUnit[FIRST_CLASS].passengers.capacity
              << " count " << this->planeUnit[FIRST_CLASS].passengers.count << std::endl;

    std::cout << "Business Class: " << this->planeUnit[BUSINESS].getWeight()
              << " count " << this->planeUnit[BUSINESS].passengers.count << std::endl;
    std::cout << "Economy Class: " << this->planeUnit[ECONOMY].passengers.capacity
              << " count " << this->planeUnit[ECONOMY].passengers.count << std::endl;
    std::cout << "First Class: " << this->planeUnit[FIRST_CLASS].passengers.capacity
              << " count " << this->planeUnit[FIRST_CLASS].passengers.count << std::endl;
  }
