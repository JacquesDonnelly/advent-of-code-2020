#include <iostream>

#include "day_3.h"

int main(int argc, char **argv) {
  int result_1 = day_3_part_2_main("/code/day_3_input.txt", 1, 1);
  int result_2 = day_3_part_2_main("/code/day_3_input.txt", 3, 1);
  int result_3 = day_3_part_2_main("/code/day_3_input.txt", 5, 1);
  int result_4 = day_3_part_2_main("/code/day_3_input.txt", 7, 1);
  int result_5 = day_3_part_2_main("/code/day_3_input.txt", 1, 2);
  long long result = static_cast<long long>(result_1)
	           * static_cast<long long>(result_2)
	           * static_cast<long long>(result_3)
	           * static_cast<long long>(result_4)
	           * static_cast<long long>(result_5);
  std::cout << result << std::endl;
}
