//file_utils.h

#pragma once
#include <fstream>
#include <string>

// Returns if a file exists with the given relative filepath
bool exists(const std::string &filename);

// Creates a file with the given relative filepath and returns the fstream
std::fstream createFile(const std::string &filepath);
