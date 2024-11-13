#include "plane.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

Unit Plane::getUnit(const UnitTypes &type)
{
  return this->planeUnit[type];
};

int Plane::getHandWeightOfUnit(const UnitTypes &type)
{
  return this->planeUnit[type].getHandWeight();
};

int Plane::getWeightOfUnit(const UnitTypes &type)
{
  return this->planeUnit[type].getWeight();
};

int Plane::getTotalWeightOfUnit(const UnitTypes &type)
{
  return this->planeUnit[type].getWeight() + this->planeUnit[type].getHandWeight();
};

int Plane::getTotalWeight()
{
  return this->getTotalWeightOfUnit(FIRST_CLASS) + this->getTotalWeightOfUnit(BUSINESS) + this->getTotalWeightOfUnit(ECONOMY);
};

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
};

void Plane::registerUnit(const UnitTypes &type, const std::vector<int> allBaggage)
{
  int handWeight = 0;
  int weight = 0;
  std::vector<int> baggage;
  std::vector<int> outOfBaggage;

  for (int i = 0; i < allBaggage.size(); i++)
  {
    if (i < this->planeUnit[type].getPassengers().getMaxHandItems())
    {
      handWeight += allBaggage[i];
    }
    else
    {
      weight += allBaggage[i];
      baggage.push_back(allBaggage[i]);
    }
  }

  int currentWeight = this->getTotalWeightOfUnit(type);

  //проверяем:
  //1. есть ли место под пассажира
  //2. есть ли место для ручной клади
  //3. не прывысил ли пассажир ограничения по своему классу (ручная кладь и багаж отдельно, только вес, без количества)
  //иначе: не можем посадить
  if (this->planeUnit[type].getPassengers().getCount() < this->planeUnit[type].getPassengers().getCapacity() &&
      (currentWeight + handWeight) <= this->planeUnit[type].getUnitCapacity() &&
      handWeight <= this->planeUnit[type].getPassengers().getMaxHandWeight() &&
      weight <= this->planeUnit[type].getPassengers().getMaxWeight()
      )
  {

    //сажаем пассажира и суммируем его ручную кладь
    //дальше проверяем, укладывается ли багаж(поштучно) в сегмент
    //если да, то суммируем с багажом и добавляем в вектор багажей
    //если нет, добавляем в вектор непоместившихся багажей outOfBaggage
    this->planeUnit[type].addPassanger();
    this->planeUnit[type].addHandWeight(handWeight);

    for (int i = 0; i < baggage.size(); i++)
    {
      currentWeight = this->getTotalWeightOfUnit(type);
      if ((baggage[i] + currentWeight) > this->planeUnit[type].getUnitCapacity())
      {
        outOfBaggage.push_back(baggage[i]);
      }
      else
      {
        this->planeUnit[type].addWeight(baggage[i]);
        this->planeUnit[type].addBaggage(baggage[i]);
      }
    }

    if (outOfBaggage.size() != 0)
    {
      if (type == UnitTypes::ECONOMY)
      {
        //по условию: если не влез эконом - снимаем багаж
        this->planeUnit[type].baggageError();
      }
      else
      {
        size_t size = outOfBaggage.size();

        //пока в outOfBaggage есть элементы проверяем:
        //сортируем вектор багажей, чтобы снимать самый тяжелый
        //снимаем, выдаем уведомление
        //
        //
        //
        while (size != 0)
        {
          this->planeUnit[ECONOMY].getPassengers().sortBaggage();
          std::vector<int> currBaggage = this->planeUnit[ECONOMY].getPassengers().getBaggage();

          this->planeUnit[ECONOMY].removeWeight(this->planeUnit[ECONOMY].getPassengers().getBaggage().back());
          this->planeUnit[ECONOMY].getPassengers().removeLastBaggage();
          this->planeUnit[ECONOMY].baggageError();

          int count = size;
          int i = 0;

          while (i < count) {
            if (this->getTotalWeightOfUnit(UnitTypes::ECONOMY) + outOfBaggage[i] <= this->planeUnit[ECONOMY].getUnitCapacity())
            {
              this->planeUnit[ECONOMY].addWeight(outOfBaggage[i]);
              this->planeUnit[ECONOMY].addBaggage(outOfBaggage[i]);
              outOfBaggage.erase(outOfBaggage.begin() + i);
              size--;
              count--;
            }
            i++;
          };

          // for (int i = 0; i < count; i++)
          // {
          //   if (this->getTotalWeightOfUnit(UnitTypes::ECONOMY) + outOfBaggage[i] <= this->planeUnit[ECONOMY].getUnitCapacity())
          //   {
          //     this->planeUnit[ECONOMY].addWeight(outOfBaggage[i]);
          //     this->planeUnit[ECONOMY].addBaggage(outOfBaggage[i]);
          //     outOfBaggage.erase(outOfBaggage.begin() + i);
          //     size--;
          //   }
          // }
        }
      }
    }
  }
  else
  {
    this->planeUnit[type].registerError(UnitToString[type]);
  }
}
;

// void Plane::report()
// {
//   std::cout << "First Class max: " << this->planeUnit[FIRST_CLASS].getPassengers().getMaxWeight()
//             << " getId() " << this->planeUnit[FIRST_CLASS].getId() << std::endl;
//   std::cout << "Business Class max: " << this->planeUnit[BUSINESS].getPassengers().getMaxWeight()
//             << " getId() " << this->planeUnit[BUSINESS].getId() << std::endl;
//   std::cout << "Economy Class max: " << this->planeUnit[ECONOMY].getPassengers().getMaxWeight()
//             << " getId() " << this->planeUnit[ECONOMY].getId() << std::endl;

//   std::cout << "Pilots: " << this->planeUnit[PILOT].getPassengers().getCapacity()
//             << " count " << this->planeUnit[PILOT].getPassengers().getCount() << std::endl;
//   std::cout << "Atts: " << this->planeUnit[FLIGHT_ATTENDANT].getPassengers().getCapacity()
//             << " count" << this->planeUnit[FLIGHT_ATTENDANT].getPassengers().getCount() << std::endl;

//   std::cout << "Business Class: " << this->planeUnit[BUSINESS].getPassengers().getCapacity()
//             << " count " << this->planeUnit[BUSINESS].getPassengers().getCount() << std::endl;
//   std::cout << "Economy Class: " << this->planeUnit[ECONOMY].getPassengers().getCapacity()
//             << " count " << this->planeUnit[ECONOMY].getPassengers().getCount() << std::endl;
//   std::cout << "First Class: " << this->planeUnit[FIRST_CLASS].getPassengers().getCapacity()
//             << " count " << this->planeUnit[FIRST_CLASS].getPassengers().getCount() << std::endl;

//   std::cout << "Business Class: " << this->planeUnit[BUSINESS].getWeight()
//             << " count " << this->planeUnit[BUSINESS].getPassengers().getCount() << std::endl;
//   std::cout << "Economy Class: " << this->planeUnit[ECONOMY].getPassengers().getCapacity()
//             << " count " << this->planeUnit[ECONOMY].getPassengers().getCount() << std::endl;
//   std::cout << "First Class: " << this->planeUnit[FIRST_CLASS].getPassengers().getCapacity()
//             << " count " << this->planeUnit[FIRST_CLASS].getPassengers().getCount() << std::endl;
// }
