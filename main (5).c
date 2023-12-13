
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief Функция вывода среднего арифметического кубов двух чисел.
* @param a первое число.
* @param b второе число.
* @return Возвращает среднее арифметическое кубов a и b.
*/
double srednarif(double a, double b);

/**
 * @brief Функция вывода среднего геометрического модулей двух чисел.
 * @param a первое число.
 * @param b второе число.
 * @return Возвращает среднее геометрическое модулей a и b.
 */
double sredngeom(double a, double b);

/**
 * @brief Проверка на правильность ввода
 * @return возвращает результат в случае успеха
 */
double double_get_value();

/**
 * @brief выбор задачи
 */
enum Operation 
{
     /**
    * @brief Среднее арифметическое кубов двух чисел.
    */
    arithmetic_mean = 1,
    /**
    * @brief Среднее геометрическое модулей двух чисел.
    */
    geometric_mean
};

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
    printf("Please, input the number 'a': \n");
    double a = double_get_value();
    printf("Please, input the number 'b': \n");
    double b = double_get_value();
       printf("Please, choose the number of operation \n");
    printf("1 - Arithmetic mean\n");
    printf("2 - Geometric mean\n");
    int choise = double_get_value();
     enum Operation operation_choise = (enum Operation)(choise);

    switch(operation_choise) {
        case arithmetic_mean:
            printf("The arithmetic mean is %f", srednarif(a, b));
            break;

        case geometric_mean:
            printf("The geometric mean is %f", sredngeom(a, b));
            break;

        default:
            printf("Please input only 1 or 2");
            return 1;
            break;
    }
    return 0;
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

double srednarif(double a, double b)
{
    return ( ( pow(a, 3) + pow(b, 3) ) / 2 );
}

double sredngeom(double a, double b)
{
    return sqrt(pow(a, 2) * pow(b, 2));
}

