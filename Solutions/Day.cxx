#include <Day.hxx>

#include <filesystem>
#include <iostream>
#include <sstream>

Day::Day(int day) : m_day(std::to_string(day)) {
}

Day::~Day() {
}

std::string Day::name() const {
  return "Day" + m_day;
}

void Day::wait() {
  return m_wait.wait();
}

void Day::solve(const std::shared_ptr<std::mutex>& mutex) {
  const auto run = [this, &mutex]() -> void {
    try {
      auto start = std::chrono::steady_clock::now();
      initialize();
      std::string solutionOne = solve(Day::PART_1);
      std::string solutionTwo = solve(Day::PART_2);
      auto duration =
          std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();

      std::lock_guard<std::mutex> lock(*mutex);
      std::cout << "Day " << m_day << ":";
      std::cout << "\n\tPart 1: " << solutionOne;
      std::cout << "\n\tPart 2: " << solutionTwo;
      std::cout << "\n\tTime: " << duration << "ms";
      std::cout << std::endl;
    } catch (const std::exception& e) {
      std::lock_guard<std::mutex> lock(*mutex);
      std::cerr << e.what() << std::endl;
    }
  };
  m_wait = std::async(std::launch::async, run);
}
