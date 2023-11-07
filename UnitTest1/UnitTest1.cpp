#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.4.2/Lab_06_4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMin)
        {
            int a[] = { -2, 109, -88, 4, 5, 34 };
            int n = 6;

            int result = Min(a, n);
            int expected = -2;

            Assert::AreEqual(expected, result);
        }
    };
}