#include <string>
#include <vector>

template <class T> T parse(std::string name);

template <> std::string parse(std::string name);

template <> int parse(std::string name);

template <> std::vector<std::string> parse(std::string name);