#ifndef DAY_10_H
#define DAY_10_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

#include "day_1.h"

long long day_10_part_2_main(std::string file_input);
int day_10_part_1_main(std::string file_input);
std::vector<int> construct_diffs(std::vector<int> sorted_vector);
std::map<int, int> count_gaps(std::vector<int> values);

#endif
