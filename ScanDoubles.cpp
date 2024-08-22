#include <stdio.h>
#include <assert.h>

#include "ScanDoubles.h"

//-----------------------------------------------------------------------------

void CleanBufer ()
    {
    int LastSymb = 0;
    while ((LastSymb = getchar ()) != '\n' && LastSymb != EOF)
        {
        }
    }

//-----------------------------------------------------------------------------

void DoubleScan (double* coef)
    {
    int NofSuccessfulCoef = scanf ("%lf", coef);
    assert (NofSuccessfulCoef != EOF);
    CleanBufer ();

    while (NofSuccessfulCoef != 1)
        {
        printf ("Try again: ");
        NofSuccessfulCoef = scanf ("%lf", coef);
        assert (NofSuccessfulCoef != EOF);
        CleanBufer ();
        }
    }

//-----------------------------------------------------------------------------
