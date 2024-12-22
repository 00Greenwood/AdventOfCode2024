#include "precompiled.hxx"
#include <Day21.hxx>

Day21::Day21() : Day(21) {
}

Day21::~Day21() {
}

void Day21::initialize() {
  parse(name(), m_input);
  // +---+---+---+
  // | 7 | 8 | 9 |
  // +---+---+---+
  // | 4 | 5 | 6 |
  // +---+---+---+
  // | 1 | 2 | 3 |
  // +---+---+---+
  //     | 0 | A |
  //     +---+---+
  m_numberKeypad['7'] = Position(0, 0);
  m_numberKeypad['8'] = Position(1, 0);
  m_numberKeypad['9'] = Position(2, 0);
  m_numberKeypad['4'] = Position(0, 1);
  m_numberKeypad['5'] = Position(1, 1);
  m_numberKeypad['6'] = Position(2, 1);
  m_numberKeypad['1'] = Position(0, 2);
  m_numberKeypad['2'] = Position(1, 2);
  m_numberKeypad['3'] = Position(2, 2);
  m_numberKeypad['0'] = Position(1, 3);
  m_numberKeypad['A'] = Position(2, 3);

  //     +---+---+
  //     | ^ | A |
  // +---+---+---+
  // | < | v | > |
  // +---+---+---+
  m_directionKeypad['^'] = Position(1, 0);
  m_directionKeypad['A'] = Position(2, 0);
  m_directionKeypad['<'] = Position(0, 1);
  m_directionKeypad['v'] = Position(1, 1);
  m_directionKeypad['>'] = Position(2, 1);
}

std::string Day21::solve(Part) const {
  // std::map<std::string, std::string> outputs;
  // for (const auto& input : m_input) {
  //   outputs[input] = input;
  // }

  // Cache cache;

  // size_t robots = part == PART_1 ? 1 : 1;

  // for (const auto& input : m_input) {
  //   for (int i = 0; i < robots; i++) {
  //     outputs[input] = move('A' + outputs[input], cache);
  //   }
  // }

  size_t total = 0;
  // for (const auto& [input, moves] : outputs) {
  //   std::string number = input.substr(0, input.size() - 1);
  //   size_t length = moves.size();
  //   total += length * std::stoi(number);
  // }

  return std::to_string(total);
}

std::string Day21::move(const std::string& input, Cache& cache) const {
  if (cache.contains(input)) {
    return cache.at(input);
  }

  std::string output;

  if (input.size() == 2) {
    output = move(input[0], input[1]);
  } else {
    std::string first = input.substr(0, 2);
    std::string second = input.substr(1);
    output = move(first, cache) + move(second, cache);
  }

  cache.insert_or_assign(input, output);
  return cache.at(input);
}

std::string Day21::move(char start, char end) const {
  if (start == end) {
    return "A";
  }
  std::map<char, Position> keypad = m_numberKeypad;
  if (start == '<' || end == '<' || start == '^' || end == '^' || start == '>' || end == '>' || start == 'v' ||
      end == 'v') {
    keypad = m_directionKeypad;
  }
  Position difference = keypad.at(end) - keypad.at(start);

  std::string movement;
  if (difference.y > 0) {
    movement.append(difference.y, 'v');
  } else if (difference.y < 0) {
    movement.append(-difference.y, '^');
  }
  if (difference.x > 0) {
    movement.append(difference.x, '>');
  } else if (difference.x < 0) {
    movement.append(-difference.x, '<');
  }

  auto countTurns = [](const std::string& movement) -> size_t {
    size_t turns = 0;
    for (size_t i = 0; i < movement.size() - 1; i++) {
      if (movement[i] != movement[i + 1]) {
        turns++;
      }
    }
    return turns;
  };

  auto isValidMove = [](const std::string& move, const std::map<char, Position>& keypad, Position position) -> bool {
    for (const auto& direction : move) {
      if (direction == '>') {
        position.x++;
      } else if (direction == '<') {
        position.x--;
      } else if (direction == 'v') {
        position.y++;
      } else if (direction == '^') {
        position.y--;
      }
      auto it =
          std::find_if(keypad.begin(), keypad.end(), [&position](const auto& pair) { return pair.second == position; });
      if (it == keypad.end()) {
        return false;
      }
    }
    return true;
  };

  std::set<std::string> outputs;
  size_t leastTurns = std::numeric_limits<size_t>::max();
  // Find all possible solutions.
  std::sort(movement.begin(), movement.end());
  do {
    Position position = keypad.at(start);
    if (isValidMove(movement, keypad, position)) {
      if (countTurns(movement) <= leastTurns) {
        if (countTurns(movement) < leastTurns) {
          outputs.clear();
        }
        leastTurns = countTurns(movement);
        outputs.insert(movement + 'A');
      }
    }
  } while (std::next_permutation(movement.begin(), movement.end()));

  return *outputs.begin();
}
