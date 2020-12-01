#ifndef DAY_1_H
#define DAY_1_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int day_1_part_1_main(std::string file_path);
int day_1_part_2_main(std::string file_path);
std::vector<int> load_integers_from_file(std::string file_path);
std::pair<int,int> find_two_ints_summing_to_2020(const std::vector<int> &numbers);
std::vector<int> find_three_ints_summing_to_2020(const std::vector<int> &numbers);

#endif
