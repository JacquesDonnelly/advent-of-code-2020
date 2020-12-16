#include <gtest/gtest.h>

#include "day_16.h"

TEST(day_16, test_day_16_part_1_main){
  ASSERT_EQ(day_16_part_1_main("/code/tests/day_16_example.txt"), 71);
}

TEST(day_16, test_field_valid_for_any_field_range){
  Number number_1 {1};
  Number number_2 {4};
  Number number_3 {5};
  Number number_4 {6};
  Number number_5 {15};
  Number number_6 {22};
  Number number_7 {100};
  Range range_1a {1, 3};
  Range range_1b {5, 7};
  Range range_2a {9, 13};
  Range range_2b {20, 22};
  Field field_1 {{range_1a, range_1b}};
  Field field_2 {{range_2a, range_2b}};
  std::vector<Field> fields = {field_1, field_2};

  TicketValidator ticket_validator {fields};

  ASSERT_TRUE(ticket_validator.valid_for_any_field(number_1));
  ASSERT_FALSE(ticket_validator.valid_for_any_field(number_2));
  ASSERT_TRUE(ticket_validator.valid_for_any_field(number_3));
  ASSERT_TRUE(ticket_validator.valid_for_any_field(number_4));
  ASSERT_FALSE(ticket_validator.valid_for_any_field(number_5));
  ASSERT_TRUE(ticket_validator.valid_for_any_field(number_6));
  ASSERT_FALSE(ticket_validator.valid_for_any_field(number_7));
}

TEST(day_16, test_read_fields_from_file){
  std::vector<Field> fields = read_fields_from_file("/code/tests/day_16_example.txt");

  ASSERT_EQ(fields.size(), 3);
  ASSERT_EQ(fields[0].ranges[0].maximum, 3);
  ASSERT_EQ(fields[2].ranges[1].minimum, 45);
}

TEST(day_16, test_read_tickets_from_file){
  std::vector<Ticket> tickets = read_tickets_from_file("/code/tests/day_16_example.txt");
  ASSERT_EQ(tickets.size(), 4);
  ASSERT_EQ(tickets[0].numbers.size(), 3);
  ASSERT_EQ(tickets[0].numbers[1].value, 3);
  ASSERT_EQ(tickets[3].numbers[2].value, 12);
}
