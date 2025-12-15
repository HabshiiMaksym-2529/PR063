#include "pch.h"
#include "CppUnitTest.h"
#include "E:\Документи\навчання\Pr6.x\PR063\PR063RE\Pr6.3RE\Pr6.3RE.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63RE
{
	TEST_CLASS(UnitTest63RE)
	{
	public:
		
        TEST_METHOD(TestSum)
        {
			int a1[] = { 2, 3, -5, 8, 0, 11, -4 };
			Assert::AreEqual(3 + (-5) + 11, Sum(a1, (int)(sizeof(a1) / sizeof(a1[0])), 0));
        }
	};
}
