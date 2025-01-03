#pragma once

class Day21 : public Day {
public:
  explicit Day21();
  virtual ~Day21();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  using PossibleMove = std::vector<std::string>;
  using PossibleMoves = std::vector<PossibleMove>;
  using Cache = std::map<std::string, PossibleMoves>;
  using DepthCache = std::map<size_t, std::map<std::string, size_t>>;

  void populate(const std::string& input, Cache& cache) const;
  std::vector<std::string> move(char start, char end) const;

  size_t move(const std::string& input, const Cache& cache, size_t depth, DepthCache& depthCache) const;

  std::vector<std::string> m_input;

  std::map<char, Position> m_numberKeypad;
  std::map<char, Position> m_directionKeypad;
};
