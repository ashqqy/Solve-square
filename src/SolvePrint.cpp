#include <stdio.h>

#include "./../include/SolvePrint.h"
#include "./../include/Constants.h"

int SolvePrint (double x1, double x2, int num_roots)
    {
    switch (num_roots)
        {
        case ZERO_ROOT:
            printf ("\nThe quadratic equation has 0 root\n\n");
            break;

        case ONE_ROOT:
            printf ("\nThe quadratic equation has 1 root:\n"
                    "This root: %lf\n\n", x1);
            break;

        case TWO_ROOTS:
            printf ("\nThe quadratic equation has 2 roots:\n"
                    "First  root: %lf\n"
                    "Second root: %lf\n\n",
                    x1, x2);
            break;

        case INF_ROOTS:
            printf ("\nThe quadratic equation has infinite roots\n\n");
            break;

        default:
            printf ("SOLVE_PRINT_ERROR\n");
            return SOLVE_PRINT_ERROR;
        }
    return 0;
    }
