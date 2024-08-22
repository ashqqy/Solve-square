#include <stdio.h>

#include "Constants.h"
#include "CheckOrSolve.h"
#include "CompareDoubles.h"
#include "ScanDoubles.h"

//-----------------------------------------------------------------------------

void CheckOrSolve (double* user_choice)
    {
    printf ("What do you want?\n"
            "Solve the equation: enter 1\n"
            "Check the program: enter 2\n"
            "Your choice: ");

    ScanDoubles (user_choice);
    printf ("\n");

    while (CompareDoubles(*user_choice, USER_CHOICE_SOLVE) == 0 && CompareDoubles(*user_choice, USER_CHOICE_CHECK) == 0)
        {
        printf ("Try again: ");
        ScanDoubles (user_choice);
        }
    }

//-----------------------------------------------------------------------------
