#include "day_13.h"

int day_13_part_1_main(std::string file_input){
  BusNotes bus_notes = read_bus_notes(file_input);
  int min_wait_time = std::numeric_limits<int>::max();
  int selected_bus_id = std::numeric_limits<int>::max();
  for (Bus bus : bus_notes.busses){
    int wait_time = bus.id - (bus_notes.earliest % bus.id);
    std::cout << wait_time << std::endl;
    if (wait_time < min_wait_time){
       min_wait_time = wait_time;
       selected_bus_id = bus.id;
    }
  }
  return min_wait_time * selected_bus_id;
}

BusNotes read_bus_notes(std::string file_input){
  std::vector<std::string> lines = load_strings_from_file(file_input);
  int earliest = std::stoi(lines[0]);
  auto bus_id_strings = split_string_by_delimiter(lines[1], ",");
  std::vector<Bus> busses;
  for (auto id : bus_id_strings){
    if (id != "x"){
      Bus bus;
      bus.id = std::stoi(id);
      busses.push_back(bus);
    }
  }
  BusNotes result;
  result.earliest = earliest;
  result.busses = busses;
  return result;
}

