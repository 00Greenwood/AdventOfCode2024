#include <Day2.hxx>
#include <parse.hxx>

#include <algorithm>
#include <map>

Day2::Day2() : Day(2) {
}

Day2::~Day2() {
}

std::string Day2::solve(Part part) const {
  auto input = parse<std::vector<std::vector<int>>>(name());
  int safeReports = 0;
  for (const auto& report : input) {
    std::vector<int> errors;
    std::vector<int> increases;
    std::vector<int> decreases;
    for (int i = 0; i < report.size() - 1; ++i) {
      int curr = report.at(i);
      int next = report.at(i + 1);
      if ((std::abs(curr - next) > 3) || (std::abs(curr - next) < 1)) {
        errors.push_back(i);
      }
      if (curr < next) {
        increases.push_back(i);
      } else if (curr > next) {
        decreases.push_back(i);
      }
    }
    const bool monotone = (increases.size() == report.size() - 1) || (decreases.size() == report.size() - 1);
    if (errors.empty() && monotone) {
      safeReports++;
    } else if (part == PART_2 && errors.empty() && (increases.size() == 1)) {
      if (increases.at(0) != 0) {
        int prev = report.at(increases.at(0) - 1);
        int next = report.at(increases.at(0) + 1);
        if ((std::abs(next - prev) <= 3) && (std::abs(next - prev) >= 1)) {
          safeReports++;
        }
      }
    } else if (part == PART_2 && errors.empty() && (decreases.size() == 1)) {
      if (decreases.at(0) != 0) {
        int prev = report.at(decreases.at(0) - 1);
        int next = report.at(decreases.at(0) + 1);
        if ((std::abs(next - prev) <= 3) && (std::abs(next - prev) >= 1)) {
          safeReports++;
        }
      }

    } else if (part == PART_2 && errors.size() == 1 && monotone) {
      if (errors.at(0) != 0) {
        int prev = report.at(errors.at(0) - 1);
        int next = report.at(errors.at(0) + 1);
        if ((std::abs(next - prev) <= 3) && (std::abs(next - prev) >= 1)) {
          safeReports++;
        }
      }
    }
  }
  return std::to_string(safeReports);
}
