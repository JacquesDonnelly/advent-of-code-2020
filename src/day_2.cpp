#include "day_2.h"

int day_2_part_2_main(std::string file_path){
  int result = 0;
  std::vector<std::string> strings = load_strings_from_file(file_path);
  for (std::string string : strings){
    Password password = extract_password_from_string(string);
    if (password.is_really_valid()){
      result++;
    }
  }
  return result;
}


int day_2_part_1_main(std::string file_path){
  int result = 0;
  std::vector<std::string> strings = load_strings_from_file(file_path);
  for (std::string string : strings){
    Password password = extract_password_from_string(string);
    if (password.is_valid()){
      result++;
    }
  }
  return result;
}

std::vector<std::string> load_strings_from_file(std::string file_path){
  std::ifstream file(file_path);
  std::vector<std::string> result;
  std::string line;

  while (std::getline(file, line)){
    result.push_back(line);
  }

  return result;
}

bool Password::is_valid(){
  int letter_count = this->letter_count();
  int min = this->policy.minimum;
  int max = this->policy.maximum;
  bool result = false;
  if ((min <= letter_count) && (letter_count <= max)){
    result = true;
  }
  return result;
}

bool Password::is_really_valid(){
  bool first_correct = (this->text[this->policy.minimum - 1] == this->policy.letter);
  bool second_correct = (this->text[this->policy.maximum - 1] == this->policy.letter);
  return first_correct ^ second_correct;
}

int Password::letter_count(){
  int result = 0;
  for (char &c : this->text){
    if (c == this->policy.letter){
      result++;
    }
  }
  return result;
}

Password extract_password_from_string(std::string input_string){
  std::regex regex("([0-9]+)-([0-9]+) (.): (.*)");
  std::smatch regex_match;
  std::regex_search(input_string, regex_match, regex);

  std::string minimum_str = regex_match.str(1);
  std::string maximum_str = regex_match.str(2);
  std::string letter_str = regex_match.str(3);
  std::string text = regex_match.str(4);

  int minimum = std::stoi(minimum_str);
  int maximum = std::stoi(maximum_str);
  char letter = letter_str[0];

  Policy policy = {minimum, maximum, letter};
  Password password = {text, policy};
  return password;
}


Password::Password(std::string text, Policy policy){
  this->text = text;
  this->policy = policy;
}

