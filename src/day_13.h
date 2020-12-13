#ifndef DAY_13_H
#define DAY_13_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>

#include "day_2.h"
#include "day_4.h"

int day_13_part_1_main(std::string file_input);

struct Bus{
  int id;
};

struct BusNotes{
  int earliest;
  std::vector<Bus> busses;
};

BusNotes read_bus_notes(std::string file_input);

#endif
