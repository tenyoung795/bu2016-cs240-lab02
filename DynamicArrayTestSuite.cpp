#include "DynamicArrayTestSuite.h"
#include "DynamicArray.h"
#include <TestSuite.h>
#include <MultiTest.h>
#include <Assert.h>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <ostream>

using namespace std;

template <class T, class Allocator>
ostream &operator<< (ostream &s, const vector<T, Allocator> &v)
{
    s << "[\n";
    auto iter = v.cbegin();
    auto end = v.cend();
    if (iter != end)
    {
        s << '\t' << *iter;
        for (iter++; iter != end; iter++)
        {
            s << ",\n\t" << *iter;
        }
    }
    return s << "\n]";
}

template <class K, class V, class Compare, class Allocator>
ostream &operator<< (ostream &s, const map<K, V, Compare, Allocator> &m)
{
    s << "{\n"; 
    auto iter = m.cbegin();
    auto end = m.cend();
    if (iter != end)
    {
        s << '\t' << iter->first << " : " << iter->second;
        for (iter++; iter != end; iter++)
        {
            s << ",\n\t" << iter->first << " : " << iter->second;
        }
    }
    return s << "\n}";
}

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
        DynamicArray explicitlyEmpty(0, FILL);
        assertEquals(int, 0, explicitlyEmpty.size());
        assertTrue(explicitlyEmpty.capacity() >= 0);
        assertEquals(int, -1, explicitlyEmpty.search(FILL));
    }},

    {"testExplicitConstructor", []()
    {
        static constexpr Element FILL = 1;
        static constexpr int SIZE = 16;
        DynamicArray arr(SIZE, FILL);
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
    }},

    {"testFoundSearch", ConcurrentMultiTest<vector<Element>, map<Element, int>>
    {
        [](const vector<Element> &testCase)
        {
            DynamicArray arr;
            for (Element e : testCase)
            {
                arr.push_back(e);
            }

            map<Element, int> results;
            for (Element e : testCase)
            {
                results[e] = arr.search(e);
            }
            return results;
        },
        {
            {{1}, {{1, 0}}},
            {{1, 1, 1}, {{1, 0}}},
            {{1, 0, 0}, {{0, 1}, {1, 0}}},
            {{0, 1, 0}, {{0, 0}, {1, 1}}},
            {{0, 0, 1}, {{0, 0}, {1, 2}}}
        }
    }},

    {"testFailedSearch", []()
    {
        for (auto &testCase : vector<vector<float>>
        {
            {},
            {1},
            {1, 1},
            {1, 1, 1}
        })
        {
            DynamicArray arr;
            for (auto el : testCase)
            {
                arr.push_back(el);
            }
            assertEquals(int, -1, arr.search(0));
        }
    }},

    {"testValidIndex", []()
    {
        DynamicArray emptyArr;
        assertFalse(emptyArr.valid_index(-1));
        assertFalse(emptyArr.valid_index(0));

        DynamicArray singletonArr(1, 0);
        assertTrue(singletonArr.valid_index(0));
        assertFalse(singletonArr.valid_index(1));

        static constexpr int SIZE = 16;
        DynamicArray arr(SIZE, 0);
        for (int i = 0; i < SIZE; i++)
        {
            assertTrue(arr.valid_index(i));
        }
        assertFalse(arr.valid_index(SIZE));
    }}
    
    
}) {}

