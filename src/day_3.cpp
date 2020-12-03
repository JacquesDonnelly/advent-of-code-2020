#include "day_2.h"
#include "day_3.h"

int day_3_part_2_main(std::string file_path, int x_step, int y_step){
  int trees = 0;
  Map map{file_path};
  map.set_step_size(x_step);
  map.set_y_step_size(y_step);
  while (map.in_transit()){
    map.take_step();
    if (map.current_position_is_tree()){
      trees++;
    }
  }
  return trees;
}

int day_3_part_1_main(std::string file_path){
  int trees = 0;
  Map map{file_path};
  map.set_step_size(3);
  while (map.in_transit()){
    map.take_step();
    if (map.current_position_is_tree()){
      trees++;
    }
  }
  return trees;
}

Map::Map(std::string file_path){
  std::vector<std::string> strings = load_strings_from_file(file_path);
  std::vector<std::vector<char>> grid;
  for (int i = 0; i < strings.size(); i++){
    grid.push_back({});
    for (int j = 0; j < strings[0].size(); j++){
      grid[i].push_back(strings[i][j]);
    }
  }

  std::pair<int, int> starting_postition {0, 0};
  int default_step_size = 1;
  int default_y_step_size = 1;
  this->grid = grid;
  this->position = starting_postition;
  this->step_size = default_step_size;
  this->y_step_size = default_y_step_size;
}

void Map::set_step_size(int step_size){
  this->step_size = step_size;
}

void Map::set_y_step_size(int step_size){
  this->y_step_size = step_size;
}

bool Map::current_position_is_tree(){
  int y = std::get<0>(this->position);
  int x = std::get<1>(this->position);
  char letter = this->at(y, x);
  return letter == '#';
}

void Map::take_step(){
  int y = std::get<0>(this->position);
  int x = std::get<1>(this->position);
  int new_y = y + this->y_step_size;
  int grid_width = static_cast<int>(this->grid[0].size());
  int new_x = resolve_step(x, this->step_size, grid_width);
  this->set_position(new_y, new_x);
}

bool Map::in_transit(){
  int y = std::get<0>(this->position);
  int map_height = static_cast<int>(this->grid.size());
  return y < map_height - 1;
}

char Map::at(int y, int x){
  return this->grid[y][x];
}

void Map::set_position(int x, int y){
  std::pair<int, int> new_position {x, y};
  this->position = new_position;
}

int resolve_step(int current, int step_size, int grid_width){
  return (current + step_size) % grid_width;
}
