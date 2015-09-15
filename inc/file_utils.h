//file_utils.h

#include <fstream>
#include <string>

// Returns if a file exists with the given relative filepath
bool exists(std::string &filename);

// Creates a file with the given relative filepath and returns the fstream
std::fstream createFile(std::string &filepath);
