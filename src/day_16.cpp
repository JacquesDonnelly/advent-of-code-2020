#include "day_16.h"

int day_16_part_1_main(std::string file_path){
  std::vector<Field> fields = read_fields_from_file(file_path);
  std::vector<Ticket> tickets = read_tickets_from_file(file_path);
  TicketValidator ticket_validator {fields};
  int result = 0;
  for (Ticket ticket : tickets){
    for (Number number : ticket.numbers){
      if (!ticket_validator.valid_for_any_field(number)){
	result += number.value;
      }
    }
  }
  return result;
}

bool TicketValidator::valid_for_any_field(Number number){
  for (Field field : this->fields){
    for (Range range : field.ranges){
      if (number.value >= range.minimum && number.value <= range.maximum) return true;
    }
  }
  return false;
}

TicketValidator::TicketValidator(std::vector<Field> fields){
  this->fields = fields;
}


std::vector<Field> read_fields_from_file(std::string file_path){
  std::vector<Field> result;
  std::string file = read_file_to_string(file_path);

  std::regex expression ("[a-z ]+: ([0-9]+)-([0-9]+) or ([0-9]+)-([0-9]+)");
  std::smatch match;

  while (std::regex_search (file, match, expression)) {
    Range lower_range {std::stoi(match[1]), std::stoi(match[2])};
    Range upper_range {std::stoi(match[3]), std::stoi(match[4])};
    std::vector<Range> ranges {lower_range, upper_range};
    Field field {ranges};
    result.push_back(field);
    file = match.suffix().str();
  }
  return result;
}

std::vector<Ticket> read_tickets_from_file(std::string file_path){
  std::vector<Ticket> result;
  std::string file = read_file_to_string(file_path);

  std::regex expression ("nearby tickets:\n");
  std::smatch match;
  std::regex_search (file, match, expression);
  file = match.suffix().str();
  std::vector<std::string> lines = split_string_by_delimiter(file, "\n");
  for (std::string line : lines){
    Ticket ticket;
    std::vector<std::string> string_numbers = split_string_by_delimiter(line, ",");
    for (std::string string_number : string_numbers){
      Number number {std::stoi(string_number)};
      ticket.numbers.push_back(number);
    }
    result.push_back(ticket);
  }
  return result;
}
