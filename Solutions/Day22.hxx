#pragma once

class Day22 : public Day {
public:
  explicit Day22();
  virtual ~Day22();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  size_t mix(size_t lhs, size_t rhs) const;

  size_t prune(size_t number) const;

  size_t divide(size_t number, size_t divisor) const;

  size_t convert(size_t number) const;

  std::string hash(const std::deque<int>& numbers) const;

  std::list<size_t> m_input;
};
