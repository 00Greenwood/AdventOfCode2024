#include <Day9.hxx>
#include <parse.hxx>

#include <deque>

Day9::Day9() : Day(9) {
}

Day9::~Day9() {
}

void Day9::initialize() {
  parse(name(), m_input);
}

std::string Day9::solve(Part part) const {
  std::deque<int> layout;
  for (int i = 0; i < m_input.size(); i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < m_input.at(i); ++j) {
        layout.push_back(i / 2);
      }
    } else {
      for (int j = 0; j < m_input.at(i); ++j) {
        layout.push_back(-1);
      }
    }
  }

  std::vector<int> reformattedLayout;
  while (layout.size() > 0) {
    if (layout.front() == -1) {
      layout.pop_front();
      while (layout.size() > 0 && layout.back() == -1) {
        layout.pop_back();
      }
      if (layout.size() > 0) {
        reformattedLayout.push_back(layout.back());
        layout.pop_back();
      }
    } else {
      reformattedLayout.push_back(layout.front());
      layout.pop_front();
    }
  }

  size_t total = 0;
  for (int i = 0; i < reformattedLayout.size(); ++i) {
    total += i * reformattedLayout.at(i);
  }
  return std::to_string(total);
}
