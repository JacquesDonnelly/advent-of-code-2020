#include <iostream>

#include "day_1.h"

int main(int argc, char **argv) {
  int part_one_result = day_1_part_1_main("/code/day_1_input.txt");
  int part_two_result = day_1_part_2_main("/code/day_1_input.txt");
  std::cout << part_one_result << std::endl;
  std::cout << part_two_result << std::endl;
}
