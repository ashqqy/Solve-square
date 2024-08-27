#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "./../include/Constants.h"
#include "./../include/SquareSolve.h"
#include "./../include/CompareDoubles.h"
#include "./../include/UnitTests.h"

//-----------------------------------------------------------------------------

int UnitTest (UnitData* unit_data)
    {
    assert (unit_data != 0);
    double x1 = 0, x2 = 0;
    int num_roots = SquareSolve ((*unit_data).a, (*unit_data).b, (*unit_data).c, &x1, &x2);

    if (CompareDoubles(x1, (*unit_data).x1_exp) == 0 || 
        CompareDoubles(x2, (*unit_data).x2_exp) == 0 || 
        CompareDoubles(num_roots, (*unit_data).num_roots_exp) == 0)
        {
        printf ("Error (Test %d):\n"
                "a = %lg, b = %lg, c = %lg,\n"
                "x1 = %lg, x2 = %lg, num_roots = %d\n"
                "Expected:\n"
                "x1 = %lg, x2 = %lg, num_roots = %d\n\n",
                (*unit_data).test_num, 
                (*unit_data).a, (*unit_data).b, (*unit_data).c, 
                x1, x2, num_roots, 
                (*unit_data).x1_exp, (*unit_data).x2_exp, (*unit_data).num_roots_exp);
        return 1;
        }
    return 0;
    }

//-----------------------------------------------------------------------------

void AllUnitTests ()
    {
                               //test num   a   b  c   x1  x2 num_roots
    UnitData unit_data[] = {{1,  0,  1, 1,  -1, 0, ONE_ROOT},  // a = 0
                            {2,  1,  0, -4, -2, 2, TWO_ROOTS}, // b = 0
                            {3,  1,  1, 0,  -1, 0, TWO_ROOTS}, // c = 0
                            {4,  0,  0, 1,  0,  0, ZERO_ROOT}, // a = b = 0
                            {5,  0,  1, 0,  0,  0, ONE_ROOT},  // a = c = 0
                            {6,  1,  0, 0,  0,  0, ONE_ROOT},  // b = c = 0
                            {7,  0,  0, 0,  0,  0, INF_ROOTS}, // a = b = c = 0
                            {8,  1,  2, -3, -3, 1, TWO_ROOTS}, // D > 0
                            {9,  1,  2, 1,  -1, 0, ONE_ROOT},  // D = 0
                            {10, 1,  1, 1,  0,  0, ZERO_ROOT}, // D < 0
                            {11, -1, 5, -4, 1,  4, TWO_ROOTS}, // a < 0
                    //test num   a    b     c      x1  x2 num_roots
                            {12, 6.6, 13.2, -19.8, -3, 1, TWO_ROOTS}}; // not int coefficients

    const int total_tests = sizeof(unit_data)/sizeof(unit_data[0]);
    
    int test_error_counter = 0;

    for (int i = 0; i < total_tests; i++)
        test_error_counter = UnitTest (&unit_data[i]);

    if (test_error_counter == 0)
        printf ("All tests are successful\n\n");
    else
        printf ("%d test(s) are unsuccessful\n\n", test_error_counter);
    }

//-----------------------------------------------------------------------------
