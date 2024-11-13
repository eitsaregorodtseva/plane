#include "crew_members.hpp"

void CrewMembers::setCapacity(int capacity) {
    this->capacity = capacity;
};

void CrewMembers::incrementCount() {
    this->count++;
};

void CrewMembers::setMaxWeight(int weight) {
    this->maxWeight = weight;
};

void CrewMembers::setMaxItems(int items) {
    this->maxItems = items;;
};

void CrewMembers::setMaxHandWeight(int weight) {
    this->maxHandWeight = weight;
};

void CrewMembers::setMaxHandItems(int items) {
    this->maxHandItems = items;
};

void CrewMembers::setCurrHandWeight(int weight) {
    this->currHandWeight = weight;
};

void CrewMembers::setCurrWeight(int weight) {
    this->currWeight = weight;
};

int CrewMembers::getCurrHandWeight() {
    return this->currHandWeight;
};

int CrewMembers::getCurrWeight() {
    return this->currWeight;
};

int CrewMembers::getCapacity() {
    return this->capacity;
};

int CrewMembers::getCount() {
    return this->count;
};

int CrewMembers::getMaxHandItems() {
    return this->maxHandItems;
};

int CrewMembers::getMaxItems() {
    return this->maxItems;
};

int CrewMembers::getMaxHandWeight() {
    return this->maxHandWeight;
};

int CrewMembers::getMaxWeight() {
    return this->maxWeight;
};