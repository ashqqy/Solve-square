#include <stdio.h>

#include "CheckOrSolve.h"
#include "CompareDoubles.h"
#include "ScanDoubles.h"

//-----------------------------------------------------------------------------

double CheckOrSolve ()
    {
    double choice = 0;
    printf ("What do you want?\n"
            "Solve the equation - enter 1\n"
            "Check the program  - enter 2\n"
            "Your choice - ");

    DoubleScan (&choice);
    printf ("\n");

    while (CompareDoubles(choice, 1) == 0 && CompareDoubles(choice, 2) == 0)
        {
        printf ("Try again: ");
        DoubleScan (&choice);
        }
    return choice;
    }

//-----------------------------------------------------------------------------
