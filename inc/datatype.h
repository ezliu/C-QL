//datatype.h

#pragma once

#include <vector>

enum DataType {
	INT,
	FLOAT,
	DOUBLE,
	CHAR,
	STRING,
	BOOL
};

DataType stringToDatatype(const std::string &s);
