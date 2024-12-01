
#include <Day.hxx>

#include <filesystem>

Day::Day(int day) : m_name("Day" + std::to_string(day)) {
}

std::string Day::name() const {
  return m_name;
}
