#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>

/**
* @breaf проверяет правильность ввода данных
* @return возвращает результат в случае успеха
*/
double double_get_value();

/**
* @breaf вычисляет площадь треугольника
* @param a – первая сторона треугольнка
* @param b – вторая сторона треугольника
* @param c – третья сторона треугольника
* @return возвращает площадь треугольника
*/
double TriangleArea(double a, double b, double c);

/**
* @breaf вычисляет площадь прямоугольника
* @param a – первая сторона прямоугольника
* @param b – вторая сторона прямоугольника
* @return возвращает площадь прямоугольника
*/
double RectangleArea(double a, double b);

/**
* @breaf проверяет правильность ввода данных
* @return возвращает результат в случае успеха
*/
int int_get_value();

/**
* @brief Выбор типа фигуры.
*/
enum shape_type {
    /**
    * @brief Выбор треугольника.
    */
    Triangle = 1,

    /**
    * @brief Выбор прямоугольника.
    */
    Rectangle
};

int main()
{
    printf("Выберите тип фигуры:\n");
    printf("1. Треугольник\n");
    printf("2. Прямоугольник\n");
    int choose = int_get_value();
    enum shape_type user_input = (enum shape_type)choose;
    switch (user_input)
    {
        case Triangle:
            printf("Введите первую сторону треугольника: ");
            double a = double_get_value();
            printf("Введите вторую сторону треугольника: ");
            double b = double_get_value();
            printf("Введите третью сторону треугольника: ");
            double c = double_get_value();
            printf("Площадь заданного треугольника равна: %lf", TriangleArea(a, b, c));
            break;
        case Rectangle:
            printf("Введите первую сторону прямоугольника: ");
            a = double_get_value();
            printf("Введите вторую сторону прямоугольника: ");
            b = double_get_value();
            printf("Площадь заданного прямоугольника равна: %lf", RectangleArea(a, b));
            break;
    }
    return 0;
}

double TriangleArea(double a, double b, double c)
{
    const double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double RectangleArea(double a, double b)
{
    return a * b;
}

double double_get_value()
{
    double result;
    double scanf_result = scanf("%lf", &result);
    if (scanf_result!=1)
    {
        errno = EIO;
        perror("Input/Output error.");
        abort();
    }
    return result;
}

int int_get_value()
{
    int result;
    int scanf_result = scanf("%d", &result);
    if (scanf_result!=1)
    {
        errno = EIO;
        perror("Input/Output error.");
        abort();
    }
    return result;
}