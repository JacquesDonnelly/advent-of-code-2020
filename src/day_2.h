#ifndef DAY_2_H
#define DAY_2_H

#include <string>
#include <regex>
#include <iostream>
#include <fstream>

struct Policy {
  int minimum;
  int maximum;
  char letter;
};

class Password {
  public:
    std::string text;
    Policy policy;
    Password(std::string text, Policy policy);
    int letter_count();
    bool is_valid();
};

Password extract_password_from_string(std::string input_string);
std::vector<std::string> load_strings_from_file(std::string file_path);
int day_2_main(std::string file_path);

#endif
