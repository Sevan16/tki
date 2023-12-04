#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

/**
 * @breaf расчитывает значение y 
 * @param x - аргумент функции 
 * @return возвращает значение y
*/
double y (double x);


/**
 * @breaf проверяет правильность ввода данных 
 * @return возвращает результат в случае успеха
*/
double double_get_value();

/**
 * @breaf проверка на корректность ввода данных 
 * @param start - начальное значение отрезка функции
 * @param end - конечное значение отрезка функции
 * @return возвращает 0 в случае успеха
*/
double check1(double start, double end);

/**
 * @breaf проверка на корректность ввода данных 
 * @param step - шаг между двумя значениями функции
 * @return возвращает 0 в случае успеха
*/
double check2(double step);

/**
 * @breaf Точка входа в программу
 * @return Возвращает 0, если ошибок нет, не 0, если ошибки присутствуют.
*/
int main()
{
    double start, end, step, z, c;
    printf("Input the start number of x: ");
    start = double_get_value();
    printf("Input the end number of x: ");
    end = double_get_value();
    c = check1(start, end);
    printf("Input the delta x: ");
    step = double_get_value();
    c = check2(step);
    z = start;
    while (z < end+step) 
    {
        if ((3 + sin(3.6 * z) == 0))
        {
            printf("%lf", z);
            printf(" no answer");
            z = z + step;
        }
        else
        {
            printf("%lf", z);
            printf(" ");
            printf("%lf\n", y(z));
            z = z + step;
        }
    }

    return 0;
}

double y (double x)
{
    return(x - 1/(3 + sin(3.6 * x)));
}

double double_get_value(){
    double result;
    double scanf_result = scanf("%lf", &result);
    if (scanf_result!=1){
        errno = EIO;
        perror("Input/Output error.");
        abort();
    }
    return result; 
}

double check1(double start, double end){
  if ((start > end) || (start == end))
  {
        errno = EIO;
        perror("Input/Output error.");
        abort();
  }
  return 0;
}

double check2(double step){
  if ((step < 0) || (step == 0))
  {
        errno = EIO;
        perror("Input/Output error.");
        abort();
  }
  return 0;
}