#ifndef DAY_3_H
#define DAY_3_H

#include <string>
#include <vector>

int day_3_part_1_main(std::string file_path);
int day_3_part_2_main(std::string file_path, int x_step, int y_step);

class Map {
  public:
    Map(std::string file_path);
    void set_step_size(int step_size);
    void set_y_step_size(int step_size);
    bool current_position_is_tree();
    void take_step();
    bool in_transit();
    char at(int y, int x);
    void set_position(int x, int y);
  private:
    std::pair<int,int> position;
    std::vector<std::vector<char>> grid;
    int step_size;
    int y_step_size;
};

int resolve_step(int current, int step_size, int grid_width);

#endif

