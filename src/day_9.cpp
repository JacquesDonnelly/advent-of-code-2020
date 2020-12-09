#include "day_9.h"

long long day_9_part_2_main(std::string file_path, long long part_1){
  std::vector<long long> numbers = load_long_longs_from_file(file_path);
  std::pair<int, int> min_and_max_idx = find_contiguous_sum(numbers, part_1);
  int min_idx = std::get<0>(min_and_max_idx);
  int max_idx = std::get<1>(min_and_max_idx);
  long long min = 99999999;
  long long max = 0;
  long long current;
  for (int i = min_idx; i <= max_idx; i++){
    long long current = numbers[i];
    if (current < min) min = current;
    if (current > max) max = current;
  }
  return min + max;

}

std::pair<int, int> find_contiguous_sum(std::vector<long long> numbers, long long part_1){
  int input_length = static_cast<int>(numbers.size());
  long long sum;
  for (int i = 0; i < input_length; i++){
    sum = numbers[i];
    for (int j = i + 1; j < input_length; j++){ 
      sum += numbers[j];
      if (sum == part_1){
        return std::pair<int, int> {i, j};
      } 
      else if (sum > part_1) continue;
    }
    sum = 0;
  }
  return std::pair<int, int> {-1, -1};
}


long long day_9_part_1_main(std::string file_path, int preamble_size){
  std::vector<long long> numbers = load_long_longs_from_file(file_path); 
  int input_length = static_cast<int>(numbers.size());
  Window window (numbers, preamble_size);

  long long current_number;
  for (int idx = preamble_size; idx < input_length; idx++){
    current_number = numbers[idx];
    if (!window.is_valid(current_number)){
      return current_number;
    }
    window.shift(current_number);
  }
  return -1;
}

std::vector<long long> load_long_longs_from_file(std::string file_path){
  std::ifstream file(file_path);
  std::vector<long long> result;
  std::string line;

  while (std::getline(file, line)){
    result.push_back(std::stoll(line));
  }

  return result;
}

void Window::shift(long long value){
  this->possibles.pop_front();
  this->values.pop_front();
  this->values.push_back(value);
  int last_idx = static_cast<int>(this->values.size()) - 1;
  std::deque<long long> empty_q;
  this->possibles.push_back(empty_q);
  for (int i = 0; i < this->values.size() - 1; i++){
    this->possibles[last_idx].push_back(value + this->values[i]);
  }
}

Window::Window(std::vector<long long> numbers, int preamble_size){
  this->possibles = construct_possibles(numbers, preamble_size);
  this->values = construct_values(numbers, preamble_size);
}

std::deque<std::deque<long long>> construct_possibles(std::vector<long long> numbers, int preamble_size){
  std::deque<std::deque<long long>> possibles;
  for (int i = 0; i < preamble_size; i++){
    std::deque<long long> empty_q;
    possibles.push_back(empty_q);
  } 
  for (int j = 0; j < preamble_size; j++){
    for (int k = 0; k < preamble_size; k++){
     if (j != k){
       possibles[j].push_back(numbers[j] + numbers[k]);
     }
    }
  } 
  return possibles;
}


std::deque<long long> construct_values(std::vector<long long> numbers, int preamble_size){
  std::deque<long long> result;
  for (int i = 0; i < preamble_size; i++){
    result.push_back(numbers[i]);
  }
  return result;
}

bool Window::is_valid(long long value){
  for (std::deque<long long> queue : this->possibles){
    if (std::find(queue.begin(), queue.end(), value) != queue.end()) return true;
  }
  return false;
}

