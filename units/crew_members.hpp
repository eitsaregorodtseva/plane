#ifndef CREW_HPP
#define CREW_HPP

class CrewMembers {
public:
    CrewMembers() {};
    ~CrewMembers() {};

    int getHandWeight();
    int getWeight();

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