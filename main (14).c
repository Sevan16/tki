#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

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

/**
 * @brief Проверка, что e не превышает модуля первого члена ряда (для k=1)
 * @param e - заданное число e
 */
void check_e(double e);

/**
 * @brief Выводит сообщение об ошибке и завершает программу.
 */
void errors();

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
    check_e(e);
    printf("Result: %lf", series_with_e(e));
    return 0;
}

int int_get_value()
{
    int result;
    int scanf_result = scanf("%d", &result);
    if ((scanf_result!=1) || (result <= 0))
    {
        errors();
    }
    return result;
}

double double_get_value()
{
    double result;
    double scanf_result = scanf("%lf", &result);
    if (scanf_result!=1)
    {
        errors();
    }
    return result;
}

double series(const int n)
{
    double result = 0;
    for (int k = 1; k <= n; k++)
    {
        result += element(k);
    }
    return result;
}

double element(const int k)
{
    double result;
    if (k % 2 != 0)
    {
        result = -1;
    }
    else
    {
        result = 1;
    }
    for (int i = k-1; i > 1; i--)
    {
        double j = pow(i, -1);
        result = result * j;
    }
    return result;
}

double series_with_e(const double e)
{
    int k = 1;
    double sum = 0;
    double current_element = element(k);
    while (fabs(current_element)-e >= -DBL_EPSILON)
    {
        current_element = element(k);
        sum += current_element;
        k += 1;
    }
    return sum;
}

void check_e(double e)
{
    if (e >= fabs(element(1)))
    {
        errors();
    }
}

void errors()
{
    errno = EIO;
    perror("Error");
    abort();
}