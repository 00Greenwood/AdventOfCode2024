#include <filesystem>
#include <fstream>
#include <regex>
#include <sstream>

#include <parse.hxx>

void parse(std::string name, std::string& output) {
  std::filesystem::path inputDir(INPUTS_DIR);
  std::filesystem::path filePath = inputDir / (name + ".txt");
  if (!std::filesystem::exists(filePath)) {
    throw std::runtime_error("File not found: " + filePath.string());
  }
  std::ifstream ifs(filePath);
  std::stringstream ss;
  ss << ifs.rdbuf();
  output = ss.str();
}

void parse(std::string name, int& output) {
  std::string input;
  parse(name, input);
  output = std::stoi(input);
}

void parse(std::string name, std::pair<std::vector<int>, std::vector<int>>& output) {
  std::string input;
  parse(name, input);
  std::regex numbersRegex("\\d+");
  auto it = std::sregex_iterator(input.begin(), input.end(), numbersRegex);
  while (it != std::sregex_iterator()) {
    output.first.push_back(std::stoi(it++->str()));
    output.second.push_back(std::stoi(it++->str()));
  }
}

void parse(std::string name, std::vector<std::vector<int>>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::regex numberRegex("\\d+");
  std::string line;
  while (std::getline(ss, line, '\n')) {
    std::vector<int> subOutput;
    auto it = std::sregex_iterator(line.begin(), line.end(), numberRegex);
    while (it != std::sregex_iterator()) {
      subOutput.push_back(std::stoi(it++->str()));
    }
    output.push_back(subOutput);
  }
}

void parse(std::string name, std::vector<int>& output) {
  std::string input;
  parse(name, input);
  for (const auto& ch : input) {
    output.push_back(ch - '0');
  }
}

void parse(std::string name, std::list<size_t>& output) {
  std::string input;
  parse(name, input);
  std::regex numberRegex("\\d+");
  auto it = std::sregex_iterator(input.begin(), input.end(), numberRegex);
  while (it != std::sregex_iterator()) {
    output.push_back(std::stoul(it++->str()));
  }
}

void parse(std::string name, std::vector<std::vector<size_t>>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::regex numberRegex("\\d+");
  std::string line;
  while (std::getline(ss, line, '\n')) {
    std::vector<size_t> subOutput;
    auto it = std::sregex_iterator(line.begin(), line.end(), numberRegex);
    while (it != std::sregex_iterator()) {
      subOutput.push_back(std::stoull(it++->str()));
    }
    output.push_back(subOutput);
  }
}

void parse(std::string name, std::vector<std::vector<char>>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::string line;
  while (std::getline(ss, line, '\n')) {
    std::vector<char> subOutput;
    for (const auto& ch : line) {
      subOutput.push_back(ch);
    }
    output.push_back(subOutput);
  }
}
