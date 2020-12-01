#ifndef DAY_1_H
#define DAY_1_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int day_1_main(std::string file_path);
std::vector<int> load_integers_from_file(std::string file_path);
std::pair<int,int> find_integers_summing_to_2020(const std::vector<int> &numbers);

#endif
