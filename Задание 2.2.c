#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief первое условие
 * @param x – значение параметра x
 * @return возвращает найденное значение y
 */
double first_condition(double x);

/**
 * @brief второе условие
 * @param x – значение параметра x
 * @return возвращает найденное значение y
 */
double second_condition(double x);

/**
 * @brief проверяет правильность ввода данных
 * @return возвращает результат в случае успеха
 */
double double_get_value();

/**
 * @brief точка входа в программу
 * @return возвращает 0 в случае успеха
 */
int main()
{
    printf("Введите значение x: ");
    double x = double_get_value();
    if (x < 4)
    {
        printf("y = %lf", first_condition(x));
    }
    else
    {
        printf("y = %lf", second_condition(x));
    }
    return 0;
}

double first_condition(double x)
{
    const double a = 2.1;
    return (a / x + pow(x, 2));
}

double second_condition(double x)
{
    const double a = 2.1;
    return (a * x + pow(x, 3));
}

double double_get_value()
{
    double result;
    double scanf_result = scanf("%lf", &result);
    if (scanf_result != 1 || result<=0)
    {
        errno = EIO;
        perror("Input/Output error.");
        abort();
    }
    return result;
}
