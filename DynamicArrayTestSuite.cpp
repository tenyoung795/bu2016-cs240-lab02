#include "DynamicArrayTestSuite.h"
#include "DynamicArray.h"
#include <TestSuite.h>
#include <Assert.h>
#include <string>

DynamicArrayTestSuite::DynamicArrayTestSuite(): SequentialTestSuite
({
    {"DELETEME", [](DynamicArray &arr)
	{
	}}
})
{
	// Test constructors first, starting with default
	DynamicArray defaultArr;
	assertEquals(int, 0, defaultArr.size());
	assertEquals(int, 0, defaultArr.capacity());

	try
	{
		auto invalidArr = DynamicArray(-1, 0);
		fail("Expected an invalid_argument exception for negative capacity");
	}
	// expected to catch exception
	catch (invalid_argument &ae) {}

	auto explicitlyEmpty = DynamicArray(0, 0);
	assertEquals(int, 0, explicitlyEmpty.size());
	assertEquals(int, 0, explicitlyEmpty.capacity());

	static constexpr int CAPACITY = 16;
	auto arr = DynamicArray(CAPACITY, 0);
	assertEquals(int, 0, arr.size());
	assertEquals(int, CAPACITY, arr.capacity());
}


