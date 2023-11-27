#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief возвращает значение у по первому условию
 * @param x, a - параметры функции для первого условия
 * @return возвращает значение функции
 */
float first_condition(float a, float x);

/**
 * @brief возвращает значение у по второму условию
 * @param x, a - параметры функции для второго условия
 * @return возвращает значение функции
 */
float second_condition(float a, float x);

/**
 * @brief функция проверки ввода на правильность 
 * @return возвращает 0 в случае успеха
 */
double double_get_value();

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа написана корректно, иначе возвращает не 0
 */
int main()
{
    const float a = 2.1;
    float x;
    printf("Input the number of x: ");
    scanf("%f", &x);
    if (x < 4)
    {
        const float Y = first_condition(a, x);
        printf("y = %f", Y);
    }

    else
    {
        const float Y = second_condition(a, x);
        printf("y = %f", Y);
    }
    return 0;
}

float first_condition(float a, float x)
{
    const float y = (a / x + pow(x, 2));
    return y;
}

float second_condition(float a, float x)
{
    const float y = (a * x + pow(x, 3));
    return y;
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