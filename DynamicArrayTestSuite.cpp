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
        assertTrue(explicitlyEmpty.capacity() >= 0);
    }},

    {"testExplicitConstructor", []()
    {
        static constexpr int SIZE = 16;
        auto arr = DynamicArray(SIZE, 0);
        assertEquals(int, SIZE, arr.size());
        assertTrue(arr.capacity() >= SIZE);
    }}
}) {}


