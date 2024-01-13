#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

/**
* @breaf проверяет правильность ввода данных
* @return возвращает результат в случае успеха
*/
int int_get_value();

/**
* @breaf проверяет правильность ввода данных
* @return возвращает результат в случае успеха
*/
double double_get_value();

/**
* @brief Функция для вычисления суммы ряда
* @param n - количество элементов ряда
* @return Возвращает сумму ряда
*/
double series(const int n);

/**
* @brief Функция для вычисления элемента ряда
* @param k - порядковый номер элемента ряда
* @return Возвращает значение элемента ряда
*/
double element(const int k);

/**
* @brief Функция для вычисления суммы всех членов ряда, не меньших заданного числа e
* @param e - число заданное с клавиатуры
* @return Возвращает сумму ряда
*/
double series_with_e(const double e);

/**
* @brief Функция для вычисления факториала
* @param n - число для вычисления
* @return Возвращает факториал числа
*/
unsigned long long factorial (int n);

/**
 * @brief Точка входа в программу.
 * @return Возвращает 0 в случае успеха.
 */
int main()
{
    printf("Input the number of n: ");
    const int n = int_get_value();
    printf("The sum of series is: %lf", series(n));
    printf("\nInput the number of e: ");
    double e = double_get_value();
    printf("Result: %lf", series_with_e(e));
    return 0;
}

int int_get_value()
{
    int result;
    int scanf_result = scanf("%d", &result);
    if ((scanf_result!=1) || (result < 0))
    {
        errno = EIO;
        perror("Error");
        abort();
    }
    return result;
}

double double_get_value()
{
    double result;
    double scanf_result = scanf("%lf", &result);
    if (scanf_result!=1 || result <= 0){
        errno = EIO;
        perror("Error");
        abort();
    }
    return result;
}

double series(const int n)
{
    double result = 0;
    for (int k = 0; k <= n; k++)
    {
        result += element(k);
    }
    return result;
}

unsigned long long factorial (int n)
{
    unsigned long long r;
    for (r = 1; n > 1; r *= (n--))
        ;
    return r;
}

double element(const int k)
{
    return(pow(-1,k) * k)/ factorial(k);
}
double series_with_e(const double e)
{
    int k = 2;
    double sum = 0;
    double current_element = element(k);
    while (current_element >= e)
    {
        current_element = element(k);
        sum += current_element;
        k += 2;
    }
    return sum;
}