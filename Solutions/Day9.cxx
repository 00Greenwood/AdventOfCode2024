#include "precompiled.hxx"

Day9::Day9() : Day(9) {
}

Day9::~Day9() {
}

void Day9::initialize() {
  parse(name(), m_input);
}

std::string Day9::solve(Part part) const {
  std::vector<int> layout;
  std::vector<std::vector<int>> partitions;
  for (int i = 0; i < m_input.size(); i++) {
    std::vector<int> partition;
    if (i % 2 == 0) {
      for (int j = 0; j < m_input.at(i); ++j) {
        layout.push_back(i / 2);
        partition.push_back(i / 2);
      }
    } else {
      for (int j = 0; j < m_input.at(i); ++j) {
        layout.push_back(-1);
        partition.push_back(-1);
      }
    }
    partitions.push_back(partition);
  }

  size_t total = 0;

  if (part == PART_1) {
    auto start = layout.begin();
    for (int i = layout.size() - 1; i >= 0; --i) {
      start = std::find(start, layout.end(), -1);
      if (start != layout.end() && i > (start - layout.begin())) {
        std::swap(layout.at(i), layout.at(start - layout.begin()));
      }
    }

    for (int i = 0; i < layout.size(); ++i) {
      if (layout.at(i) > 0) {
        total += i * layout.at(i);
      }
    }
  }

  if (part == PART_2) {
    auto start = partitions.begin();
    for (int i = partitions.size() - 1; i >= 0; --i) {
      std::vector<int>& file = partitions.at(i);
      if (file.empty() || file.at(0) == -1) {
        continue;
      }
      auto partitionMatcher = [&file](const std::vector<int>& partition) {
        return partition.size() >= file.size() && partition.at(0) == -1;
      };
      auto it = std::find_if(partitions.begin(), partitions.end(), partitionMatcher);
      if (it != partitions.end() && i > (it - partitions.begin())) {
        std::vector<int>& space = partitions.at(it - partitions.begin());
        if (file.size() == space.size()) {
          std::swap(file, space);
        } else {
          std::vector<int> difference;
          for (int j = file.size(); j < space.size(); ++j) {
            difference.push_back(-1);
          }
          space.resize(file.size());
          std::swap(file, space);
          partitions.insert(it + 1, difference);
          i++;
        }
      }
    }

    int index = 0;
    for (const auto& partition : partitions) {
      for (const auto& id : partition) {
        if (id > 0) {
          total += index * id;
        }
        ++index;
      }
    }
  }

  return std::to_string(total);
}
