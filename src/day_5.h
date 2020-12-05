#ifndef DAY_5_H
#define DAY_5_H

#include <string>
#include <iostream>
#include <cmath>

struct Seat {
  int row;
  int column;
};

int day_5_part_2_main(std::string file_path);
int day_5_part_1_main(std::string file_path);
int find_min_id(std::string file_path);
Seat resolve_seat(std::string partitioning);
int resolve_partition(std::string row_partition);
int calculate_id(std::string partition);
int sum_all_ids(std::string file_path);

#endif
