#pragma once
#include <list>
#include <string>
#include <vector>

void parse(std::string name, std::string&);

void parse(std::string name, int&);

void parse(std::string name, std::pair<std::vector<int>, std::vector<int>>&);

void parse(std::string name, std::vector<std::vector<int>>&);

void parse(std::string name, std::vector<int>&);

void parse(std::string name, std::list<size_t>&);

void parse(std::string name, std::vector<int64_t>&);

void parse(std::string name, std::vector<std::vector<size_t>>&);

void parse(std::string name, std::vector<std::vector<char>>&);

void parse(std::string name, std::vector<std::string>&);
