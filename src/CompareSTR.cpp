#include <stdio.h>

#include "./../include/CompareSTR.h"

//-----------------------------------------------------------------------------

int CompareSTR (const char* str1, const char* str2)
    {
    if (str1 == NULL || str2 == NULL)
        return 0;
    int i = 0;
    while (str1[i] != 0)
        {
        if (str1[i] != str2 [i])
            {
            return 0; //числа не равны
            }
        i += 1;
        }
    return 1; //числа равны
    }

//-----------------------------------------------------------------------------