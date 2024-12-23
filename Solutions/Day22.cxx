#include "precompiled.hxx"
#include <Day22.hxx>

Day22::Day22() : Day(22) {
}

Day22::~Day22() {
}

void Day22::initialize() {
  parse(name(), m_input);
}

std::string Day22::solve(Part part) const {
  std::map<size_t, size_t> secrets;
  for (const auto& secret : m_input) {
    secrets[secret] = secret;
  }

  std::unordered_map<std::string, size_t> totalOrders;

  for (auto& [key, secret] : secrets) {
    std::unordered_map<std::string, int> orders;
    std::deque<int> prices;
    for (size_t i = 0; i < 2000; i++) {
      secret = convert(secret);
      if (part == PART_2) {
        prices.push_back(secret % 10);
        // Only strore the last 5 prices and use them to create a key for the order.
        if (prices.size() == 5) {
          std::string order = hash(prices);
          if (!orders.contains(order)) {
            orders[order] = prices.back();
          }
          prices.pop_front();
        }
      }
    }

    for (const auto& [order, price] : orders) {
      totalOrders[order] += price;
    }
  }

  size_t total = 0;
  if (part == PART_1) {
    for (auto& [key, secret] : secrets) {
      total += secret;
    }
  } else {
    for (const auto& [order, price] : totalOrders) {
      total = std::max(total, price);
    }
  }

  return std::to_string(total);
}

size_t Day22::mix(size_t lhs, size_t rhs) const {
  return lhs ^ rhs;
}

size_t Day22::prune(size_t number) const {
  return number % 16777216;
}

size_t Day22::divide(size_t number, size_t divisor) const {
  size_t remainder = number % divisor;
  return (number - remainder) / divisor;
}

size_t Day22::convert(size_t number) const {
  number = prune(mix(number, number * 64));
  number = prune(mix(number, divide(number, 32)));
  return prune(mix(number, number * 2048));
}

std::string Day22::hash(const std::deque<int>& numbers) const {
  std::string output;
  std::optional<int> previous;
  for (const auto& number : numbers) {
    if (previous) {
      int change = (number - *previous);
      if (change < 0) {
        output += '-';
      }
      char ch = '0' + static_cast<char>(abs(change));
      output += ch;
    }
    previous = number;
  }
  return output;
}
