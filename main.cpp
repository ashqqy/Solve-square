#include <stdio.h>

#include "Constants.h"
#include "CheckOrSolve.h"
#include "SquareSolve.h"
#include "SolvePrint.h"
#include "ScanDoubles.h"
#include "CompareDoubles.h"
#include "UnitTests.h"


//-----------------------------------------------------------------------------

int main()
    {
    printf ("\nSolve Square Equation\n"
            "(by Shafeev Artiom)\n\n");

    double user_choice = 0;
    CheckOrSolve (&user_choice);

    if (CompareDoubles (user_choice, USER_CHOICE_SOLVE))
        {
        double a = 0, b = 0, c = 0;

        printf ("Enter the coefficient a:\n");
        ScanDoubles (&a);
        printf ("Enter the coefficient b:\n");
        ScanDoubles (&b);
        printf ("Enter the coefficient c:\n");
        ScanDoubles (&c);

        double x1 = 0, x2 = 0;

        int num_roots = SquareSolve (a, b, c, &x1, &x2);
        SolvePrint (x1, x2, num_roots);
        }

    if (CompareDoubles (user_choice, USER_CHOICE_CHECK))
        {
        AllUnitTests ();
        }
    }

//-----------------------------------------------------------------------------

