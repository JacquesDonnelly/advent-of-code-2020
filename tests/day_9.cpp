#include <gtest/gtest.h>

#include "day_9.h"

TEST(day_9, test_day_9_part_2_main){
  long long result = day_9_part_2_main("/code/tests/day_9_example.txt", 127LL);
  ASSERT_EQ(result, 62);
}

TEST(day_9, test_day_9_part_1_main){
  long long result = day_9_part_1_main("/code/tests/day_9_example.txt", 5);
  ASSERT_EQ(result, 127);
}

TEST(day_9, test_is_valid){
  std::vector<long long> numbers {1,2,3,4,5};
  int preamble_size = 3;
  Window window(numbers, preamble_size);

  ASSERT_EQ(window.is_valid(1), false);
  ASSERT_EQ(window.is_valid(2), false);
  ASSERT_EQ(window.is_valid(3), true);
  ASSERT_EQ(window.is_valid(4), true);
  ASSERT_EQ(window.is_valid(5), true);
  ASSERT_EQ(window.is_valid(6), false);
  ASSERT_EQ(window.is_valid(7), false);
  ASSERT_EQ(window.is_valid(7), false);
  ASSERT_EQ(window.is_valid(9), false);
}


TEST(day_9, test_construct_possibles){
  std::vector<long long> numbers {1,2,3,4,5};
  int preamble_size = 3;

  std::deque<std::deque<long long>> possibles = construct_possibles(numbers, preamble_size);

  ASSERT_EQ(possibles[0][0], 3);
  ASSERT_EQ(possibles[0][1], 4);
  ASSERT_EQ(possibles[1][0], 3);
  ASSERT_EQ(possibles[1][1], 5);
  ASSERT_EQ(possibles[2][0], 4);
  ASSERT_EQ(possibles[2][1], 5);
}

TEST(day_9, test_constructor_window_values){
  std::vector<long long> numbers {1,2,3,4,5};
  int preamble_size = 3;
  std::deque<long long> values = construct_values(numbers, preamble_size);

  ASSERT_EQ(values.size(), preamble_size);
  ASSERT_EQ(values[0], 1);
  ASSERT_EQ(values[1], 2);
  ASSERT_EQ(values[2], 3);
}

TEST(day_9, test_shift_window){
  std::vector<long long> numbers {1,2,3};
  int preamble_size = 3;
  Window window(numbers, preamble_size);
  ASSERT_EQ(window.possibles[0][0], 3);
  ASSERT_EQ(window.possibles[0][1], 4);
  ASSERT_EQ(window.possibles[2][0], 4);
  ASSERT_EQ(window.possibles[2][1], 5);
  ASSERT_EQ(window.values[0], 1);
  ASSERT_EQ(window.values[1], 2);
  ASSERT_EQ(window.values[2], 3);
  window.shift(4);
  ASSERT_EQ(window.possibles[0][0], 3);
  ASSERT_EQ(window.possibles[0][1], 5);
  ASSERT_EQ(window.possibles[2][0], 6);
  ASSERT_EQ(window.possibles[2][1], 7);
  ASSERT_EQ(window.values[0], 2);
  ASSERT_EQ(window.values[1], 3);
  ASSERT_EQ(window.values[2], 4);
}

