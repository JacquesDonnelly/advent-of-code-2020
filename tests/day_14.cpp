#include <gtest/gtest.h>

#include "day_14.h"

//TEST(day_14, test_day_14_part_1_main){
  //int result = day_14_part_1_main("/code/tests/day_14_example.txt");
  //ASSERT_EQ(result, 165);
//}

TEST(day_14, test_apply_mask){
  std::bitset<36> bits(11);
  std::string mask = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X";
  apply_mask(&bits, mask);
  ASSERT_EQ(static_cast<int>(bits.to_ulong()), 73);
}
