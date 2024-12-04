#pragma once
#include <string>
#include <vector>

void parse(std::string name, std::string&);

void parse(std::string name, int&);

void parse(std::string name, std::pair<std::vector<int>, std::vector<int>>&);

void parse(std::string name, std::vector<std::vector<int>>&);

void parse(std::string name, std::vector<std::vector<char>>& output);