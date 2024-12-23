#pragma once

class Day23 : public Day {
public:
  explicit Day23();
  virtual ~Day23();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  std::vector<std::string> m_input;

  struct Node {
    std::string name;
    std::set<const Node*> connections;
  };

  std::map<std::string, Node> m_nodes;
};
