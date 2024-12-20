#include "precompiled.hxx"

Day2::Day2() : Day(2) {
}

Day2::~Day2() {
}

void Day2::initialize() {
  parse(name(), m_input);
}

std::string Day2::solve(Part part) const {
  int safeReports = 0;
  for (const auto& report : m_input) {
    if (isReportSafe(report)) {
      safeReports++;
    } else if (part == PART_2) {
      for (int i = 0; i < report.size(); ++i) {
        auto newReport = report;
        newReport.erase(newReport.begin() + i);
        if (isReportSafe(newReport)) {
          safeReports++;
          break;
        }
      }
    }
  }
  return std::to_string(safeReports);
}

bool Day2::isReportSafe(const std::vector<int>& report) const {
  std::vector<int> errors;
  std::vector<int> increases;
  std::vector<int> decreases;
  size_t steps = report.size() - 1;
  for (int i = 0; i < steps; ++i) {
    int curr = report.at(i);
    int next = report.at(i + 1);
    if (std::abs(curr - next) > 3 || std::abs(curr - next) < 1) {
      errors.push_back(i);
    }
    if (curr < next) {
      increases.push_back(i);
    } else if (curr > next) {
      decreases.push_back(i);
    }
  }
  return errors.empty() && (increases.size() == steps || decreases.size() == steps);
}
