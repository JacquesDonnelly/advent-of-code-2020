#ifndef DAY_16_H
#define DAY_16_H

#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <streambuf>
#include <iostream>

#include "day_4.h"


struct Number {
  int value;
};

struct Range {
  int minimum;
  int maximum;
};

struct Field {
  std::vector<Range> ranges;
};

struct Ticket {
  std::vector<Number> numbers;
};

class TicketValidator {
  public:
    TicketValidator(std::vector<Field> fields);
    bool valid_for_any_field(Number number);
  private:
    std::vector<Field> fields;
};

int day_16_part_1_main(std::string file_path);
std::vector<Field> read_fields_from_file(std::string file_path);
std::vector<Ticket> read_tickets_from_file(std::string file_path);

#endif
