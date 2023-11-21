#include <stdio.h>
#include <math.h>

/**
 * @breaf расчитывает значение переменной a по формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return возвращает значение переменной a по формуле
*/
double a(double x, double y, double z);

/**
 * @breaf рассчитывает значение переменной b по формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return возвращает значение переменной b по формуле
*/
double b(double x, double y, double z);

/**
 * @breaf Точка входа в программу
 * @return Возвращает 0, если ошибок нет, не 0, если ошибки присутствуют.
*/

int main()
{
    const double x = -4.8;
    const double y = 17.5;
    const double z = 3.2;
    printf("result of a = %f", a(x,y,z));
    printf("\nresult of b = %f", b(x,y,z));
    return 0;
}

double a(double x, double y, double z)
{
    return (y*z*pow(x, 2) - (z/(pow(sin(x/z),2))));
}

double b(double x, double y, double z)
{
    return (z*exp(-sqrt(z))*cos((y*x)/z));
}