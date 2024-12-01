#include <filesystem>
#include <fstream>
#include <regex>
#include <sstream>

#include <parse.hxx>

template <> std::string parse(std::string name) {
  std::filesystem::path inputDir(INPUTS_DIR);
  std::ifstream ifs(inputDir / (name + ".txt"));
  std::stringstream ss;
  ss << ifs.rdbuf();
  return ss.str();
}

template <> int parse(std::string name) {
  return std::stoi(parse<std::string>(name));
}

template <> std::pair<std::vector<int>, std::vector<int>> parse(std::string name) {
  std::string input = parse<std::string>(name);
  std::regex numbersRegex("\\d+");
  auto it = std::sregex_iterator(input.begin(), input.end(), numbersRegex);
  std::pair<std::vector<int>, std::vector<int>> output;
  while (it != std::sregex_iterator()) {
    output.first.push_back(std::stoi(it++->str()));
    output.second.push_back(std::stoi(it++->str()));
  }
  return output;
}