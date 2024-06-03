#include "CppUnitTest.h"
#include "Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{  
    TEST_CLASS(PointTests)
    {
    public:
        
        TEST_METHOD(TestGetX) 
        {
            Point p(3, 4);
            Assert::AreEqual(3, p.getX());
        }

        TEST_METHOD(TestGetY) 
        {
            Point p(3, 4);
            Assert::AreEqual(4, p.getY());
        }

        TEST_METHOD(TestDistanceToOrigin) 
        {
            Point p(3, 4);
            Assert::AreEqual(5.0, p.distanceToOrigin());
        }
    };
}