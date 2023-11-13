#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief возвращает площадь треугольника 
 * @param a первая сторона треугольника
 * @param b вторая сторона треугольника
 * @param c третья сторона треугольника
 * @return возвращает значение функции
*/
double Striangle(double a, double b, double c);

/**
 * @brief возвращает площадь пямоугольника
 * @param a первая сторона пямоугольника
 * @param b вторая сторона пямоугольника
 * @return возвращает значение функции
*/

double Srectangle(double a, double b);
/**
 * @brief точка входа в программу
 * @return возвращает 0 если программа корректна, не 0 если нет
*/

int main()
{
    int w;
    float a, b, c;
    printf("Chose triangle or rectangle:\n");
    printf("1 - Triangle\n");
    printf("2 - Rectangle\n");
    scanf_s("%d", &w);
    if (w == 1)
    {
        printf("Enter 1st side of triangle\n");
        scanf_s("%f", &a);
        printf("Enter 2nd side of triangle\n");
        scanf_s("%f", &b);
        printf("Enter 3rd side of triangle\n");
        scanf_s("%f", &c);
        printf("Area of this triangle is: %f", Striangle(a, b, c));
    }
    else if (w == 2)
    {
        printf("Enter 1st side of rectangle\n");
        scanf_s("%f", &a);
        printf("Enter 2nd side of rectangle\n");
        scanf_s("%f", &b);
        printf("Area of this rectangle is: %f", Srectangle(a, b));
    }
    else
    {
        printf("Please input only number 1 or 2");
    }
    return 0;
}
double Striangle(double a, double b, double c)
{
    const double p = 0.5 * (a + b + c);
    return (sqrt(p * (p - a) * (p - b) * (p - c)));
}
double Srectangle(double a, double b)
{
    return (a * b);
}
