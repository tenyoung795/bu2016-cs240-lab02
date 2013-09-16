#include "DynamicArray.h"
#include <climits>
#include <cmath>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

static Element *initArray(int size, Element e)
{
    if (size < 0) throw invalid_argument("Size " + to_string(size) + " cannot be negative");

    Element *arr = new Element[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = e;
    }
    return arr;
}

DynamicArray::DynamicArray(int size, Element e):
    dynamicArray(initArray(size, e)), arraySize(size), arrayCapacity(size) {}

DynamicArray::DynamicArray(): dynamicArray(nullptr), arraySize(0), arrayCapacity(0) {}

DynamicArray::~DynamicArray()
{
    delete[] dynamicArray;
}

void DynamicArray::push_back(Element e)
{
}

Element DynamicArray::pop_back()
{
	return NAN;
}

int DynamicArray::search(Element e)
{
	return -1;
}

bool DynamicArray::valid_index(int index)
{
	return false;
}

int DynamicArray::size()
{
	return arraySize;
}

int DynamicArray::capacity()
{
	return arrayCapacity;
}

