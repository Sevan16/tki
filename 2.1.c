#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @breaf рассчитывает среднее арифмитическое по заданной формуле
* @param a первое число
* @param b второе число
* @return возвращает среднее арифмитическое по заданной формуле
*/
float srednarif(float a, float b);

/**
* @breaf рассчитывает среднее геометрическое по заданной формуле
* @param a первое число
* @param b второе число
* @return возвращает среднее геометрическое по заданной формуле
*/
float sredngeom(float a, float b);

/**
* @breaf пользовательский ввод
*/
enum Operation {
    arithmetic_mean = 1,
    geometric_mean
};

/**
* @breaf точка входа в программу
* @return возвращает 0 если ошибок нет, иначе не 0
*/
int main()
{
    int choise;
    float a, b;

    printf("Please, input the number 'a': \n");
    scanf_s("%f", &a);
    printf("Please, input the number 'b': \n");
    scanf_s("%f", &b);

    printf("Please, choose the number of operation \n");
    printf("1 - Arithmetic mean\n");
    printf("2 - Geometic mean\n");
    scanf_s("%i", &choise);

    switch (choise) {

    case arithmetic_mean:
        printf("The arithmetic mean is %f", srednarif(a, b));
        break;

    case geometric_mean:
        printf("The geometric mean is %f", sredngeom(a, b));
        break;

    default:
        printf("Please input only 1 or 2");
        break;
    }

}

float srednarif(float a, float b)
{
    const float s = ((pow(a, 3) + pow(b, 3)) / 2);
    return s;
}


float sredngeom(float a, float b)
{
    const float s = sqrt(pow(a, 2) * pow(b, 2));
    return s;
}
