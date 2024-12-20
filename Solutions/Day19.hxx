#pragma once

class Day19 : public Day {
public:
  explicit Day19();
  virtual ~Day19();

protected:
  void initialize() override;
  std::string solve(Part) const override;

  size_t validPatterns(const std::string& pattern, std::map<std::string, size_t>& cache, Part part) const;

  std::vector<std::string> m_input;
  std::vector<std::string> m_towels;
  std::vector<std::string> m_patterns;
};
