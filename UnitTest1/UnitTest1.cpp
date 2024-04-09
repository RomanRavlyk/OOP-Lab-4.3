#include "pch.h"
#include "CppUnitTest.h"
#include "..//OOP Lab 4.3/Array.h"
#include "..//OOP Lab 4.3/Array.cpp"
#include "..//OOP Lab 4.3/Bit String.h"
#include "..//OOP Lab 4.3/BitString.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			{
				BitString str;
				str.setSize(19);
				Assert::AreEqual(19, str.getSize());
			}
		}
	};
}
