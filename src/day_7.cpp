#include "day_7.h"

int day_7_part_1_main(std::string file_path){
  auto nodes = load_node_hashmap(file_path);
  std::set<std::string> bag_set;
  auto shiny_gold = nodes["shiny gold"];
  add_all_parent_names_to_set(shiny_gold, bag_set);
  int result = static_cast<int>(bag_set.size());
  return result;
}


std::unordered_map<std::string, Node> load_node_hashmap(std::string file_path){
  std::unordered_map<std::string, Node> dict;
  std::vector<std::string> lines = load_strings_from_file(file_path);
  for (auto line : lines){
    auto relationship = parse_line(line);
    Node empty_parent;
    empty_parent.name = relationship.parent;
    dict.try_emplace(relationship.parent, empty_parent);
    for (auto child : relationship.children){
      Node empty_child;
      empty_child.name = child;
      dict.try_emplace(child, empty_child);
      dict[child].parents.push_back(&dict[relationship.parent]);
    }
  }
  return dict;
}


void add_all_parent_names_to_set(Node node, std::set<std::string> &set){
  for (auto parent : node.parents){
    set.insert(parent->name);
    add_all_parent_names_to_set(*parent, set);
  }
}


Relationship parse_line(std::string line){
  Relationship relationship;

  // Match parent bag
  std::regex parent_expression ("(.*) bags contain .*");
  std::smatch parent_match;
  std::regex_search(line, parent_match, parent_expression);
  relationship.parent = parent_match[1];

  // Match children bags
  std::regex children_expression ("[0-9]+ ([a-z ]+) bags?");
  std::smatch children_match;
  while (std::regex_search (line, children_match, children_expression)) {
    relationship.children.push_back(children_match[1]);
    line = children_match.suffix().str();
  }

  return relationship;
}
