GCC = g++
CXXFLAGS = -g -Wall -Wextra -std=c++11 -I${INCLUDE}
OBJECTS=./obj
INCLUDE=./inc
SRC=./src

VPATH=${INCLUDE}

all: getObj Database putObj ctags

.PHONY: getObj
getObj:
	-mv ${OBJECTS}/*.[oa] . 2>/dev/null

.PHONY: putObj
putObj:
	-mv *.[oa] ${OBJECTS} 2>/dev/null

Database: database.o expression.o evaluation_context.o parser.o expression_factory.o tokenizer.o exception.o file_utils.o
	${GCC} ${CXXFLAGS} database.o expression.o evaluation_context.o parser.o expression_factory.o tokenizer.o exception.o file_utils.o -o Database

database.o: $(SRC)/database.cpp
	${GCC} ${CXXFLAGS} $(SRC)/database.cpp -c

expression.o: $(SRC)/expression.cpp expression.h
	${GCC} ${CXXFLAGS} $(SRC)/expression.cpp -c

expression_factory.o: expression_factory.h $(SRC)/expression_factory.cpp
	${GCC} ${CXXFLAGS} $(SRC)/expression_factory.cpp -c

evaluation_context.o: $(SRC)/evaluation_context.cpp evaluation_context.h
	${GCC} ${CXXFLAGS} $(SRC)/evaluation_context.cpp -c

parser.o: $(SRC)/parser.cpp parser.h
	${GCC} ${CXXFLAGS} $(SRC)/parser.cpp -c

tokenizer.o: $(SRC)/tokenizer.cpp tokenizer.h
	${GCC} ${CXXFLAGS} $(SRC)/tokenizer.cpp -c

exception.o: $(SRC)/exception.cpp exception.h
	${GCC} ${CXXFLAGS} $(SRC)/exception.cpp -c

file_utils.o: $(SRC)/file_utils.cpp file_utils.h
	${GCC} ${CXXFLAGS} $(SRC)/file_utils.cpp -c

.PHONY: clean
clean: 
	-rm -vf Database
	-rm -vf ${OBJECTS}/*.[oa]

.PHONY: drop_tables
drop_tables:
	-rm -vf data/table/* data/schema/*

ctags:
	ctags -R *
