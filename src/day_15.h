#ifndef DAY_15_H
#define DAY_15_H

#include <vector>
#include <iostream>
#include <map>

class Game {
  public:
    Game(std::vector<int> starters);
    int get_most_recent();
    void say_number();
  private:
    std::vector<int> starters;
    std::map<int, int> number_turn_map;
    int most_recent_number;
    int current_turn;
};

int day_15_part_1_main(std::vector<int> starters);

#endif
