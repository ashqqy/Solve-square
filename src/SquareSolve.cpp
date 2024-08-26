#include <math.h>
#include <assert.h>
#include <stdio.h>

#include "./../include/Constants.h"
#include "./../include/CompareDoubles.h"

int SquareSolve (double a, double b, double c, double* x1, double* x2)
    {
    assert (x1 != 0);
    assert (x2 != 0);
    assert (x1 != x2);
    if (a == INFINITY || a == NAN)
        {
        printf ("Invalid value of argument a: %lg\n", a);
        return INVALID_VALUE_ERROR;
        }
    if (b == INFINITY || b == NAN)
        {
        printf ("Invalid value of argument b: %lg\n", b);
        return INVALID_VALUE_ERROR;
        }
    if (c == INFINITY || c == NAN)
        {
        printf ("Invalid value of argument c: %lg\n", c);
        return INVALID_VALUE_ERROR;
        }

    if (CompareDoubles (a, 0) && CompareDoubles (b, 0) && CompareDoubles (c, 0))
        {
        return INF_ROOTS;
        }
    if (CompareDoubles (a, 0) && CompareDoubles (b, 0))
        {
        return ZERO_ROOT;
        }
    if (CompareDoubles (a, 0))
        {
        *x1 = -c / b;
        return ONE_ROOT;
        }

    if (CompareDoubles (a, 0) == 0)
        {
        double Discriminant = b*b - 4*a*c;

        if (Discriminant < -DELTA)
            {
            return ZERO_ROOT;
            }

        if (CompareDoubles (Discriminant, 0))
            {
            *x1 = -b/(2*a);
            return ONE_ROOT;
            }

        if (Discriminant > DELTA)
            {
            if (a > 0) //упорядочивание корней по возрастанию
                {
                *x1 = (-b - sqrt (Discriminant))/(2*a);
                *x2 = (-b + sqrt (Discriminant))/(2*a);
                }
            else
                {
                *x1 = (-b + sqrt (Discriminant))/(2*a);
                *x2 = (-b - sqrt (Discriminant))/(2*a);
                }

            return TWO_ROOTS;
            }
        }
    return SQUARE_SOLVE_ERROR;
    }
