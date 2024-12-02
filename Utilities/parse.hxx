#pragma once
#include <string>
#include <vector>

template <class T> T parse(std::string name);

template <> std::string parse(std::string name);

template <> int parse(std::string name);

template <> std::pair<std::vector<int>, std::vector<int>> parse(std::string name);

template <> std::vector<std::vector<int>> parse(std::string name);