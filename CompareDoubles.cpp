#include <math.h>

#include "constants.h"
#include "CompareDoubles.h"

bool CompareDoubles (double num1, double num2)
    {
    if (fabs (num1 - num2) < delta)
        {
        return 1;
        }
    return 0;
    }
