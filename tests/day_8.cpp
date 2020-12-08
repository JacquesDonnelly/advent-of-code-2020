#include "day_8.h"

#include <gtest/gtest.h>

TEST(day_8, test_day_8_part_1_main){
  int result = day_8_part_1_main("/code/tests/day_8_example.txt");
  ASSERT_EQ(result, 5);
}

TEST(day_8, test_load_boot_code){
  BootCode result = load_boot_code("/code/tests/day_8_example.txt");

  ASSERT_EQ(result.operations.size(), 9);
  ASSERT_EQ(result.operations[0].code, nop);
  ASSERT_EQ(result.operations[2].code, jmp);
  ASSERT_EQ(result.operations[2].value, 4);
  ASSERT_EQ(result.operations[5].value, -99);
  ASSERT_EQ(result.operations[5].code, acc);
}
