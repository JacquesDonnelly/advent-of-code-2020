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

TEST(day_2, test_find_integers_summing_to_2020){
  std::string file_path = "/code/tests/case_1.txt";
  std::vector<int> numbers = load_integers_from_file(file_path);
  std::pair<int,int> result = find_integers_summing_to_2020(numbers);

  ASSERT_EQ(std::get<0>(result), 1721);
  ASSERT_EQ(std::get<1>(result), 299);
}

TEST(day_2, test_day_1_main){
  std::string file_path = "/code/tests/case_1.txt";
  int result = day_1_main(file_path);
  
  ASSERT_EQ(result, 514579); 
}
