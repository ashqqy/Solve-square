#include <math.h>

#include "Constants.h"
#include "CompareDoubles.h"

bool CompareDoubles (double num1, double num2)
    {
    if (fabs (num1 - num2) < DELTA)
        {
        return 1;
        }
    return 0;
    }
