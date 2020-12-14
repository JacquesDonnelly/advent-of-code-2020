#include "day_14.h"

int day_14_part_1_main(std::string file_path){
  std::vector<std::string> input_file = load_strings_from_file(file_path);
  ComputerSystem computer;
  for (std::string line : input_file){
    computer.process(line);
  }
  return computer.sum_all_addresses();
}

void ComputerSystem::process(std::string line){
  // TODO
  // If mask, set mask
  // else apply mask and set to memory
}

long ComputerSystem::sum_all_addresses(){
  // TODO
  // sum all values in memory map
  long result = 0;
  return result;
}

void ComputerSystem::update_mask(std::string mask){
  this->mask = mask;
}

void apply_mask(std::bitset<36> *bits, std::string mask){
  for (int i = 0; i < mask.length(); i++){
    int bitset_idx = mask.length() - 1 - i;
    if (mask[i] == '1'){
	    bits->set(bitset_idx);
    }
    if (mask[i] == '0'){
	    bits->reset(bitset_idx);
    }
  }
}
