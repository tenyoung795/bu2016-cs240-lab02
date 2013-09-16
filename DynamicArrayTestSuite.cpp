#include "DynamicArrayTestSuite.h"
#include "DynamicArray.h"
#include <TestSuite.h>
#include <Assert.h>
#include <string>

DynamicArrayTestSuite::DynamicArrayTestSuite(): SequentialTestSuite
({
    {"testDefaultConstructor", []()
	{
        DynamicArray defaultArr;
        assertEquals(int, 0, defaultArr.size());
        assertEquals(int, 0, defaultArr.capacity());
    }},

    {"testInvalidConstructorArgs", []()
    {
        try
        {
            auto invalidArr = DynamicArray(-1, 0);
            fail("Expected an invalid_argument exception for negative capacity");
        }
        // expected to catch exception
        catch (invalid_argument &ae) {}
    }},

    {"testExplicitConstructorEmpty", []()
    {
        auto explicitlyEmpty = DynamicArray(0, 0);
        assertEquals(int, 0, explicitlyEmpty.size());
        assertEquals(int, 0, explicitlyEmpty.capacity());
    }},

    {"testExplicitConstructor", []()
    {
        static constexpr int CAPACITY = 16;
        auto arr = DynamicArray(CAPACITY, 0);
        assertEquals(int, 0, arr.size());
        assertEquals(int, CAPACITY, arr.capacity());
    }}
}) {}


