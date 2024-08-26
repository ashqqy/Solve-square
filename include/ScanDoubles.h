/**
    @file
    @brief Файл с функцией ввода чисел double с клавиатуры
*/

#ifndef SCAN_DOUBLES
#define SCAN_DOUBLES

/// @brief Функция, очищающая буфер ввода
void CleanBufer ();
/** 
    @brief Функция для ввода чисел double с клавиатуры
    @param[in] coef Переменная, в которую помещается введенное число

    Функция работает на основе уже существующего scanf'a,\n
    но обрабатывает ввод на случай ошибок, совершенных при вводе.
*/
void ScanDoubles (double* coef);

#endif //SCAN_DOUBLES
