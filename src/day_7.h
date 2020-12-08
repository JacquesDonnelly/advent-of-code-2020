#ifndef DAY_7_H
#define DAY_7_H

#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
#include <iostream>
#include <set>

#include "day_2.h"

struct Node{
  std::vector<Node *> parents;
  std::string name;
};

struct Relationship{
  std::string parent;
  std::vector<std::string> children;
};

int day_7_part_1_main(std::string file_path);
std::unordered_map<std::string, Node> load_node_hashmap(std::string file_path);
void add_all_parent_names_to_set(Node node, std::set<std::string> &set);
Relationship parse_line(std::string line);
void add_to_set(std::set<std::string> &set, std::string name);

#endif
