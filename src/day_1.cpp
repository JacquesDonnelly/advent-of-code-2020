#include "day_1.h"

int day_1_part_1_main(std::string file_path){
  std::vector<int> numbers = load_integers_from_file(file_path);
  std::pair<int,int> pair = find_two_ints_summing_to_2020(numbers);
  int result = std::get<0>(pair) * std::get<1>(pair);
  return result;
}


int day_1_part_2_main(std::string file_path){
  std::vector<int> numbers = load_integers_from_file(file_path);
  std::vector<int> triplet = find_three_ints_summing_to_2020(numbers);
  int result = triplet[0] * triplet[1] * triplet[2];
  return result;
}

std::vector<int> load_integers_from_file(std::string file_path){
  std::ifstream file(file_path);
  std::vector<int> result;
  std::string line;

  while (std::getline(file, line)){
    result.push_back(std::stoi(line));
  }

  return result;
}

std::pair<int,int> find_two_ints_summing_to_2020(const std::vector<int> &numbers){
  int length = static_cast<int>(numbers.size());
  std::pair<int,int> result;

  for (int i = 0; i < length - 1; i++){
    for (int j = i + 1; j < length; j++){
      if (numbers[i] + numbers[j] == 2020){
        result.first = numbers[i];
        result.second = numbers[j];
        return result;
      }
    }
  }
  return result;
}


std::vector<int> find_three_ints_summing_to_2020(const std::vector<int> &numbers){
  int length = static_cast<int>(numbers.size());
  std::vector<int> result;

  for (int i = 0; i < length - 2; i++){
    for (int j = i + 1; j < length - 1; j++){
      for (int k = j + 1; k < length; k++){
        if (numbers[i] + numbers[j] + numbers[k] == 2020){
	  result.push_back(numbers[i]);
	  result.push_back(numbers[j]);
	  result.push_back(numbers[k]);
          return result;
        }
      }
    }
  }
  return result;
}
