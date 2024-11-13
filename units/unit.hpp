#ifndef UNIT_HPP
#define UNIT_HPP

#include "crew_members.hpp"
#include "passengers.hpp"
#include "plane.hpp"
#include <iostream>

class Unit {
private: 
    int id = 0;
    int handWeight = 0; 
    int weight = 0; 
    int weightCapacity = 0;

public:
    Passengers passengers;

    Unit() {};
    Unit(int id, int capacity, int maxHandItems, int maxHandWeight, int maxItems, int maxWeight) {
        this->setId(id);
        this->passengers.capacity = capacity;
        this->passengers.maxHandItems = maxHandItems;
        this->passengers.maxHandWeight = maxHandWeight;
        this->passengers.maxItems = maxItems;
        this->passengers.maxWeight = maxWeight;
    };
    ~Unit() {};

    int getId() {
        return this->id;
    };
    int setId(int id) {
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
        std::cout << weight << " removed " << std::endl; 
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
       this->passengers.count++; 
    }

    void addBaggage(int baggage) {
       this->passengers.baggage.push_back(baggage); 
    };


    virtual void registerUnit() {};
};

#endif