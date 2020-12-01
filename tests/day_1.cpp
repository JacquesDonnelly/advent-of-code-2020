#include <gtest/gtest.h>

#include "day_1.h"

TEST(day_1, test_load_integers_from_file){
  std::string file_path = "/code/tests/case_1.txt";
  std::vector<int> result = load_integers_from_file(file_path);

  int result_size = static_cast<int>(result.size());

  ASSERT_EQ(result_size, 6);
  ASSERT_EQ(result[0], 1721);
  ASSERT_EQ(result[5], 1456);
}

TEST(day_1, test_find_integers_summing_to_2020){
  std::string file_path = "/code/tests/case_1.txt";
  std::vector<int> numbers = load_integers_from_file(file_path);
  std::pair<int,int> result = find_two_ints_summing_to_2020(numbers);

  ASSERT_EQ(std::get<0>(result), 1721);
  ASSERT_EQ(std::get<1>(result), 299);
}

TEST(day_1, test_day_1_part_1_main){
  std::string file_path = "/code/tests/case_1.txt";
  int result = day_1_part_1_main(file_path);
  
  ASSERT_EQ(result, 514579); 
}

TEST(day_1, test_find_three_integers_summing_to_2020){
  std::string file_path = "/code/tests/case_1.txt";
  std::vector<int> numbers = load_integers_from_file(file_path);
  std::vector<int> result = find_three_ints_summing_to_2020(numbers);

  ASSERT_EQ(result[0], 979);
  ASSERT_EQ(result[1], 366);
  ASSERT_EQ(result[2], 675);
}

TEST(day_1, test_day_1_part_2_main){
  std::string file_path = "/code/tests/case_1.txt";
  int result = day_1_part_2_main(file_path);
  
  ASSERT_EQ(result, 241861950); 
}
