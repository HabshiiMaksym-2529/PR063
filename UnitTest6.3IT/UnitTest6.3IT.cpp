#include "pch.h"
#include "CppUnitTest.h"
#include "E:\Документи\навчання\Pr6.x\PR063\PR063IT\Pr6.3IT\Pr6.3IT.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63IT
{
    TEST_CLASS(UnitTest63IT)
    {
    public:

        TEST_METHOD(TestSum)
        {
            const int n = 10;

            int a1[] = { 2, 3, -5, 8, 0, 11, -4 };
            Assert::AreEqual(3 + (-5) + 11, Sum(a1, (int)(sizeof(a1) / sizeof(a1[0]))));

        };
    };
}