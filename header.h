#pragma once
#include <string>
#include <unordered_map>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

string ToLower(string str);
void ScanFiles(fs::path Path ,unordered_map<string ,string >& files);
void SerchFunction(unordered_map<string ,string >& files,string Target);
