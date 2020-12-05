#ifndef DAY_4_H
#define DAY_4_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <set>
#include <regex>

int day_4_part_1_main(std::string file_path);
int day_4_part_2_main(std::string file_path);
bool is_key_value_valid(std::string key_value);
std::string read_file_to_string(std::string file_path);
std::vector<std::string> split_string_by_delimiter(std::string str, std::string delimiter);
std::vector<std::vector<std::string>> vectorize_pairs(std::string input_string);
std::vector<std::string> get_key_value_vector(std::string passport);
bool passport_is_valid(std::vector<std::string> passport);

bool is_valid_byr(std::string value);
bool is_valid_hgt(std::string value);
bool is_valid_hcl(std::string value);
bool is_valid_ecl(std::string value);
bool is_valid_pid(std::string value);
bool is_valid_eyr(std::string value);
bool is_valid_iyr(std::string value);

#endif
