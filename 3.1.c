#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief рассчитывает значение функции 
 * @param значение параметра х
 * @return возвращает значение функции
*/

float y(float x);

/**
 * @brief точка входа в пргорамму
 * @return возвращает 0 если ошибок нет, иначе не 0
*/

int main()
{
    float start, end, h, z;
    printf("Input the start number of x: ");
    scanf_s("%f", &start);
    z = start;
    printf("Input the end number of x: ");
    scanf_s("%f", &end);
    printf("Input the delta x: ");
    scanf_s("%f", &h);
    while (z < end + h)
    {
        if ((3 + sin(3.6 * z) == 0))
        {
            printf("%f", z);
            printf(" no answer");
            z = z + h;
        }
        else
        {
            printf("%f", z);
            printf(" ");
            printf("%f\n", y(z));
            z = z + h;
        }
    }

    return 0;
}

float y(float x)
{
    return(x - 1 / (3 + sin(3.6 * x)));
}
