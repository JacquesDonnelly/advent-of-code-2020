#ifndef DAY_12_H
#define DAY_12_H

#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <cstdlib>

#include "day_2.h"

enum Action {
  north,
  south,
  east,
  west,
  left,
  right,
  forward
};

struct Instruction {
  Action action;
  int magnitude;
};

class Ship {
  public:
    int x;
    int y;
    int angle; // Measured positive clockwise. 0 is east.
    void execute_instruction(Instruction instruction);
    int manhattan_distance();
};

int day_12_part_1_main(std::string file_path);
std::vector<Instruction> load_instructions(std::string file_path);
Instruction parse_string_instruction(std::string string_instruction);

#endif
