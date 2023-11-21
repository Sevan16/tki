#include <stdio.h>
#include <stdlib.h>
/**
 *  @breaf расчитывает время нагревания проволоки
 *  @param q - количество теплоты, кДж
 *  @param i - сила тока, А
 *  @param r - сопротивление, Ом
 *  @return возвращает время нагревания проволоки
*/
float t(float q, float i, float r);

/**
 *  @breaf Точка входа в программу
 *  @return Возвращает 0, если ошибок нет, не 0, если ошибки присутствуют.
*/
int main()
{
    float q, i, r;
    printf("Input Q [kJ]:\n");
    scanf_s("%f", &q);
    printf("Input I [A]:\n");
    scanf_s("%f", &i);
    printf("Input R [Om]:\n");
    scanf_s("%f", &r);
    printf("t = %f", t(q, i, r));
    printf(" sec.");
    return 0;
}
float t(float q, float i, float r)
{
    const float t = (1000 * q) / (i * i * r);
    return t;
}
