#ifndef UNIT_HPP
#define UNIT_HPP

#include "crew_members.hpp"
#include "crew_members.cpp"
#include "passengers.hpp"
#include "passengers.cpp"
#include "plane.hpp"
#include <iostream>

class Unit {
private: 
    int id = 0;
    int handWeight = 0; 
    int weight = 0; 
    int weightCapacity = 0;
    Passengers passengers;

public:
    Unit() {};
    Unit(int id, int capacity, int maxHandItems, int maxHandWeight, int maxItems, int maxWeight) {
        this->setId(id);
        this->passengers.setCapacity(capacity);
        this->passengers.setMaxHandItems(maxHandItems);
        this->passengers.setMaxHandWeight(maxHandWeight);
        this->passengers.setMaxItems(maxItems);
        this->passengers.setMaxWeight(maxWeight);
    };
    ~Unit() {};

    Passengers& getPassengers() {
        return this->passengers;
    };

    int getId() {
        return this->id;
    };
    void setId(int id) {
        this->id = id;
    };
    void setUnitCapacity(const int& weight) {
        this->weightCapacity = weight;
    };
    int getHandWeight() {
        return this->handWeight;
    };
    void addHandWeight(int handWeight) {
        this->handWeight += handWeight;
    };
    int getWeight() {
        return this->weight;
    };
    void addWeight(int weight) {
        this->weight += weight;
    };
    void removeWeight(int weight) {
        this->weight -= weight;
    };
    int getUnitCapacity() {
        return this->weightCapacity;
    };

    void registerError(const std::string &type) {
        std::cout << "!!CANT REGISTER " << type << " PASSENGER, ID = " << this->getId() << "!!" << std::endl;
    };
    
    void baggageError() {
        std::cout << "!!PASSENGER’S LUGGAGE REMOVED FROM FLIGHT, ID = " << this->getId() << "!!" << std::endl;
    };

    void addPassanger() {
       this->passengers.incrementCount(); 
    }

    void addBaggage(int baggage) {
       this->passengers.addBaggage(baggage); 
    };


    virtual void registerUnit() {};
};

#endif