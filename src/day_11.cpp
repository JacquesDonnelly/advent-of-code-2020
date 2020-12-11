#include "day_11.h"

int day_11_part_2_main(std::string file_input, int occupied_threshold){
  Grid grid = load_grid(file_input);
  int change_count = 1;
  bool is_sight = true;
  while (change_count > 0) change_count = grid.step(occupied_threshold, is_sight);
  return grid.count_occupied();
}


int day_11_part_1_main(std::string file_input, int occupied_threshold){
  Grid grid = load_grid(file_input);
  int change_count = 1;
  bool is_sight = false;
  while (change_count > 0) change_count = grid.step(occupied_threshold, is_sight);
  return grid.count_occupied();
}


Grid load_grid(std::string file_path){
  std::vector<std::string> lines = load_strings_from_file(file_path);
  std::vector<std::vector<GridPoint>> positions;
  for (auto line : lines){
    std::vector<GridPoint> row;
    for (auto letter : line){
      if (letter == '.'){
        row.push_back(floor);
      }   
      if (letter == '#'){
        row.push_back(occupied);
      }   
      if (letter == 'L'){
        row.push_back(empty);
      }   
    }
    positions.push_back(row);
  }
  Grid grid {positions};
  return grid;
}

int Grid::step(int occupied_threshold, bool is_sight){
  int change_count = 0;
  std::vector<std::vector<GridPoint>> new_positions;
  for (int y = 0; y < this->positions.size(); y++){
    std::vector<GridPoint> row;
    for (int x = 0; x < this->positions[0].size(); x++){
      std::vector<GridPoint> surrounding;
      if (is_sight){
        surrounding = this->sight_resolve(x, y);
      }
      else {
        surrounding = this->get_surrounding_points(x, y);
      }
      int occupied_count = 0;
      for (GridPoint point : surrounding){
        if (point == occupied) occupied_count++;
      }

      switch (this->positions[y][x]){
        case floor:
          row.push_back(floor);
	  break;
	case empty:
	  if (occupied_count == 0){
            row.push_back(occupied);
	    change_count++;
	  }
	  else row.push_back(empty);
	  break;
	case occupied:
	  if (occupied_count >= occupied_threshold){
	    row.push_back(empty);
	    change_count++;
	  }
	  else row.push_back(occupied);
	  break;
      }
    }
    new_positions.push_back(row);
  }  
  this->positions = new_positions;
  return change_count;
}

std::vector<GridPoint> Grid::get_surrounding_points(int x, int y){
  std::vector<GridPoint> result;
  std::vector<int> x_range;
  std::vector<int> y_range;
  int height = static_cast<int>(this->positions.size());
  int width = static_cast<int>(this->positions[0].size());
  if (x == 0) x_range = {0, 1};
  else if (x == width - 1) x_range = {-1, 0};
  else x_range = {-1, 0, 1};
  if (y == 0) y_range = {0, 1};
  else if (y == height - 1) y_range = {-1, 0};
  else y_range = {-1, 0, 1};

  for (auto x_offset : x_range){
    for (auto y_offset : y_range){
      if (x_offset != 0 || y_offset != 0){
        result.push_back(this->positions[y + y_offset][x + x_offset]);
      }
    }
  }

  return result;
}


int Grid::count_occupied(){
  int count = 0;
  for (auto row: this->positions){
    for (auto point : row){
      if (point == occupied) count++;
    }
  }
  return count;
}

std::vector<GridPoint> Grid::sight_resolve(int x, int y){
  std::vector<GridPoint> result;
  std::vector<std::pair<int, int>> directions = {
    {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
  };
  for (std::pair<int, int> direction : directions){
    int x_direction = std::get<0>(direction);
    int y_direction = std::get<1>(direction);
    std::pair<int, int> idx = {x + x_direction, y + y_direction};
    while (this->is_on_grid(idx)){
      GridPoint point = this->positions[std::get<1>(idx)][std::get<0>(idx)];
      int new_x;
      int new_y;
      if (point == floor){
        new_x = std::get<0>(idx) + x_direction;
	new_y = std::get<1>(idx) + y_direction;
	std::pair<int, int> new_idx = {new_x, new_y};
	idx = new_idx;
      }
      else {
        result.push_back(point);
	std::pair<int, int> new_idx = {-1, -1};
	idx = new_idx;
      }
    }
  }
  return result;
}


bool Grid::is_on_grid(std::pair<int, int> idx){
  int height = static_cast<int>(this->positions.size());
  int width = static_cast<int>(this->positions[0].size());
  int x = std::get<0>(idx);
  int y = std::get<1>(idx);
  return (x >= 0) && (x < width) && (y >=0) && (y < height);
}
