#include "day_13.h"

#include <gtest/gtest.h>

TEST(day_13, test_day_13_part_1_main){
  int result = day_13_part_1_main("/code/tests/day_13_example.txt");

  ASSERT_EQ(result, 295);
}

TEST(day_13, test_read_bus_plan){
  BusNotes bus_notes = read_bus_notes("/code/tests/day_13_example.txt"); 

  ASSERT_EQ(bus_notes.earliest, 939);
  ASSERT_EQ(bus_notes.busses.size(), 5);
  ASSERT_EQ(bus_notes.busses[0].id, 7);
  ASSERT_EQ(bus_notes.busses[1].id, 13);
  ASSERT_EQ(bus_notes.busses[2].id, 59);
  ASSERT_EQ(bus_notes.busses[3].id, 31);
  ASSERT_EQ(bus_notes.busses[4].id, 19);
}
