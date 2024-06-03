#include "CppUnitTest.h"
#include "Circle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(CircleTests)
    {
    public:
        
        TEST_METHOD(TestGetRadius) 
        {
            Circle c(5);
            Assert::AreEqual(5.0, c.getRadius());
        }

        TEST_METHOD(TestSetRadius) 
        {
            Circle c(5);
            c.setRadius(10);
            Assert::AreEqual(10.0, c.getRadius());
        }

        TEST_METHOD(TestArea) 
        {
            Circle c(5);
            Assert::AreEqual(78.54, c.area(), 0.01); 
        }

        TEST_METHOD(TestCircumference) 
        {
            Circle c(5);
            Assert::AreEqual(31.42, c.circumference(), 0.01);
        }
    };
}