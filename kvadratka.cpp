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

int SolveSquare (double a, double b, double c, double* x1, double* x2);
bool CampareWithZero (double num);
void CleanBufer ();
void scan (double* a, double* b, double* c);

//-----------------------------------------------------------------------------

int main()
{
    printf ("Solve Square Equation by Shafeev Artiom\n\n");

    double a = 0, b = 0, c = 0;

    printf ("Enter the coefficients (a b c):\n");
    scan (&a, &b, &c);

    double x1 = 0, x2 = 0;

    int nRoots = SolveSquare (a, b, c, &x1, &x2);

    switch (nRoots)
    {
        case ZERO_ROOT:
            printf ("0 root\n");
            break;

        case ONE_ROOT:
            printf ("1 root: %lf\n", x1);
            break;

        case TWO_ROOTS:
            printf ("2 roots: %lf %lf\n", x1, x2);
            break;

        case INF_ROOTS:
            printf ("Infinite roots\n");
            break;

        default:
            printf ("Warning\n");
            break;
    }
}

//-----------------------------------------------------------------------------

int SolveSquare (double a, double b, double c, double* x1, double* x2)
    {
    assert (x1 != 0);
    assert (x2 != 0);
    assert (x1 != x2);

    if (CampareWithZero (a) && CampareWithZero (b) && CampareWithZero (c))
    {
        return INF_ROOTS;
    }
    if (CampareWithZero (a) && CampareWithZero (b))
    {
        return ZERO_ROOT;
    }
    if (CampareWithZero (a))
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }

    if (CampareWithZero (a) == 0)
    {
        double Discriminant = b*b - 4*a*c;

        if (Discriminant < 0)
        {
            return ZERO_ROOT;
        }

        if (CampareWithZero (Discriminant))
        {
            *x1 = (-b + sqrt (Discriminant))/(2*a);
            return ONE_ROOT;
        }

        if (Discriminant > 0)
        {
            *x1 = (-b + sqrt (Discriminant))/(2*a);
            *x2 = (-b - sqrt (Discriminant))/(2*a);
            return TWO_ROOTS;
        }

    }
        return ERROR;
    }

//-----------------------------------------------------------------------------

bool CampareWithZero (double num)
{
    if (fabs (num) < delta)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//-----------------------------------------------------------------------------

void CleanBufer ()
{
    while (getchar() != '\n')
    {
    }
}

//-----------------------------------------------------------------------------

void scan (double* a, double* b, double* c)
{
    int NofSuccessfulCoef = scanf ("%lf %lf %lf", a, b, c);
    CleanBufer ();

    if (NofSuccessfulCoef != 3)
    {
        while (NofSuccessfulCoef != 3)
        {
            printf ("Try again:\n");
            NofSuccessfulCoef = scanf ("%lf %lf %lf", a, b, c);
            CleanBufer ();
        }
    }
}


// сделать структуры
// сделать свою функцию ввода (очистка буфера+проверка сканфа)
