#include <stdio.h>
#include <stdlib.h>


/**
* @brief Возвращает результат функции b
* @param Параметр "a" для функции b
* @param Параметр "n" для функции b
**/
float get_B(double a, double n);
/*
* @brief Возвращает результат функции square_func
* @param Параметр "a" для функции square_func
* @param Параметр "b" для функции square_func
**/
float square_func(float a, float b);

/*
* @brief Возвращает результат функции perimeter_func
* @param Параметр "a" для функции perimeter_func
* @param Параметр "b" для функции perimeter_func
**/
float perimeter_func(float a, float b);


/*
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе не 0
**/
int main()
{
    float a, n;

    scanf_s("%f", &a);
    scanf_s("%f", &n);

    float b = get_B(a, n);
    float square = square_func(a, b);
    float perimeter = perimeter_func(a, b);

    printf("\n square=%f", square);
    printf("\n preimeter=%f", perimeter);
}

float get_B(float a, float n)
{
    return a * n / 100;
}


float square_func(float a, float b)
{
    return a * b;
}


float perimeter_func(float a, float b)
{
    return a * 2 + b * 2;
}