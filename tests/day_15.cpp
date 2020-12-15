#include <gtest/gtest.h>

#include "day_15.h"

TEST(day_15, test_day_15_part_1_main){
  ASSERT_EQ(day_15_part_1_main({1,3,2}), 1);
  ASSERT_EQ(day_15_part_1_main({2,1,3}), 10);
  ASSERT_EQ(day_15_part_1_main({2,3,1}), 78);
  ASSERT_EQ(day_15_part_1_main({3,2,1}), 438);
  ASSERT_EQ(day_15_part_1_main({3,1,2}), 1836);
}

TEST(day_15, test_game_state){
  std::vector<int> starters {0,3,6};
  Game game {starters};
  game.say_number();
  ASSERT_EQ(game.get_most_recent(), 0);
  game.say_number();
  ASSERT_EQ(game.get_most_recent(), 3);
  game.say_number();
  ASSERT_EQ(game.get_most_recent(), 6);
  game.say_number();
  ASSERT_EQ(game.get_most_recent(), 0);
  game.say_number();
  ASSERT_EQ(game.get_most_recent(), 3);
  game.say_number();
  ASSERT_EQ(game.get_most_recent(), 3);
  game.say_number();
  ASSERT_EQ(game.get_most_recent(), 1);
  game.say_number();
  ASSERT_EQ(game.get_most_recent(), 0);
  game.say_number();
  ASSERT_EQ(game.get_most_recent(), 4);
  game.say_number();
  ASSERT_EQ(game.get_most_recent(), 0);
}
