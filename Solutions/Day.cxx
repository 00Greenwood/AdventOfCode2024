#include <Day.hxx>

#include <filesystem>
#include <sstream>

Day::Day(int day) : m_day(std::to_string(day)) {
}

Day::~Day() {
}

std::string Day::name() const {
  return "Day" + m_day;
}

std::string Day::solution() {
  return m_solution.get();
}

void Day::solve() {
  const auto run = [this]() -> std::string {
    auto start = std::chrono::steady_clock::now();
    std::stringstream ss;
    ss << "Day " << m_day << ":";
    ss << "\n\tPart 1: " << solve(Day::PART_1);
    ss << "\n\tPart 2: " << solve(Day::PART_2);
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
    ss << "\n\tTime: " << duration << "ms";
    return ss.str();
  };
  m_solution = std::async(std::launch::async, run);
}
