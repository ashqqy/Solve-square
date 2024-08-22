#include <stdio.h>

#include "constants.h"
#include "EquationSolve.h"
#include "CompareDoubles.h"
#include "UnitTests.h"

//-----------------------------------------------------------------------------

int UnitTest (int numTest, double a, double b, double c, double x1Exp, double x2Exp, int numRootsExp)
    {
    double x1 = 0, x2 = 0;
    int numRoots = SolveSquare (a, b, c, &x1, &x2);

    if (CompareDoubles(x1, x1Exp) == 0 || CompareDoubles(x2, x2Exp) == 0  || CompareDoubles(numRoots, numRootsExp) == 0)
        {
        printf ("Error (Test %d):\n"
                "a = %lg, b = %lg, c = %lg,\n"
                "x1 = %lg, x2 = %lg, numRoots = %d\n"
                "Expected:\n"
                "x1 = %lg, x2 = %lg, numRoots = %d\n\n",
                numTest, a, b, c, x1, x2, numRoots, x1Exp, x2Exp, numRootsExp);
        return 1;
        }
    return 0;
    }

//-----------------------------------------------------------------------------

void AllUnitTests ()
    {
    int TestErrorCounter = 0;
    TestErrorCounter += UnitTest (1,  0,   1,    1,     -1, 0, ONE_ROOT);   // a = 0
    TestErrorCounter += UnitTest (2,  1,   0,    -4,    -2, 2, TWO_ROOTS);  // b = 0
    TestErrorCounter += UnitTest (3,  1,   1,    0,     -1, 0, TWO_ROOTS);  // c = 0

    TestErrorCounter += UnitTest (4,  0,   0,    1,     0,  0, ZERO_ROOT);  // a = 0, b = 0
    TestErrorCounter += UnitTest (5,  0,   1,    0,     0,  0, ONE_ROOT);   // a = 0, c = 0
    TestErrorCounter += UnitTest (6,  1,   0,    0,     0,  0, ONE_ROOT);   // b = 0, c = 0

    TestErrorCounter += UnitTest (7,  0,   0,    0,     0,  0, INF_ROOTS);  // a = 0, b = 0, c = 0

    TestErrorCounter += UnitTest (8,  1,   2,    -3,    -3, 1, TWO_ROOTS);  // D > 0
    TestErrorCounter += UnitTest (9,  1,   2,    1,     -1, 0, ONE_ROOT);   // D = 0
    TestErrorCounter += UnitTest (10, 1,   1,    1,     0,  0, ZERO_ROOT);  // D < 0

    TestErrorCounter += UnitTest (11, 6.6, 13.2, -19.8, -3, 1, TWO_ROOTS);  // not int coefficients

    if (TestErrorCounter == 0)
        {
        printf ("All tests are successful\n");
        }
    else
        {
        printf ("%d test(s) are unsuccessful\n", TestErrorCounter);
        }
    }

//-----------------------------------------------------------------------------
