#include <filesystem>
#include <fstream>
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

template <> std::vector<std::string> parse(std::string name) {
  return std::vector<std::string>();
}