#include "day_11.h"

#include <gtest/gtest.h>

TEST(day_11, test_day_11_part_2_main){
  int occupied_threshold = 5;
  int result = day_11_part_2_main("/code/tests/day_11_example.txt", occupied_threshold);

  ASSERT_EQ(result, 26);
}

TEST(day_11, test_day_11_part_1_main){
  int occupied_threshold = 4;
  int result = day_11_part_1_main("/code/tests/day_11_example.txt", occupied_threshold);

  ASSERT_EQ(result, 37);
}

TEST(day_11, test_load_grid){
  Grid grid = load_grid("/code/tests/day_11_small_example_grid.txt");

  ASSERT_EQ(grid.positions[0][0], floor);
  ASSERT_EQ(grid.positions[0][1], occupied);
  ASSERT_EQ(grid.positions[0][2], empty);
  ASSERT_EQ(grid.positions[1][0], occupied);
  ASSERT_EQ(grid.positions[1][1], occupied);
  ASSERT_EQ(grid.positions[1][2], occupied);
  ASSERT_EQ(grid.positions[2][0], floor);
  ASSERT_EQ(grid.positions[2][1], floor);
  ASSERT_EQ(grid.positions[2][2], empty);
}

TEST(day_11, test_get_surrounding_points){
  Grid grid = load_grid("/code/tests/day_11_small_example_grid.txt");

  auto surrounding = grid.get_surrounding_points(1, 1);
  int occupied_count = 0;
  int empty_count = 0;
  int floor_count = 0;
  for (GridPoint point : surrounding){
    switch (point) {
     case occupied:
       occupied_count++;
       break;
     case empty:
       empty_count++;
       break;
     case floor:
       floor_count++;
       break;
    }
  }
  ASSERT_EQ(occupied_count, 3);
  ASSERT_EQ(floor_count, 3);
  ASSERT_EQ(empty_count, 2);
}

TEST(day_11, test_get_surrounding_points_corner){
  Grid grid = load_grid("/code/tests/day_11_small_example_grid.txt");

  auto surrounding = grid.get_surrounding_points(2, 2);
  int occupied_count = 0;
  int empty_count = 0;
  int floor_count = 0;
  for (GridPoint point : surrounding){
    switch (point) {
     case occupied:
       occupied_count++;
       break;
     case empty:
       empty_count++;
       break;
     case floor:
       floor_count++;
       break;
    }
  }
  ASSERT_EQ(occupied_count, 2);
  ASSERT_EQ(floor_count, 1);
  ASSERT_EQ(empty_count, 0);
}

TEST(day_11, test_grid_step){
  Grid grid = load_grid("/code/tests/day_11_example_2.txt");
  int occupied_threshold = 4;
  int result = grid.step(occupied_threshold, false);

  ASSERT_EQ(result, 31);
  ASSERT_EQ(grid.positions[0][2], occupied);
}


TEST(day_11, test_count_occupied){
  Grid grid;
  std::vector<GridPoint> row_1 = {occupied, occupied, occupied};
  std::vector<GridPoint> row_2 = {floor, empty, occupied};
  std::vector<GridPoint> row_3 = {floor, occupied, empty};
  std::vector<std::vector<GridPoint>> positions = {row_1, row_2, row_3};
  grid.positions = positions;
  int result = grid.count_occupied();

  ASSERT_EQ(result, 5);
}

TEST(day_11, test_resolve_sight){
  Grid grid = load_grid("/code/tests/day_11_sight_resolve_1.txt");
  std::vector<GridPoint> resolved_sight = grid.sight_resolve(3, 4);
  int occupied_count = 0;
  int empty_count = 0;
  int floor_count = 0;
  for (GridPoint point : resolved_sight){
    switch (point) {
     case occupied:
       occupied_count++;
       break;
     case empty:
       empty_count++;
       break;
     case floor:
       floor_count++;
       break;
    }
  }
  ASSERT_EQ(occupied_count, 7);
  ASSERT_EQ(empty_count, 1);
  ASSERT_EQ(floor_count, 0);
}

