//file_utils.cpp
#include "file_utils.h"

#include <sys/stat.h>

#include "exception.h"

bool exists(const std::string &filename)
{
	struct stat buffer;   
	return (stat (filename.c_str(), &buffer) == 0); 
}

std::fstream createFile(const std::string &filepath)
{
	if (exists(filepath)) {
		FileExistsException e("File of name: " + filepath + " already exists!");
		throw e;
		//throw "hello, world.";
		// Throw an exception
	}

	std::fstream file;
	file.open(filepath, std::ios::out);
	return file;
}

bool deleteFile(const std::string &filename)
{
	if (!exists(filename)) return false;
	std::string command = "rm " + filename;
	system(command.c_str());
	return true;
}
