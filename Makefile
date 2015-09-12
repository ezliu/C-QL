GCC = g++
CXXFLAGS = -g -Wall -Wextra -std=c++11 -I${INCLUDE}
OBJECTS=./obj
INCLUDE=./inc

VPATH=${INCLUDE}

all: getObj Database putObj ctags

.PHONY: getObj
getObj:
	-mv ${OBJECTS}/*.[oa] . 2>/dev/null

.PHONY: putObj
putObj:
	-mv *.[oa] ${OBJECTS} 2>/dev/null

Database: database.o expression.o evaluation_context.o parser.o expression_factory.o tokenizer.o
	${GCC} ${CXXFLAGS} database.o expression.o evaluation_context.o parser.o expression_factory.o tokenizer.o -o Database

database.o: database.cpp
	${GCC} ${CXXFLAGS} database.cpp -c

expression.o: expression.cpp expression.h
	${GCC} ${CXXFLAGS} expression.cpp -c

expression_factory.o: expression_factory.h expression_factory.cpp
	${GCC} ${CXXFLAGS} expression_factory.cpp -c

evaluation_context.o: evaluation_context.cpp evaluation_context.h
	${GCC} ${CXXFLAGS} evaluation_context.cpp -c

parser.o: parser.cpp parser.h
	${GCC} ${CXXFLAGS} parser.cpp -c

tokenizer.o: tokenizer.cpp tokenizer.h
	${GCC} ${CXXFLAGS} tokenizer.cpp -c

ctags:
	ctags -R *
