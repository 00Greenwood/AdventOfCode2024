#include <Day16.hxx>
#include <PositionAndDirection.hxx>
#include <parse.hxx>

#include <queue>
#include <set>

#include <iostream>
#include <sstream>

Day16::Day16() : Day(16) {
}

Day16::~Day16() {
}

void Day16::initialize() {
  parse(name(), m_input);
  int y = -1;
  for (const auto& line : m_input) {
    y++;
    int x = -1;
    for (const auto& ch : line) {
      x++;
      switch (ch) {
      case '.':
        m_maze.emplace(Position(x, y), EMPTY);
        break;
      case '#':
        m_maze.emplace(Position(x, y), WALL);
        break;
      case 'S':
        m_maze.emplace(Position(x, y), START);
        m_start = Position(x, y);
        break;
      case 'E':
        m_maze.emplace(Position(x, y), END);
        m_end = Position(x, y);
        break;
      }
    }
  }
}

std::string Day16::solve(Part part) const {
  std::map<PositionAndDirection, int> scores;
  scores.emplace(PositionAndDirection(m_start, RIGHT), 0);

  {
    std::queue<PositionAndDirection> queue;
    queue.push(PositionAndDirection(m_start, RIGHT));

    auto move = [this, &scores, &queue](const Position& position, Direction direction, int score) {
      PositionAndDirection nextPad(position + DIRECTIONS[direction], direction);
      if (m_maze.at(nextPad.position) != WALL) {
        if (!scores.contains(nextPad)) {
          scores[nextPad] = score;
          queue.push(nextPad);
        } else if (score < scores.at(nextPad)) {
          scores[nextPad] = score;
          queue.push(nextPad);
        }
      }
    };

    // A* Algorithm
    while (!queue.empty()) {
      PositionAndDirection pad = queue.front();
      queue.pop();
      if (m_maze.at(pad.position) == END) {
        continue;
      }
      int score = scores.at(pad);
      { // Forward
        move(pad.position, pad.direction, score + 1);
      }
      { // Clockwise
        move(pad.position, turn90(pad.direction), score + 1001);
      }
      { // Counterclockwise
        move(pad.position, turn270(pad.direction), score + 1001);
      }
    }
  }

  std::set<int> endingScores;
  for (const auto& [pad, score] : scores) {
    if (pad.position == m_end) {
      endingScores.insert(score);
    }
  }
  int lowestScore = *endingScores.begin();

  if (part == PART_1) {
    return std::to_string(lowestScore);
  }

  std::set<Position> path;
  std::queue<PositionAndDirection> queue;
  auto it = std::find_if(scores.begin(), scores.end(), [this, &lowestScore](const auto& pair) {
    return pair.first.position == m_end && pair.second == lowestScore;
  });
  queue.push(it->first);

  while (!queue.empty()) {
    PositionAndDirection pad = queue.front();
    queue.pop();
    path.insert(pad.position);
    int score = scores.at(pad);
    for (const auto& direction : DIRECTIONS) {
      for (const auto& incomingDirection : DIRECTIONS) {
        PositionAndDirection nextPad(pad.position - direction, REVERSE_DIRECTIONS[incomingDirection]);
        if (scores.contains(nextPad) && (scores.at(nextPad) == score - 1 || scores.at(nextPad) == score - 1001)) {
          queue.push(nextPad);
        }
      }
    }
  }

  return std::to_string(path.size());
}
