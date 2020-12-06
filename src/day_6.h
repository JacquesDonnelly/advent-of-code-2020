#ifndef DAY_6_H
#define DAY_6_H

#include <string>
#include <vector>
#include <set>
#include "day_4.h"

class Group{
  public:
    int count_unique_yesses();
    int count_common_yesses();
    std::vector<std::string> answers;
};

Group group_from_text(std::string group_text);
std::vector<Group> parse_groups_from_file(std::string file_path);
int day_6_part_1_main(std::string file_path);
int day_6_part_2_main(std::string file_path);
std::set<char> string_to_character_set(std::string chars);

#endif
