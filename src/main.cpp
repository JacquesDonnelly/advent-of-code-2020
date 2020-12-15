#include <iostream>

#include "day_15.h"

int main(int argc, char **argv) {
  std::vector<int> starters = {0,1,4,13,15,12,16};
  int result = day_15_part_1_main(starters);
  std::cout << result << std::endl;
}
