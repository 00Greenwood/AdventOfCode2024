#pragma once

class Day11 : public Day {
public:
  explicit Day11();
  virtual ~Day11();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  size_t blink(size_t stone, int index, std::map<std::pair<int, size_t>, size_t>& cache) const;

  std::list<size_t> m_input;
};
