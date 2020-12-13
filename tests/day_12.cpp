#include "day_12.h"

#include <gtest/gtest.h>

TEST(day_12, test_day_12_part_1_main){
  int result = day_12_part_1_main("/code/tests/day_12_example.txt");

  ASSERT_EQ(result, 25);
}

TEST(day_12, test_load_instructions){
  auto instructions = load_instructions("/code/tests/day_12_example.txt");

  ASSERT_EQ(instructions[0].action, forward);
  ASSERT_EQ(instructions[0].magnitude, 10);
  ASSERT_EQ(instructions[1].action, north);
  ASSERT_EQ(instructions[1].magnitude, 3);
  ASSERT_EQ(instructions[2].action, forward);
  ASSERT_EQ(instructions[2].magnitude, 7);
  ASSERT_EQ(instructions[3].action, right);
  ASSERT_EQ(instructions[3].magnitude, 90);
  ASSERT_EQ(instructions[4].action, forward);
  ASSERT_EQ(instructions[4].magnitude, 11);
}

TEST(day_12, test_parse_string_instruction){
  std::string input_1 = "N1";
  std::string input_2 = "S20";
  std::string input_3 = "E15";
  std::string input_4 = "W6";
  std::string input_5 = "L90";
  std::string input_6 = "R270";
  std::string input_7 = "F10";

  Instruction result_1 = parse_string_instruction(input_1);
  Instruction result_2 = parse_string_instruction(input_2);
  Instruction result_3 = parse_string_instruction(input_3);
  Instruction result_4 = parse_string_instruction(input_4);
  Instruction result_5 = parse_string_instruction(input_5);
  Instruction result_6 = parse_string_instruction(input_6);
  Instruction result_7 = parse_string_instruction(input_7);

  ASSERT_EQ(result_1.action, north);
  ASSERT_EQ(result_1.magnitude, 1);
  ASSERT_EQ(result_2.action, south);
  ASSERT_EQ(result_2.magnitude, 20);
  ASSERT_EQ(result_3.action, east);
  ASSERT_EQ(result_3.magnitude, 15);
  ASSERT_EQ(result_4.action, west);
  ASSERT_EQ(result_4.magnitude, 6);
  ASSERT_EQ(result_5.action, left);
  ASSERT_EQ(result_5.magnitude, 90);
  ASSERT_EQ(result_6.action, right);
  ASSERT_EQ(result_6.magnitude, 270);
  ASSERT_EQ(result_7.action, forward);
  ASSERT_EQ(result_7.magnitude, 10);
}

TEST(day_12, test_execute_instruction){
  int default_x = 0;
  int default_y = 0;
  int default_angle = 0;
  Ship ship {default_x, default_y, default_angle};

  Instruction instruction_1 {north, 10};
  ship.execute_instruction(instruction_1);
  ASSERT_EQ(ship.y, 10);
  ASSERT_EQ(ship.x, 0);
  ASSERT_EQ(ship.angle, 0);

  Instruction instruction_2 {east, 20};
  ship.execute_instruction(instruction_2);
  ASSERT_EQ(ship.y, 10);
  ASSERT_EQ(ship.x, 20);
  ASSERT_EQ(ship.angle, 0);

  Instruction instruction_3 {left, 270};
  ship.execute_instruction(instruction_3);
  ASSERT_EQ(ship.y, 10);
  ASSERT_EQ(ship.x, 20);
  ASSERT_EQ(ship.angle, 90);

  Instruction instruction_4 {west, 40};
  ship.execute_instruction(instruction_4);
  ASSERT_EQ(ship.y, 10);
  ASSERT_EQ(ship.x, -20);
  ASSERT_EQ(ship.angle, 90);

  Instruction instruction_5 {forward, 15};
  ship.execute_instruction(instruction_5);
  ASSERT_EQ(ship.y, -5);
  ASSERT_EQ(ship.x, -20);
  ASSERT_EQ(ship.angle, 90);

  Instruction instruction_6 {right, 180};
  ship.execute_instruction(instruction_6);
  ASSERT_EQ(ship.y, -5);
  ASSERT_EQ(ship.x, -20);
  ASSERT_EQ(ship.angle, 270);
}

