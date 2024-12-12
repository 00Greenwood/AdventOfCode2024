#include <Day12.hxx>
#include <Direction.hxx>
#include <parse.hxx>

#include <set>
#include <map>

namespace {
struct Node {
  char id;
  std::set<Position> adjacent;
};
}

Day12::Day12() : Day(12) {
}

Day12::~Day12() {
}

void Day12::initialize() {
  parse(name(), m_input);
}

std::string Day12::solve(Part part) const {
  std::map<Position, Node> nodes;
  for (int y = 0; y < m_input.size(); ++y) {
    for (int x = 0; x < m_input.at(y).size(); ++x) {
      nodes[Position(x, y)] = Node(m_input[y][x]);
    }
  }

  std::list<Position> positions;
  for (const auto& [position, node] : nodes) {
    positions.push_back(position);
    for (const auto& direction : DIRECTIONS) {
      Position adjacent = position + direction;
      if (nodes.count(adjacent) > 0 && nodes.at(adjacent).id == node.id) {
          nodes.at(position).adjacent.insert(adjacent);
          nodes.at(adjacent).adjacent.insert(position);
      }
    }
  }

  std::vector<std::set<Position>> groups;
  while (positions.size() > 0) {
    std::set<Position> group;
    group.insert(positions.front());
    std::list<Position> toCheck;
    toCheck.push_back(positions.front());
    while (toCheck.size() > 0) {
      Position position = toCheck.front();
      toCheck.pop_front();
      for (const auto& adjacent : nodes.at(position).adjacent) {
        if (group.contains(adjacent)) {
          continue;
        }
        group.insert(adjacent);
        toCheck.push_back(adjacent);
      }
    }
    groups.push_back(group);
    for (const auto& position : group) {
      positions.remove(position);
    }
  }

  size_t total = 0;
  for (const auto& group : groups) {
    size_t perimeter = 0;
    for (const auto& position : group) {
      perimeter += 4 - nodes.at(position).adjacent.size();
    }
    total += group.size() * perimeter;
  }

  return std::to_string(total);
}
