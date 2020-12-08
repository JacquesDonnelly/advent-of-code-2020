#ifndef DAY_8_H
#define DAY_8_H

#include <string>
#include <vector>
#include <set>

#include "day_2.h"

enum OperationCode { nop, acc, jmp };

struct Operation{
  OperationCode code;
  int value;
};

struct BootCode{
  std::vector<Operation> operations;
};

class Console{
  public:
    int accumulator;
    BootCode boot_code;
    Console(BootCode boot_code);
    void boot_until_duplicate_op();
    bool not_yet_duplicate_op();
    void perform_op();
  private:
    int index;
    std::set<int> seen_index;
};

int day_8_part_1_main(std::string file_path);
BootCode load_boot_code(std::string file_input);
OperationCode parse_operation_code(std::string line);
int parse_operation_value(std::string line);

#endif
