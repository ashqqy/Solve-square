/** 
    @mainpage
    @brief <b> Решение квадратных уравнений </b>

    Автор Артём Шафеев\n 
    Летняя школа Ильи Дединского МФТИ
*/

//-----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h> //сравнение строк

#include "./../include/Constants.h"
#include "./../include/CheckOrSolve.h"
#include "./../include/SquareSolve.h"
#include "./../include/SolvePrint.h"
#include "./../include/ScanDoubles.h"
#include "./../include/CompareDoubles.h"
#include "./../include/UnitTests.h"
#include "./../include/CompareSTR.h"

//-----------------------------------------------------------------------------

int main(int argc, const char *argv[])
    {
    printf ("\nSolve Square Equation\n"
            "(by Shafeev Artiom)\n\n");

    double user_choice = 0;

    if (CompareSTR(argv[1], SOLVE_1) || CompareSTR(argv[1], SOLVE))
        user_choice = 1;
    if (CompareSTR(argv[1], CHECK_2) || CompareSTR(argv[1], CHECK))
        user_choice = 2;
    if (user_choice != 1 && user_choice != 2)
        CheckOrSolve (&user_choice);

    if (CompareDoubles (user_choice, USER_CHOICE_SOLVE))
        {
        double a = 0, b = 0, c = 0;

        printf ("Enter the coefficient a:\n");
        ScanDoubles (&a);
        printf ("Enter the coefficient b:\n");
        ScanDoubles (&b);
        printf ("Enter the coefficient c:\n");
        ScanDoubles (&c);

        double x1 = 0, x2 = 0;

        int num_roots = SquareSolve (a, b, c, &x1, &x2);
        SolvePrint (x1, x2, num_roots);
        }

    if (CompareDoubles (user_choice, USER_CHOICE_CHECK))
        {
        AllUnitTests ();
        }
    }

    // double input = 0;
    // ScanDouble (&input);
    // int user_choise = int(input);
    // int user_choise = (int) input; //переделать scandoubles
//-----------------------------------------------------------------------------