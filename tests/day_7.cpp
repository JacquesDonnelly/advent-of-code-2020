#include <gtest/gtest.h>

#include "day_7.h"

TEST(day_7, test_day_7_part_1_main){
  std::string file_path = "/code/tests/day_7_example.txt";
  int result = day_7_part_1_main(file_path);

  ASSERT_EQ(result, 4);
}

TEST(day_7, test_parse_line){
  Relationship rel_1 = parse_line("dotted black bags contain no other bags.");
  Relationship rel_2 = parse_line("vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.");
  Relationship rel_3 = parse_line("light red bags contain 1 bright white bag, 2 muted yellow bags.");
  Relationship rel_4 = parse_line("bright white bags contain 1 shiny gold bag.");

  ASSERT_EQ(rel_1.parent, "dotted black");
  ASSERT_EQ(rel_1.children.size(), 0);
  ASSERT_EQ(rel_2.parent, "vibrant plum");
  ASSERT_EQ(rel_2.children.size(), 2);
  ASSERT_EQ(rel_2.children[0], "faded blue");
  ASSERT_EQ(rel_2.children[1], "dotted black");
  ASSERT_EQ(rel_3.parent, "light red");
  ASSERT_EQ(rel_3.children.size(), 2);
  ASSERT_EQ(rel_3.children[0], "bright white");
  ASSERT_EQ(rel_3.children[1], "muted yellow");
  ASSERT_EQ(rel_4.parent, "bright white");
  ASSERT_EQ(rel_4.children.size(), 1);
  ASSERT_EQ(rel_4.children[0], "shiny gold");
}

TEST(day_7, test_load_node_hashmap){
  auto dict = load_node_hashmap("/code/tests/day_7_example.txt");
  auto bright_white = dict["bright white"];

  ASSERT_EQ(bright_white.parents[0]->name, "light red");
  ASSERT_EQ(bright_white.parents[1]->name, "dark orange");
}

