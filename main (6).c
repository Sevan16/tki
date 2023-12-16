#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


/**
* @brief Способы заполнения массива.
*/
enum array_input
{
    /**
    * @brief Заполнение массива вручную.
    */
    MANUAL = 1,
    /**
    * @brief Заполнение массива случайными числами.
    */
    RANDOM
};

/**
* @breaf проверяет правильность ввода данных
* @return возвращает результат в случае успеха
*/
double double_get_value();

/**
 * @breaf проверяет правильность ввода данных
 * @return возвращает результат в случае успеха
*/
int get_value();

/**
 * @breaf проверяет правильность ввода размера массива
 * @param size - размер массива
*/
void check_size(int int_size);

/**
* @brief Функция для считывания элементов массива с клавиатуры.
* @param size - длинна массива.
* @param arr - массив.
* @param low - нижняя граница массива
* @param high - верхняя граница массива
*/
void arrmanual(int* arr, size_t size, int low, int high);

/**
* @brief Функция для заполнения массива случайными числами.
* @param size - длинна массива.
* @param arr - массив.
* @param low - нижняя граница массива
* @param high - верхняя граница массива
*/
void arrrandom(int* arr, size_t size, int low, int high);

/**
 * @brief Функция для вычисления задания 1.
 * @param size - длинна массива.
 * @param arr - массив.
 * @return Возвращает ответ на задание 1.
 */
int task1(int* arr, size_t size);

/**
 * @brief Функция для вычисления задания 2.
 * @param size - длинна массива.
 * @param arr - массив.
 * @param A - заданное число.
 * @return Возвращает ответ на задание 2.
 */
int task2(int* arr, size_t size);

/**
 * @brief Функция для вычисления задания 3.
 * @param size - длинна массива.
 * @param arr - массив.
 * @return Возвращает ответ на задание 3.
 */
int task3(int* arr, size_t size);

/**
 * @brief Выводит сообщение об ошибке и завершает программу.
 */
void errors();

/**
 * @brief - проверка на правильность ввода границ массива
 * @param low - нижняя граница массива
 * @param high -верхняя граница массива
 */
void check_low_and_high(int low, int high);

/**
 * @brief - проверка на выделение памяти для динамического массива
 * @param arr – массив
 */
void check_memory(int* arr);

/**
 * @brief Точка входа в программу.
 * @return Возвращает 0 в случае успеха.
 */
int main()
{
    setlocale(LC_ALL, "RU");
    printf("Введите размер массива: ");
    size_t size = get_value();
    check_size(size);
    int* arr = (int*)malloc(size * sizeof(int));
    check_memory(arr);
    printf("Введите нижнюю границу массива: ");
    int low = double_get_value();
    printf("Введите верхнюю границу массива: ");
    int high = double_get_value();
    check_low_and_high(low, high);
    printf("Как Вы хотите заполнить массив? \n 1 – Cамостоятельно \n 2 – Случайным образом\n");
    int choose = get_value();
    enum array_input user_input = (enum array_input)choose;
    switch(user_input)
    {
        case MANUAL:
            arrmanual(arr, size, low, high);
            break;

        case RANDOM:
            arrrandom(arr, size, low, high);
            break;

        default:
            errors();
            break;
    }

    printf("1) Сумма отрицательных элементов равна: ");
    printf("%d\n", task1(arr, size));
    printf("Введите значение А для задания 2: ");
    printf("%d\n", task2(arr, size));
    if (task3(arr, size) == 0)
    {
    printf("3) Требуемых пар не нашлось.");
    }
    else
    {
    printf("3) Номер последней пары соседних элементов с разными знаками: ");
    printf("%d\n", task3(arr, size));
    }
    if (arr == NULL)
    {
       free(arr);
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

int get_value(){
    int result;
    int scanf_result = scanf("%d", &result);
    if (scanf_result!=1){
        errno = EIO;
        perror("Input/Output error.");
        abort();
    }
    return result;
}

void check_size(int int_size){
    if (int_size <= 0){
        errno = EIO;
        perror("Input/Output error.");
        abort();
    }
}

void arrmanual(int* arr, size_t size, int low, int high){
    for (int i = 0; i < size; i++){
        printf("Введите число: ");
        int  x = get_value();
        if (x < low || x > high)
        {
            errno = EIO;
            perror("Input/Output error.");
            abort();
        }
        arr[i] = x;
    }
}

void arrrandom(int* arr, size_t size, int low, int high){
    srand(time(NULL));
    for (int i = 0; i < size; i++){
        arr[i] = rand() % (high - low + 1) + low;
    }
}

int task1(int* arr, size_t size){
    int s = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] < 0){
            s += arr[i];
        }
    }
    return s;
}

int task2(int* arr, size_t size)
{
    double a = double_get_value();
    int k = 0;
    for (int i = 0; i < size; i++){
        if ((arr[i] > 0) && (arr[i] <= a)){
            k++;
        }
    }
    printf("2) Количество тех элементов, значения которых положительны и не превосходят заданного числа А: ");
    return k;
}

int task3(int* arr, size_t size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if ((arr[i] * arr[i-1]) < 0)
        {
            return i;
        }
    }
    return 0;
}

void errors()
{
    errno = EIO;
    perror("Input/Output error.");
    abort();
}

void check_low_and_high(int low, int high)
{
    if (low > high)
    {
        errno = EIO;
        perror("Input/Output error.");
        abort();
    }
}

void check_memory(int* arr) 
 { 
    if (arr == NULL) 
    { 
        perror("Ошибка выделения памяти");
        exit(errno);
    } 
 } 
