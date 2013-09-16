#include "DynamicArray.h"
#include <climits>
#include <cmath>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iostream>
#include <new>

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
    if (arrayCapacity == INT_MAX)
    {
        throw length_error("At max capacity " + to_string(INT_MAX));
    }

    if (arraySize == arrayCapacity)
    {
        int newCapacity = max(arrayCapacity * 2, INT_MAX);
        Element *newArr = nullptr;
        // if the doubling/INT_MAX policy doesn't work, we can narrow out the best interval via binary search
        // (a + b) / 2 = (2a + (b - a)) / 2 = a + (b - a) / 2
        for (; newArr != nullptr && newCapacity < arrayCapacity + 1;
            newCapacity -= newCapacity + (arrayCapacity + 1 - newCapacity) / 2)
        {
            newArr = new(nothrow) Element[newCapacity];
        }
        // if we can't grow by at least one, THEN we're screwed
        if (newArr == nullptr)
        {
            newCapacity = arrayCapacity + 1;
            newArr = new Element[newCapacity];
        }

        for (int i = 0; i < arraySize; i++)
        {
            newArr[i] = dynamicArray[i];
        }        
        delete[] dynamicArray;
        dynamicArray = newArr;
        arrayCapacity = newCapacity;
    }
    
    dynamicArray[arraySize] = e; // oldSize = newSize - 1
    arraySize++;
}

Element DynamicArray::pop_back()
{
    if (arraySize == 0)
    {
        throw out_of_range("Cannot pop from empty array");
    }
    
    int possiblyNewCapacity = arrayCapacity / 2;
    if (arraySize <= possiblyNewCapacity)   
    {
        auto newArr = new(nothrow) Element[possiblyNewCapacity];
        if (newArr != nullptr)
        {
            for (int i = 0; i < arraySize; i++)
            {
                newArr[i] = dynamicArray[i];
            }
            delete[] dynamicArray;
            dynamicArray = newArr;
            arrayCapacity = possiblyNewCapacity;
        }
    }
    
    arraySize--;
    return dynamicArray[arraySize]; // newSize = oldSize - 1
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

