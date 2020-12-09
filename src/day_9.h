#ifndef DAY_9_H
#define DAY_9_H

#include <string>
#include <vector>
#include <deque>
#include <fstream>
#include <iostream>

class Window{
  public:
    Window(std::vector<long long> numbers, int preamble_size);
    bool is_valid(long long value);
    void shift(long long value);
    std::deque<std::deque<long long>> possibles;
    std::deque<long long> values;
};

std::vector<long long> load_long_longs_from_file(std::string file_path);
std::pair<int, int> find_contiguous_sum(std::vector<long long> numbers, long long part_1);
long long day_9_part_1_main(std::string file_path, int preamble_size);
long long day_9_part_2_main(std::string file_path, long long part_1);
std::deque<std::deque<long long>> construct_possibles(std::vector<long long> numbers, int preamble_size);
std::deque<long long> construct_values(std::vector<long long> numbers, int preamble_size);

#endif
