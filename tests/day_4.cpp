#include <gtest/gtest.h>

#include "day_4.h"

TEST(day_4, test_day_4_part_2_main){
  std::string file_path = "/code/tests/day_4_example_2.txt";
  int result = day_4_part_2_main(file_path);
  ASSERT_EQ(result, 4);
}

TEST(day_4, test_key_value_validation){
  ASSERT_EQ(is_key_value_valid("byr:2002"), true);
  ASSERT_EQ(is_key_value_valid("byr:2003"), false);
  ASSERT_EQ(is_key_value_valid("hgt:60in"), true);
  ASSERT_EQ(is_key_value_valid("hgt:190cm"), true);
  ASSERT_EQ(is_key_value_valid("hgt:190in"), false);
  ASSERT_EQ(is_key_value_valid("hgt:190"), false);
  ASSERT_EQ(is_key_value_valid("hcl:#123abc"), true);
  ASSERT_EQ(is_key_value_valid("hcl:#123abz"), false);
  ASSERT_EQ(is_key_value_valid("hcl:123abc"), false);
  ASSERT_EQ(is_key_value_valid("ecl:brn"), true);
  ASSERT_EQ(is_key_value_valid("ecl:wat"), false);
  ASSERT_EQ(is_key_value_valid("pid:000000001"), true);
  ASSERT_EQ(is_key_value_valid("pid:0123456789"), false);
}

TEST(day_4, test_day_4_part_1_main){
  std::string file_path = "/code/tests/day_4_example.txt";
  int result = day_4_part_1_main(file_path);
  ASSERT_EQ(result, 2);
}

TEST(day_4, test_read_file_to_string){
  std::string file_path = "/code/tests/example_multiline.txt";
  std::string result = read_file_to_string(file_path);

  ASSERT_EQ(result, "this\ntext is\n\nmultiline");
}

TEST(day_4, test_split_string_by_delimiter){
  std::string file_path = "/code/tests/example_multiline.txt";
  std::string str = read_file_to_string(file_path);
  auto result = split_string_by_delimiter(str, "\n\n");

  ASSERT_EQ(result[0], "this\ntext is");
  ASSERT_EQ(result[1], "multiline");

  auto result_2 = split_string_by_delimiter(result[0], "\n"); 
  
  ASSERT_EQ(result_2[0], "this");
  ASSERT_EQ(result_2[1], "text is");

  auto result_3 = split_string_by_delimiter(result_2[1], " ");

  ASSERT_EQ(result_3[0], "text");
  ASSERT_EQ(result_3[1], "is");
}

TEST(day_4, test_vectorize_pairs){
  std::string file_path = "/code/tests/day_4_example.txt";
  std::string input_string = read_file_to_string(file_path);
  auto result = vectorize_pairs(input_string);

  ASSERT_EQ(result.size(), 4);
  ASSERT_EQ(result[0].size(), 8);
  ASSERT_EQ(result[1].size(), 7);
  ASSERT_EQ(result[2].size(), 7);
  ASSERT_EQ(result[3].size(), 6);
  ASSERT_EQ(result[0][2], "eyr:2020");
  ASSERT_EQ(result[3][4], "ecl:brn");
}


TEST(day_4, test_passport_is_valid){
  std::vector<std::string> input_1 = {
    "ecl:gry", 
    "pid:860033327", 
    "eyr:2020",
    "hcl:#fffffd",
    "byr:1937",
    "iyr:2017", 
    "cid:147", 
    "hgt:183cm"
  };

  std::vector<std::string> input_2 = {
    "ecl:gry", 
    "pid:860033327", 
    "eyr:2020",
    "hcl:#fffffd",
    "byr:1937",
    "iyr:2017", 
    "hgt:183cm"
  };

  std::vector<std::string> input_3 = {
    "ecl:gry", 
    "pid:860033327", 
    "eyr:2020",
    "byr:1937",
    "iyr:2017", 
    "cid:147", 
    "hgt:183cm"
  };
  
  bool result_1 = passport_is_valid(input_1);
  bool result_2 = passport_is_valid(input_2);
  bool result_3 = passport_is_valid(input_3);

  ASSERT_EQ(result_1, true);
  ASSERT_EQ(result_2, true);
  ASSERT_EQ(result_3, false);
}

