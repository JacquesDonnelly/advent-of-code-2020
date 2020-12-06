#include <gtest/gtest.h>

#include "day_6.h"

TEST(day_6, test_day_6_part_2_main){
  std::string file_path = "/code/tests/day_6_example.txt";
  int result = day_6_part_2_main(file_path);
  ASSERT_EQ(result, 6);
}

TEST(day_6, test_day_6_part_1_main){
  std::string file_path = "/code/tests/day_6_example.txt";
  int result = day_6_part_1_main(file_path);
  ASSERT_EQ(result, 11);
}

TEST(day_6, test_parse_groups_from_file){
  std::string file_path = "/code/tests/day_6_example.txt";
  auto groups = parse_groups_from_file(file_path);

  ASSERT_EQ(groups.size(), 5);
  ASSERT_EQ(groups[0].answers.size(), 1);
  ASSERT_EQ(groups[0].answers[0], "abc");
  ASSERT_EQ(groups[1].answers.size(), 3);
  ASSERT_EQ(groups[4].answers[0], "b");
  ASSERT_EQ(groups[4].answers.size(), 1);
}

TEST(day_6, test_count_unique_yesses){
  Group group_1 = group_from_text("a\nb\nabc");
  Group group_2 = group_from_text("x\nx\ny");
  Group group_3 = group_from_text("abc\nabcd\nab\nac\nd");

  ASSERT_EQ(group_1.count_unique_yesses(), 3);
  ASSERT_EQ(group_2.count_unique_yesses(), 2);
  ASSERT_EQ(group_3.count_unique_yesses(), 4);
}

TEST(day_6, test_count_common_yesses){
  Group group_1 = group_from_text("ab\nac\nad");
  Group group_2 = group_from_text("x\nx\ny");
  Group group_3 = group_from_text("abcd\nabty\nabutxck");

  ASSERT_EQ(group_1.count_common_yesses(), 1);
  ASSERT_EQ(group_2.count_common_yesses(), 0);
  ASSERT_EQ(group_3.count_common_yesses(), 2);
}
