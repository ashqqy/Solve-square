#include <stdio.h>

#include "constants.h"
#include "UnitTests.h"
#include "EquationSolve.h"
#include "SolvePrint.h"
#include "ScanDoubles.h"
#include "CompareDoubles.h"
#include "CheckOrSolve.h"

//-----------------------------------------------------------------------------

// CONSTANTS

//-----------------------------------------------------------------------------

//double CheckOrSolve ();

//int SolveSquare (double a, double b, double c, double* x1, double* x2);
//int OutputSolveSquare (double x1, double x2, int numRoots);

//bool CompareDoubles (double num1, double num2);

//void DoubleScan (double* coef);
//void CleanBufer ();

//int UnitTest (int numTest, double a, double b, double c, double x1Exp, double x2Exp, int numRootsExp);
//void AllUnitTests ();

//-----------------------------------------------------------------------------

int main()
    {
    printf ("Solve Square Equation\n"
            "(by Shafeev Artiom)\n\n");

    double userChoice = CheckOrSolve ();

    if (CompareDoubles (userChoice, 1))
        {
        double a = 0, b = 0, c = 0;

        printf ("Enter the coefficient a:\n");
        DoubleScan (&a);
        printf ("Enter the coefficient b:\n");
        DoubleScan (&b);
        printf ("Enter the coefficient c:\n");
        DoubleScan (&c);

        double x1 = 0, x2 = 0;
        int numRoots = SolveSquare (a, b, c, &x1, &x2);
        OutputSolveSquare (x1, x2, numRoots);
        }

    if (CompareDoubles (userChoice, 2))
        {
        AllUnitTests ();
        }
    }

//-----------------------------------------------------------------------------

//Check or Solve

//-----------------------------------------------------------------------------

// Double Scan
// CleanBufer

//-----------------------------------------------------------------------------

// EquationSolve

//-----------------------------------------------------------------------------

// OutputSolveSquare

//-----------------------------------------------------------------------------

// UNIT TESTS

//-----------------------------------------------------------------------------

// CompareDoubles

//-----------------------------------------------------------------------------


//ЗАДАЧИ
// сделать структуры
// вторым аргументом DoubleScan'a сделать печатаемый текст
// пофиксить ошибку в DoubleScan'e (хавает 12h как 12)
// сделать вывод в юнит тестах лучше
// Разделить по файлам

//ФИШКИ
// ctrl+shift+u все развернуть

// ИЗМЕНЕНИЯ
// разделил по файлам


