#include <stdio.h>
#include <math.h>
#include <assert.h>

//-----------------------------------------------------------------------------

const int ZERO_ROOT = 0;
const int ONE_ROOT  = 1;
const int TWO_ROOTS = 2;
const int INF_ROOTS = -1;

const double delta  = 10e-8;

const double ERROR  = -100;

//-----------------------------------------------------------------------------

double CheckOrSolve ();

int SolveSquare (double a, double b, double c, double* x1, double* x2);
int OutputSolveSquare (double x1, double x2, int numRoots);

bool CompareDoubles (double num1, double num2);

void DoubleScan (double* coef);
void CleanBufer ();

int UnitTest (int numTest, double a, double b, double c, double x1Exp, double x2Exp, int numRootsExp);
void AllUnitTests ();

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

double CheckOrSolve ()
    {
    double choice = 0;
    printf ("What do you want?\n"
            "Solve the equation - enter 1\n"
            "Check the program  - enter 2\n"
            "Your choice - ");

    DoubleScan (&choice);
    printf ("\n");

    while (CompareDoubles(choice, 1) == 0 && CompareDoubles(choice, 2) == 0)
        {
        printf ("Try again: ");
        DoubleScan (&choice);
        }
    return choice;
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
        CleanBufer ();
        }
    }

//-----------------------------------------------------------------------------

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

        if (Discriminant > 0)
            {
            *x1 = (-b - sqrt (Discriminant))/(2*a);
            *x2 = (-b + sqrt (Discriminant))/(2*a);
            return TWO_ROOTS;
            }

        }
    return ERROR;
    }

//-----------------------------------------------------------------------------

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
//-----------------------------------------------------------------------------

int UnitTest (int numTest, double a, double b, double c, double x1Exp, double x2Exp, int numRootsExp)
    {
    double x1 = 0, x2 = 0;
    int numRoots = SolveSquare (a, b, c, &x1, &x2);

    if (CompareDoubles(x1, x1Exp) == 0 || CompareDoubles(x2, x2Exp) == 0  || CompareDoubles(numRoots, numRootsExp) == 0)
        {
        printf ("Error (Test %d):\n"
                "a = %lg, b = %lg, c = %lg,\n"
                "x1 = %lg, x2 = %lg, numRoots = %d\n"
                "Expected:\n"
                "x1 = %lg, x2 = %lg, numRoots = %d\n\n",
                numTest, a, b, c, x1, x2, numRoots, x1Exp, x2Exp, numRootsExp);
        return 1;
        }
    return 0;
    }

//-----------------------------------------------------------------------------

void AllUnitTests ()
    {
    int TestErrorCounter = 0;
    TestErrorCounter += UnitTest (1,  0,   1,    1,     -1, 0, ONE_ROOT);   // a = 0
    TestErrorCounter += UnitTest (2,  1,   0,    -4,    -2, 2, TWO_ROOTS);  // b = 0
    TestErrorCounter += UnitTest (3,  1,   1,    0,     -1, 0, TWO_ROOTS);  // c = 0

    TestErrorCounter += UnitTest (4,  0,   0,    1,     0,  0, ZERO_ROOT);  // a = 0, b = 0
    TestErrorCounter += UnitTest (5,  0,   1,    0,     0,  0, ONE_ROOT);   // a = 0, c = 0
    TestErrorCounter += UnitTest (6,  1,   0,    0,     0,  0, ONE_ROOT);   // b = 0, c = 0

    TestErrorCounter += UnitTest (7,  0,   0,    0,     0,  0, INF_ROOTS);  // a = 0, b = 0, c = 0

    TestErrorCounter += UnitTest (8,  1,   2,    -3,    -3, 1, TWO_ROOTS);  // D > 0
    TestErrorCounter += UnitTest (9,  1,   2,    1,     -1, 0, ONE_ROOT);   // D = 0
    TestErrorCounter += UnitTest (10, 1,   1,    1,     0,  0, ZERO_ROOT);  // D < 0

    TestErrorCounter += UnitTest (11, 6.6, 13.2, -19.8, -3, 1, TWO_ROOTS);  // not int coefficients

    if (TestErrorCounter == 0)
        {
        printf ("All tests are successful\n");
        }
    else
        {
        printf ("%d test(s) are unsuccessful\n", TestErrorCounter);
        }
    }

//-----------------------------------------------------------------------------

bool CompareDoubles (double num1, double num2)
    {
    if (fabs (num1 - num2) < delta)
        {
        return 1;
        }
    return 0;
    }

//-----------------------------------------------------------------------------

void CleanBufer ()
    {
    int LastSymb = 0;
    while ((LastSymb = getchar ()) != '\n' && LastSymb != EOF)
        {
        }
    }

//-----------------------------------------------------------------------------



