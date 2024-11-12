#include "units/plane.hpp"
#include "units/plane.cpp"
#include "units/unit.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>


int main() {
    Plane plane;
    std::string line;

    int i = 0;

    while (std::getline(std::cin, line) && line.size() > 0) {
        std::istringstream iss(line);
        std::string type;
        std::vector<int> luggage;
        int weight;

        iss >> type;

        if (i < 3) {
          iss >> weight;
          plane.setSegmentCapacity(type, weight);
        } else {
          if (i < 5) {
            plane.registerPilots();
          } else {
            if (i < 11) {
              plane.registerFlightAttendants();
            } else {
              while (iss >> weight) {
                luggage.push_back(weight);
              }
              plane.registerPassengers(type, luggage);
            }
          }
        }


        i++;
        // iss >> type;
        // while (iss >> weight) {
        //     if (handLuggage.size() < 2) 
        //         handLuggage.push_back(weight);
        //     else
        //         luggage.push_back(weight);
        // }

        // aircraft.registerUnit(type, handLuggage, luggage);
    }

    plane.report();

    return 0;
}
