#!/usr/bin/make -f

CC = g++
STD = c++0x
OPTIONS = -std=$(STD) -Wall -g
LIBRARIES = -lassert
OBJECTS = Driver.o DynamicArray.o DynamicArrayTestSuite.o
OUTPUT = lab02

all: $(OBJECTS)
	$(CC) $(OPTIONS) -o $(OUTPUT) $(OBJECTS) $(LIBRARIES)

Driver.o: Driver.cpp DynamicArrayTestSuite.h
	$(CC) $(OPTIONS) -c Driver.cpp

DynamicArray.o: DynamicArray.cpp DynamicArray.h
	$(CC) $(OPTIONS) -c DynamicArray.cpp

DynamicArrayTestSuite.o: DynamicArrayTestSuite.cpp DynamicArrayTestSuite.h DynamicArray.h
	$(CC) $(OPTIONS) -c DynamicArrayTestSuite.cpp

clean:
	rm -f $(OBJECTS) $(OUTPUT) *.~ .*.swp

