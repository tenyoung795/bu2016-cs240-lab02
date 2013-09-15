#ifndef DYNAMICARRAYTESTSUITE_H
#define DYNAMICARRAYTESTSUITE_H
#include <TestSuite.h>
#include <Assert.h>
#include "DynamicArray.h"

class DynamicArrayTestSuite: public SequentialTestSuite<DynamicArray>
{
    public:
    static void testExplicitConstructor();
    static void testDefaultConstructor();
    static void testDestructor();
    DynamicArrayTestSuite();
};

#endif
