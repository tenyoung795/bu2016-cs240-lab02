#ifndef DYNAMICARRAYTESTSUITE_H
#define DYNAMICARRAYTESTSUITE_H
#include <TestSuite.h>
#include <Assert.h>
#include "DynamicArray.h"

class DynamicArrayTestSuite: public SequentialTestSuite<DynamicArray>
{
    public:
    DynamicArrayTestSuite();
};

#endif
