#include <gtest/gtest.h>

#include "day_3.h"

TEST(day_3_part_2, e2e){
  std::string f = "/code/tests/day_3_example_input.txt";
  ASSERT_EQ(day_3_part_2_main(f, 1, 1), 2);
  ASSERT_EQ(day_3_part_2_main(f, 3, 1), 7);
  ASSERT_EQ(day_3_part_2_main(f, 5, 1), 3);
  ASSERT_EQ(day_3_part_2_main(f, 7, 1), 4);
  ASSERT_EQ(day_3_part_2_main(f, 1, 2), 2);
}

TEST(day_3, e2e){
  int result = day_3_part_1_main("/code/tests/day_3_example_input.txt");

  ASSERT_EQ(result, 7);
}

TEST(day_3, test_map_at){
  Map map{"/code/tests/day_3_example_input.txt"};

  ASSERT_EQ(map.at(0, 0), '.');
  ASSERT_EQ(map.at(1, 0), '#');
  ASSERT_EQ(map.at(2, 7), '.'); 
}

TEST(day_3, test_current_position_is_tree){
  Map map{"/code/tests/day_3_example_input.txt"};

  map.set_position(1, 0);
  ASSERT_EQ(map.current_position_is_tree(), true);

  map.set_position(2, 7);
  ASSERT_EQ(map.current_position_is_tree(), false);
}

TEST(day_3, test_number_of_steps_possible){
  int step_count = 0;
  Map map{"/code/tests/day_3_example_input.txt"};
  do {
    map.take_step();
    step_count++;
  }
  while (map.in_transit());

  ASSERT_EQ(step_count, 10);
}

TEST(day_3, test_resolve_step){
  int current_1 = 3;
  int current_2 = 5;
  int current_3 = 8;

  int step_size_1 = 2;
  int step_size_2 = 5;
  int step_size_3 = 3;

  int grid_width_1 = 5;
  int grid_width_2 = 11;
  int grid_width_3 = 9;

  ASSERT_EQ(resolve_step(current_1, step_size_1, grid_width_1), 0);
  ASSERT_EQ(resolve_step(current_2, step_size_2, grid_width_2), 10);
  ASSERT_EQ(resolve_step(current_3, step_size_3, grid_width_3), 2);
}
