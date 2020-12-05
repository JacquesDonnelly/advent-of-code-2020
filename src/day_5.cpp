#include "day_2.h"
#include "day_5.h"


int day_5_part_2_main(std::string file_path){
  int max = day_5_part_1_main(file_path);
  int min = find_min_id(file_path);
  int sum_of_input_ids = sum_all_ids(file_path);
  int sum_of_all_ids = (max - min + 1) * (min + max) / 2;
  return sum_of_all_ids - sum_of_input_ids;
}

int sum_all_ids(std::string file_path){
  // Same as part 1 main but calculates total
  auto strings = load_strings_from_file(file_path);
  int sum = 0;
  int seat_id;
  for (auto string : strings){
    sum += calculate_id(string);
  }
  return sum;
}

int find_min_id(std::string file_path){
  // Same as part 1 main but calculates min
  auto strings = load_strings_from_file(file_path);
  int min = 900; // we know 900 is upper bound
  int seat_id;
  for (auto string : strings){
    seat_id = calculate_id(string);
    if (seat_id < min) min = seat_id;
  }
  return min;
}

int day_5_part_1_main(std::string file_path){
  auto strings = load_strings_from_file(file_path);
  int max = 0;
  int seat_id;
  for (auto string : strings){
    seat_id = calculate_id(string);
    if (seat_id > max) max = seat_id;
  }
  return max;
}

int calculate_id(std::string partition){
  Seat seat = resolve_seat(partition);
  return 8 * seat.row + seat.column;
}

Seat resolve_seat(std::string partitioning){
  Seat seat;
  seat.row = resolve_partition(partitioning.substr(0, 7));
  seat.column = resolve_partition(partitioning.substr(7, 10));
  return seat;
}

int resolve_partition(std::string row_partition){
  int length = static_cast<int>(row_partition.size());
  int upper = std::pow(2, length) - 1;
  int lower = 0;
  int diff = std::pow(2, length - 1);
  for (char& c : row_partition){
    //std::cout << "lower: " << lower << " upper: " << upper << std::endl;
    if (c == 'F' || c == 'L') upper -= diff;
    if (c == 'B' || c == 'R') lower += diff;
    diff /= 2;
  }
  return upper;
}

