#include "day_8.h"

int day_8_part_1_main(std::string file_input){
  BootCode boot_code = load_boot_code(file_input);
  Console console{boot_code};
  console.boot_until_duplicate_op();
  return console.accumulator;
}

void Console::boot_until_duplicate_op(){
  while (this->not_yet_duplicate_op()){
    this->perform_op();
  }
}

void Console::perform_op(){
  this->seen_index.insert(this->index);
  Operation current_op = this->boot_code.operations[this->index];
  switch (current_op.code){
    case nop: 
      this->index += 1;
      break;
    case acc:
      this->accumulator += current_op.value;
      this->index += 1;
      break;
    case jmp:
      this->index += current_op.value;
      break;
  }
}

bool Console::not_yet_duplicate_op(){
  return !this->seen_index.contains(this->index);
}

BootCode load_boot_code(std::string file_input){
  BootCode boot_code;
  std::vector<std::string> lines = load_strings_from_file(file_input);
  for (std::string line : lines){
    OperationCode code = parse_operation_code(line);
    int value = parse_operation_value(line);
    Operation operation {code, value};
    boot_code.operations.push_back(operation);
  }
  return boot_code;
}

OperationCode parse_operation_code(std::string line){
  std::string op_string = line.substr(0,3); 
  OperationCode result;
  if (op_string == "nop") result = nop;
  if (op_string == "acc") result = acc;
  if (op_string == "jmp") result = jmp;
  return result;
}

int parse_operation_value(std::string line){
  std::regex expression ("[a-z]{3} ([+-])([0-9]+)");
  std::smatch match;
  std::regex_search(line, match, expression);
  std::string sign = match[1];
  std::string value = match[2];
  int result = std::stoi(value);
  if (sign == "-"){
    result *= -1;
  }
  return result;
}

Console::Console(BootCode boot_code){
  this->boot_code = boot_code;
  this->index = 0;
  this->accumulator = 0;
}

