#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.1.rec/lb_7.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71rec
{
	TEST_CLASS(UnitTest71rec)
	{
    public:

        TEST_METHOD(TestMethod1)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int S = 0;
            int k = 0;
            int** q = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                q[i] = new int[colCount];

            q[0][0] = 1;
            q[0][1] = 2;
            q[0][2] = 3;
            q[1][0] = 4;
            q[1][1] = 5;
            q[1][2] = 6;
            q[2][0] = 7;
            q[2][1] = 8;
            q[2][2] = 9;

            Calculate(q, rowCount, colCount, S, k, 0, 0);


            Assert::AreEqual(40, S);
            Assert::AreEqual(8, k);


            for (int i = 0; i < rowCount; i++)
                delete[] q[i];
            delete[] q;
        }
    };
}
