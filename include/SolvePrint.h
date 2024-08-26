/**
    @file
    @brief Файл с функцией, выводящей ответ на квадратное уравнение
*/

#ifndef EQUATION_SOLVE_PRINT
#define EQUATION_SOLVE_PRINT

/** @brief Функция вывода количества решений и корней уравнения
    @warning Перед использованием необходимо решить квадратное уравнение, используя функцию SquareSolve
    @param[in] x1 Первый корень
    @param[in] x2 Второй корень
    @param[in] num_roots Количество корней
*/
int SolvePrint (double x1, double x2, int num_roots);

#endif //EQUATION_SOLVE_PRINT
