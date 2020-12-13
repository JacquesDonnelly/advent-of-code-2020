#include "day_12.h"

int day_12_part_1_main(std::string file_path){
  std::vector<Instruction> instructions = load_instructions(file_path);
  int default_x = 0;
  int default_y = 0;
  int default_angle = 0;
  Ship ship {default_x, default_y, default_angle};
  for (Instruction instruction : instructions){
    ship.execute_instruction(instruction);
  }
  return ship.manhattan_distance();
}

int Ship::manhattan_distance(){
  return std::abs(this->x) + std::abs(this->y); 
}

void Ship::execute_instruction(Instruction instruction){
  switch(instruction.action){
    case north:
      this->y += instruction.magnitude;
      break;
    case south:
      this->y -= instruction.magnitude;
      break;
    case east:
      this->x += instruction.magnitude;
      break;
    case west:
      this->x -= instruction.magnitude;
      break;
    case left:
      this->angle = (this->angle - instruction.magnitude) % 360;
      if (this->angle < 0) this->angle += 360;
      break;
    case right:
      this->angle = (this->angle + instruction.magnitude) % 360;
      if (this->angle < 0) this->angle += 360;
      break;
    case forward:
      switch (this->angle){
      case 0:
        this->x += instruction.magnitude;
        break;
      case 90:
      	this->y -= instruction.magnitude;
  	break;
      case 180:
       	this->x -= instruction.magnitude;
  	break;
      case 270:
       	this->y += instruction.magnitude;
  	break;
      }
      break;
  }
}


std::vector<Instruction> load_instructions(std::string file_path){
  std::vector<Instruction> result;
  std::vector<std::string> lines = load_strings_from_file(file_path);
  for (std::string line : lines){
    result.push_back(parse_string_instruction(line));
  }
  return result;
}

Instruction parse_string_instruction(std::string string_instruction){
  std::regex regex("([NSEWLRF])([0-9]+)");
  std::smatch regex_match;
  std::regex_search(string_instruction, regex_match, regex);
  std::string letter = regex_match.str(1);
  std::string number = regex_match.str(2);
  Action action;
  if (letter == "N") action = north;
  if (letter == "S") action = south;
  if (letter == "E") action = east;
  if (letter == "W") action = west;
  if (letter == "L") action = left;
  if (letter == "R") action = right;
  if (letter == "F") action = forward;
  int magnitude = std::stoi(number);
  Instruction result {action, magnitude};
  return result;
}

