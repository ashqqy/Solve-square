#include <stdio.h>
#include <assert.h>

#include "./../include/Constants.h"
#include "./../include/CheckOrSolve.h"
#include "./../include/CompareDoubles.h"
#include "./../include/ScanDoubles.h"

//-----------------------------------------------------------------------------

void CheckOrSolve (double* user_choice)
    {
    assert (user_choice != 0);
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
