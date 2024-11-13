#include "units/plane.hpp"
#include "units/plane.cpp"

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
      std::vector<int> baggage;
      int weight;

      iss >> type;

      if (i < 3) {
        iss >> weight;
        plane.setUnitCapacity(type, weight);
      } else {
        while (iss >> weight) {
          baggage.push_back(weight);
        }

        for (auto i : UnitToString) {
          if (i.second == type) {
            plane.registerUnit(i.first, baggage);
          }
        }
      }

      i++;
    }

    // plane.report();
    return 0;
}
