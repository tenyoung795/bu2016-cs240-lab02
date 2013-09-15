#include "DynamicArray.h"
#include <climits>
#include <cmath>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

static int checkCapacity(int capacity)
{
    if (capacity < 0) throw invalid_argument("Capacity " + to_string(capacity) + " cannot be negative");
    return capacity;
}

DynamicArray::DynamicArray(int capacity, Element e):
    dynamicArray(new Element[checkCapacity(capacity)]), arraySize(0), arrayCapacity(capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        dynamicArray[i] = e;
    }
}

DynamicArray::DynamicArray(): dynamicArray(nullptr), arraySize(0), arrayCapacity(0) {}

DynamicArray::~DynamicArray()
{
    delete[] dynamicArray;
    dynamicArray = nullptr;
    arraySize = arrayCapacity = 0;
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

