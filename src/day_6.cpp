#include "day_6.h"

int day_6_part_2_main(std::string file_path){
  auto groups = parse_groups_from_file(file_path);
  int count = 0;
  for (Group group : groups){
    count += group.count_common_yesses();
  }
  return count;
}

int day_6_part_1_main(std::string file_path){
  auto groups = parse_groups_from_file(file_path);
  int count = 0;
  for (Group group : groups){
    count += group.count_unique_yesses();
  }
  return count;
}

std::vector<Group> parse_groups_from_file(std::string file_path){
  std::vector<Group> result;
  std::string text = read_file_to_string(file_path);
  auto groups_text = split_string_by_delimiter(text, "\n\n");
  for (auto group_text : groups_text){
    result.push_back(group_from_text(group_text));
  }
  return result;
}

Group group_from_text(std::string group_text){
  Group group;
  group.answers = split_string_by_delimiter(group_text, "\n");
  return group;
}

int Group::count_unique_yesses(){
  std::set<char> character_set;
  for (std::string chars : this->answers){
    for (char &c : chars){
      character_set.insert(c);
    }
  }
  int result = static_cast<int>(character_set.size());
  return result;
}

int Group::count_common_yesses(){
  std::set<char> char_set = string_to_character_set(this->answers[0]);
  std::set<char> intersect;
  for (std::string chars : this->answers){
    intersect = {};
    auto answer_set = string_to_character_set(chars);
    set_intersection(
      answer_set.begin(),
      answer_set.end(),
      char_set.begin(),
      char_set.end(),
      std::inserter(intersect, intersect.begin())
    );
    char_set = intersect;
  }
  int result = static_cast<int>(char_set.size());
  return result;
}

std::set<char> string_to_character_set(std::string chars){
  std::set<char> result;
  for (char &c : chars){
    result.insert(c);
  }
  return result;
}

