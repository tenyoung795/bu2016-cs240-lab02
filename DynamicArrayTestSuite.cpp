#include "DynamicArrayTestSuite.h"
#include "DynamicArray.h"
#include <TestSuite.h>
#include <Assert.h>
#include <string>

DynamicArrayTestSuite::DynamicArrayTestSuite(): ConcurrentTestSuite
({
    {"testDefaultConstructor", []()
	{
        DynamicArray defaultArr;
        assertEquals(int, 0, defaultArr.size());
        assertTrue(defaultArr.capacity() >= 0);
    }},

    {"testInvalidConstructorArgs", []()
    {
        try
        {
            DynamicArray(-1, 0);
            fail("Expected an invalid_argument exception for negative capacity");
        }
        // expected to catch exception
        catch (invalid_argument &ae) {}
    }},

    {"testExplicitConstructorEmpty", []()
    {
        static constexpr Element FILL = 1;
        auto explicitlyEmpty = DynamicArray(0, FILL);
        assertEquals(int, 0, explicitlyEmpty.size());
        assertTrue(explicitlyEmpty.capacity() >= 0);
        assertEquals(int, -1, explicitlyEmpty.search(FILL));
    }},

    {"testExplicitConstructor", []()
    {
        static constexpr Element FILL = 1;
        static constexpr int SIZE = 16;
        auto arr = DynamicArray(SIZE, FILL);
        assertEquals(int, SIZE, arr.size());
        assertTrue(arr.capacity() >= SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            assertEquals(int, 0, arr.search(FILL));
            arr.pop_back();
        }
    }},

    {"testMutation", []()
    {
        DynamicArray arr;
        try
        {
            arr.pop_back();
            fail("Expected an exception on popping from an empty array");
        }
        // expect out of range
        catch (out_of_range &e) {}

        static constexpr Element ELEMENT = 1;

        arr.push_back(ELEMENT);
        assertEquals(int, 1, arr.size());
        assertTrue(arr.capacity() >= 1);
        assertEquals(int, 0, arr.search(ELEMENT));
        
        assertEquals(float, ELEMENT, arr.pop_back());
        assertEquals(int, 0, arr.size());
        assertTrue(arr.capacity() >= 1);
        assertEquals(int, -1, arr.search(ELEMENT));
    }}
}) {}

