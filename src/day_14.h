#ifndef DAY_14_H
#define DAY_14_H

#include <string>
#include <iostream>
#include <bitset>

#include "day_2.h"

int day_14_part_1_main(std::string file_path);
void apply_mask(std::bitset<36> *bits, std::string mask);

class ComputerSystem{
  public:
    void process(std::string line);
    long sum_all_addresses();
    void update_mask();
  private:
    std::map<long, long> memory;
    std::string mask;
};

#endif
