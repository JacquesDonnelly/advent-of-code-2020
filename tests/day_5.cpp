#include <gtest/gtest.h>

#include "day_5.h"

TEST(day_5, test_resolve_seat){
  auto result_1 = resolve_seat("FBFBBFFRLR");
  ASSERT_EQ(result_1.row, 44);
  ASSERT_EQ(result_1.column, 5);

  auto result_2 = resolve_seat("BFFFBBFRRR");
  ASSERT_EQ(result_2.row, 70);
  ASSERT_EQ(result_2.column, 7);

  auto result_3 = resolve_seat("FFFBBBFRRR");
  ASSERT_EQ(result_3.row, 14);
  ASSERT_EQ(result_3.column, 7);

  auto result_4 = resolve_seat("BBFFBBFRLL");
  ASSERT_EQ(result_4.row, 102);
  ASSERT_EQ(result_4.column, 4);
}

TEST(day_5, test_day_5_part_1_main){
  std::string file_path = "/code/tests/day_5_example.txt";
  int result = day_5_part_1_main(file_path);
  ASSERT_EQ(result, 820);
}
