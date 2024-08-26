/**
    @file
    @brief Файл с функцией тестирования
*/

#ifndef UNIT_TESTS
#define UNIT_TESTS

/// @brief Структура с данными для unit-теста
struct UnitData 
    {
    /// @brief Номер теста
    int test_num; 
    /// @brief Коэффициент уравнения a
    double a;
    /// @brief Коэффициент уравнения b
    double b;
    /// @brief Коэффициент уравнения с
    double c;
    /// @brief Правильный (ожидаемый) первый корень уравнения 
    double x1_exp;
    /// @brief Правильный (ожидаемый) второй корень уравнения 
    double x2_exp;
    /// @brief Правильное (ожидаемое) количество корней уравнения
    int num_roots_exp;
    };

/** @brief Тестирует функцию SquareSolve
    @param[in] unit_data Массив структур с данными для тестов
    @return 0 - тест пройден, 1 - тест не пройден
*/
int UnitTest (UnitData* unit_data);

/// @brief Вызывает все unit-тесты и хранит данные для них 
void AllUnitTests ();

#endif //UNIT_TESTS