//file_utils.cpp
#include "file_utils.h"

#include <sys/stat.h>

bool exists(std::string &filename)
{
	struct stat buffer;   
	return (stat (filename.c_str(), &buffer) == 0); 
}

std::fstream createFile(std::string &filepath)
{
	if (exists(filepath)) {
		throw "hello, world.";
		// Throw an exception
	}

	std::fstream file;
	file.open(filepath, std::ios::out);
	return file;
}
