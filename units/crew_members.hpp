#ifndef CREW_HPP
#define CREW_HPP

class CrewMembers {
public:
    CrewMembers() {};
    ~CrewMembers() {};

    void setCapacity(int capacity);
    void incrementCount();

    void setMaxWeight(int weight);
    void setMaxItems(int items);

    void setMaxHandWeight(int weight);
    void setMaxHandItems(int items);

    void setCurrHandWeight(int weight);
    void setCurrWeight(int weight);

    int getCurrHandWeight();
    int getCurrWeight();

    int getCapacity();
    int getCount();

    int getMaxHandItems();
    int getMaxItems();
    int getMaxWeight();
    int getMaxHandWeight();

private:
    int capacity = 0;
    int count = 0;

    int maxWeight = 0;
    int maxItems = 0;

    int maxHandWeight = 0;
    int maxHandItems = 0;

    int currHandWeight = 0;
    int currWeight = 0;
};

#endif