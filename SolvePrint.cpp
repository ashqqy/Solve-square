#include <stdio.h>

#include "SolvePrint.h"
#include "constants.h"

int OutputSolveSquare (double x1, double x2, int numRoots)
    {
    switch (numRoots)
        {
        case ZERO_ROOT:
            printf ("\nThe quadratic equation has 0 root\n\n");
            return 0;

        case ONE_ROOT:
            printf ("\nThe quadratic equation has 1 root:\n"
                    "This root: %lf\n\n", x1);
            return 0;

        case TWO_ROOTS:
            printf ("\nThe quadratic equation has 2 roots:\n"
                    "First  root: %lf\n"
                    "Second root: %lf\n\n",
                    x1, x2);
            return 0;

        case INF_ROOTS:
            printf ("\nThe quadratic equation has infinite roots\n\n");
            return 0;

        default:
            printf ("Error\n\n");
            return 1;
        }
    }
