#include <stdio.h>
#include <assert.h>

#include "./../include/ScanDoubles.h"

//-----------------------------------------------------------------------------

void CleanBufer ()
    {
    int last_symb = 0;
    while ((last_symb = getchar ()) != '\n' && last_symb != EOF)
        {
        }
    }

//-----------------------------------------------------------------------------

void ScanDoubles (double* coef)
    {
    assert (coef != 0);
    int num_good_coef = 0;
    int last_symb = 0;

    while ((num_good_coef = scanf ("%lf", coef)) != 1 || ((last_symb = getchar()) != '\n' && last_symb != EOF))
        {
        assert (num_good_coef != EOF);
        printf ("Try again: ");
        CleanBufer ();
        }
    }

//-----------------------------------------------------------------------------
