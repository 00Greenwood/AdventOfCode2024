
#include <Day.h>

Day::Day(int day) : m_name("Day " + std::to_string(day))
{
    fetch_input(day);
}

std::string Day::name() const
{
    return m_name;
}

std::string Day::input() const
{
    return m_input;
}

void Day::fetch_input(int day)
{
    m_input = "";
}