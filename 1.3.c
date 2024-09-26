#include <stdio.h>
#include <stdlib.h>
/**
 *  @breaf ����������� ����� ���������� ���������
 *  @param q - ���������� �������, ���
 *  @param i - ���� ����, �
 *  @param r - �������������, ��
 *  @return ���������� ����� ���������� ���������
*/
float t(float q, float i, float r);

/**
 *  @breaf ����� ����� � ���������
 *  @return ���������� 0, ���� ������ ���, �� 0, ���� ������ ������������.
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
