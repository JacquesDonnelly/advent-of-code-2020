#include "day_10.h"

long long day_10_part_2_main(std::string file_input){
  std::vector<int> adapters = load_integers_from_file(file_input);
  std::sort(adapters.begin(), adapters.end());
  adapters.insert(adapters.begin(), 0);
  std::map<int, long long> route;
  route[0] = 1;
  for (int j = 1; j < adapters.size(); j++){
    route[adapters[j]] = (
	route[adapters[j] - 1] +
	route[adapters[j] - 2] + 
	route[adapters[j] - 3]
    );
  }
  auto max = std::max_element(adapters.begin(), adapters.end());

  return route[*max];
}

int day_10_part_1_main(std::string file_input){
  std::vector<int> adapters = load_integers_from_file(file_input);
  std::sort(adapters.begin(), adapters.end());
  adapters.insert(adapters.begin(), 0);
  adapters.push_back(adapters[adapters.size()-1] + 3);
  std::vector<int> diffs = construct_diffs(adapters);
  std::map<int, int> diff_counts = count_gaps(diffs);

  return diff_counts[1] * diff_counts[3];
}

std::vector<int> construct_diffs(std::vector<int> sorted_vector){
  std::vector<int> result;
  int i = 0;
  int j = 1;
  while (j < sorted_vector.size()){
    result.push_back(sorted_vector[j] - sorted_vector[i]);
    i++;
    j++;
  }
  return result;
}


std::map<int, int> count_gaps(std::vector<int> values){
  std::map<int, int> result;
  for (int value : values) result[value] += 1;
  return result;
}

