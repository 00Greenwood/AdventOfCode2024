#include "precompiled.hxx"
#include <Day23.hxx>

Day23::Day23() : Day(23) {
}

Day23::~Day23() {
}

void Day23::initialize() {
  parse(name(), m_input);

  for (const auto& line : m_input) {
    std::string from = line.substr(0, line.find("-"));
    std::string to = line.substr(line.find("-") + 1);
    m_nodes[from].name = from;
    m_nodes[to].name = to;
    m_nodes[from].connections.insert(&m_nodes[to]);
    m_nodes[to].connections.insert(&m_nodes[from]);
  }
}

std::string Day23::solve(Part part) const {
  if (part == PART_1) {
    std::set<std::set<const Node*>> sets;

    for (const auto& [id, node] : m_nodes) {
      if (node.name.starts_with('t')) {
        for (const auto& connection : node.connections) {
          for (const auto& subConnection : connection->connections) {
            for (const auto& subSubConnection : subConnection->connections) {
              if (subSubConnection == &node) {
                std::set<const Node*> set = {&node, connection, subConnection};
                sets.insert(set);
              }
            }
          }
        }
      }
    }

    return std::to_string(sets.size());
  }

  std::set<std::string> output;
  for (const auto& [_, node] : m_nodes) {
    for (const auto& connection : node.connections) {
      std::set<const Node*> connected;
      connected.insert(&node);
      connected.insert(connection);
      for (const auto& otherConnection : node.connections) {
        bool fullyConnected = true;
        for (const auto& current : connected) {
          fullyConnected &= otherConnection->connections.contains(current);
        }
        if (fullyConnected) {
          connected.insert(otherConnection);
        }
      }
      if (connected.size() > output.size()) {
        std::set<std::string> names;
        std::transform(connected.begin(), connected.end(), std::inserter(names, names.begin()),
                       [](const Node* node) { return node->name; });
        output = names;
      }
    }
  }

  std::ostringstream ss;
  for (const auto& name : output) {
    ss << name << ',';
  }
  return ss.str();
}
