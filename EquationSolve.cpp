#include <math.h>
#include <assert.h>

#include "constants.h"
#include "CompareDoubles.h"

int SolveSquare (double a, double b, double c, double* x1, double* x2)
    {
    assert (x1 != 0);
    assert (x2 != 0);
    assert (x1 != x2);

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

        if (Discriminant < 0)
            {
            return ZERO_ROOT;
            }

        if (CompareDoubles (Discriminant, 0))
            {
            *x1 = -b/(2*a);
            return ONE_ROOT;
            }

        if (Discriminant > 0) // безопасно ли такое сравнение?
            {
            *x1 = (-b - sqrt (Discriminant))/(2*a);
            *x2 = (-b + sqrt (Discriminant))/(2*a);
            return TWO_ROOTS;
            }

        }
    return ERROR;
    }
