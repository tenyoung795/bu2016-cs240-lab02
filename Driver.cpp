#include "DynamicArrayTestSuite.h"
#include <cstdlib>

int main()
{
	DynamicArrayTestSuite::testExplicitConstructor();
	DynamicArrayTestSuite::testDefaultConstructor();
	DynamicArrayTestSuite::testDestructor();
	return DynamicArrayTestSuite{}()? EXIT_SUCCESS : EXIT_FAILURE;
}

