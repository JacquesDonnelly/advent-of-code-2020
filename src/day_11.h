#ifndef DAY_11_H
#define DAY_11_H

#include <string>
#include <vector>
#include <iostream>

#include "day_2.h"

enum GridPoint {occupied, empty, floor};

class Grid{
  public:
    std::vector<std::vector<GridPoint>> positions;
    std::vector<GridPoint> get_surrounding_points(int x, int y);
    std::vector<GridPoint> sight_resolve(int x, int y);
    int step(int occupied_threshold, bool is_sight);
    int count_occupied();
    bool is_on_grid(std::pair<int, int> idx);
};

int day_11_part_1_main(std::string file_input, int occupied_threshold);
int day_11_part_2_main(std::string file_input, int occupied_threshold);
Grid load_grid(std::string file_input);

#endif
