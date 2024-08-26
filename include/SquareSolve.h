/**
    @file
    @brief Файл с функцией, решающей квадратное уравнение
*/

#ifndef EQUATION_SOLVE
#define EQUATION_SOLVE

/** @brief Функция, решающая квадратное уравнение
    @param[in] a Коэффициент перед x2
    @param[in] b Коэффициент перед x
    @param[in] c Коэффициент свободный
    @param[out] x1 Первый корень
    @param[out] x2 Второй корень
    @return Количество корней
*/
int SquareSolve (double a, double b, double c, double* x1, double* x2);

#endif //EQUATION_SOLVE
