#include "day_4.h"

int day_4_part_2_main(std::string file_path){
  std::string input = read_file_to_string(file_path);
  auto passports = vectorize_pairs(input);
  int result = 0;
  bool all_valid;
  for (auto passport : passports){
    if (passport_is_valid(passport)){
      all_valid = true;
      for (auto key_value : passport){
	all_valid = all_valid && is_key_value_valid(key_value);
      }
      if (all_valid) result++;
    }
  }
  return result;
}

bool passport_is_valid(std::vector<std::string> passport){
  std::set<std::string> required = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
  for (std::string key_value : passport){
    required.erase(key_value.substr(0,3));
  }
  return static_cast<int>(required.size()) == 0;
}

int day_4_part_1_main(std::string file_path){
  std::string input = read_file_to_string(file_path);
  auto passports = vectorize_pairs(input);
  int result = 0;
  for (auto passport : passports){
    if (passport_is_valid(passport)){
      result++;
    }
  }
  return result;
}

bool is_key_value_valid(std::string key_value){
  bool result;
  std::string key = key_value.substr(0, 3);
  std::string value = key_value.substr(4, key_value.size());
  if (key == "byr") result = is_valid_byr(value);
  if (key == "hgt") result = is_valid_hgt(value);
  if (key == "hcl") result = is_valid_hcl(value);
  if (key == "ecl") result = is_valid_ecl(value);
  if (key == "pid") result = is_valid_pid(value);
  if (key == "iyr") result = is_valid_iyr(value);
  if (key == "eyr") result = is_valid_eyr(value);
  if (key == "cid") result = true;
  return result;
}

bool is_valid_pid(std::string value){
  bool result;
  std::regex regex("[0-9]{9}");
  if (std::regex_match(value, regex)) result = true;
  else result = false;
  return result;
}

bool is_valid_ecl(std::string value){
  std::set<std::string> valids = {"amb","blu","brn","gry","grn","hzl","oth"};
  bool result = valids.find(value) != valids.end();
  return result;
}

bool is_valid_hcl(std::string value){
  bool result;
  std::regex regex("#[0-9a-f]{6}");
  if (std::regex_match(value, regex)) result = true;
  else result = false;
  return result;
}

bool is_valid_byr(std::string value){
  int year = std::stoi(value);
  return (year >= 1920) && (year <= 2002);
}

bool is_valid_iyr(std::string value){
  int year = std::stoi(value);
  return (year >= 2010) && (year <= 2020);
}

bool is_valid_eyr(std::string value){
  int year = std::stoi(value);
  return (year >= 2020) && (year <= 2030);
}

bool is_valid_hgt(std::string value){
  bool result = false;
  std::string unit = value.substr(value.size() - 2, value.size());
  int height = std::stoi(value.substr(0, value.size() - 2));
  if (unit == "cm"){
    result = ((height >= 150) && (height <= 198));
  }
  if (unit == "in"){
    result = ((height >= 59) && (height <= 76));
  }
  return result;
}

std::string read_file_to_string(std::string file_path){
  std::ifstream in_file;
  in_file.open(file_path);
  std::stringstream string_stream;
  string_stream << in_file.rdbuf();
  std::string str = string_stream.str();
  auto result = str.substr(0, str.size()-1);
  return result;
}

std::vector<std::string> split_string_by_delimiter(std::string str, std::string delimiter){
  std::vector<std::string> result;
  size_t pos = 0;
  std::string token;
  while ((pos = str.find(delimiter)) != std::string::npos) {
    token = str.substr(0, pos);
    result.push_back(token);
    str.erase(0, pos + delimiter.length());
  }
  result.push_back(str);
  return result;
}


std::vector<std::vector<std::string>> vectorize_pairs(std::string input_string){
  std::vector<std::vector<std::string>> result;
  auto passports = split_string_by_delimiter(input_string, "\n\n");
  for (auto passport : passports){
    auto key_value_vector = get_key_value_vector(passport);
    result.push_back(key_value_vector);
  }
  return result;
}


std::vector<std::string> get_key_value_vector(std::string passport){
  std::vector<std::string> result;
  auto lines = split_string_by_delimiter(passport, "\n");
  for (auto line : lines){
   auto key_values = split_string_by_delimiter(line, " ");
   for (auto key_value : key_values){
     result.push_back(key_value);
   }
  }
  return result;
}
