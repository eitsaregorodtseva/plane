#ifndef UNIT_HPP
#define UNIT_HPP

class Unit {
protected:
public:
    int id;
    int count = 0;
    int capacity = 0;

    int maxWeight = 0;
    int maxItems = 0;

    int maxHandWeight = 0;
    int maxHandItems = 0;

    int currHandWeight = 0;
    int currWeight = 0;

    Unit() {};
    ~Unit() {};

    int getHandWeight() { return this->currHandWeight; }
    int getWeight() { return this->currWeight; }

    virtual void registerUnit() {};
};

#endif