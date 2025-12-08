#include "pch.h"
#include "CppUnitTest.h"
#include "E:\Документи\навчання\Pr6.x\PR063\PR063RE\Pr6.3RE\Pr6.3RE.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63RE
{
	TEST_CLASS(UnitTest63RE)
	{
	public:
		
        TEST_METHOD(TestSumRecursive)
        {
            const int n = 10;

            int a[n] = { 1,2,3,4,5,6,7,8,9,10 };
            double b[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
            string c[n] = { "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10 " };

            int s1 = Sum(a, n);
            int s2 = Sum<int>(a, n);

            Assert::AreEqual(25, s1);
            Assert::AreEqual(25, s2);

            double s3 = Sum<double>(b, n);
            Assert::AreEqual(27.5, s3, 1e-9);

            string s4 = Sum<string>(c, n);
            string expected = "1 3 5 7 9 ";

            Assert::AreEqual(expected, s4);
        }
	};
}
