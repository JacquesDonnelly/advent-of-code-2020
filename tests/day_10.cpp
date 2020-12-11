#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "day_10.h"

using ::testing::ElementsAre;

TEST(day_10, test_day_10_part_1_main){
  int result = day_10_part_1_main("/code/tests/day_10_example.txt");

  ASSERT_EQ(result, 220);
}

TEST(day_10, test_day_10_part_2_main){
  long long result = day_10_part_2_main("/code/tests/day_10_example.txt");

  ASSERT_EQ(result, 19208);
}

TEST(day_10, test_construct_diffs){
  std::vector<int> sorted_vector {1,2,3,4,5,7,9,12};
  std::vector<int> diffs = construct_diffs(sorted_vector);

  ASSERT_THAT(diffs, ElementsAre(1,1,1,1,2,2,3));
}

TEST(day_10, test_count_gaps){
  std::vector<int> values {1, 2, 2, 3, 3, 3, 4, 4, 4, 5};
  std::map<int, int> result = count_gaps(values);

  ASSERT_EQ(result[1], 1);
  ASSERT_EQ(result[2], 2);
  ASSERT_EQ(result[3], 3);
  ASSERT_EQ(result[4], 3);
  ASSERT_EQ(result[5], 1);
}
