#include "day_15.h"

int day_15_part_1_main(std::vector<int> starters){
  Game game {starters};
  for (int i = 0; i < 2020; i++){
    // Just change 2020 to 30000000 for part 2. 20 second runtime.
    game.say_number();
  }
  return game.get_most_recent();
}

Game::Game(std::vector<int> starters){
  this->starters = starters;
  this->current_turn = 0;
}

void Game::say_number(){
  int starters_length = this->starters.size();
  int number;
  if (this->current_turn < starters_length){
    number = this->starters[this->current_turn];
  }
  else{
    auto search = this->number_turn_map.find(this->most_recent_number);
    if (search == this->number_turn_map.end()){
      number = 0;
    }
    else {
      int last_turn_seen = this->number_turn_map[this->most_recent_number];
      number = this->current_turn - last_turn_seen - 1;
    }
  }
  this->number_turn_map[this->most_recent_number] = this->current_turn - 1;
  this->most_recent_number = number;
  this->current_turn++;
}

int Game::get_most_recent(){
  return this->most_recent_number;
}

