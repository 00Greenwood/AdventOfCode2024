#pragma once
#include <future>
#include <string>

// Bass class for the Days.
class Day {
public:
  explicit Day(int day);
  virtual ~Day();

  std::string name() const;

  // Wait for the solution to be ready..
  void wait();

  // Solve the day and store the solution in the promise.
  void solve(const std::shared_ptr<std::mutex>& mutex);

protected:
  enum Part { PART_1, PART_2 };

  // Called before solving both parts.
  virtual void initialize() = 0;

  // Solve the Day for a specific part.
  virtual std::string solve(Part) const = 0;

  std::string m_day;

  std::future<void> m_wait;
};
