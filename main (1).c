#include <stdio.h>
#include <float.h>
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
 * @return возвращает размер массива в случае успеха
*/
int check_size();

/**
* @brief Функция для считывания элементов массива с клавиатуры.
* @param array - массив
* @param size - длинна массива
* @param low - нижняя граница массива
* @param high - верхняя граница массива
*/
void get_array_manually(int* array, const size_t size, const int low, const int high);

/**
* @brief Функция для заполнения массива случайными числами.
* @param array - массив
* @param size - длинна массива
* @param low - нижняя граница массива
* @param high - верхняя граница массива
*/
void get_array_randomly(int* array, const size_t size, const int low, const int high);

/**
 * @brief Функция для вычисления задания 1
 * @param array - массив
 * @param size - длинна массива
 * @return Возвращает ответ на задание 1
 */
int task1(const int* array, const size_t size);

/**
 * @brief Функция для вычисления задания 2
 * @param array - массив
 * @param size - длинна массива
 * @return Возвращает ответ на задание 2
 */
int task2(const int* array, const size_t size);

/**
 * @brief Функция для вычисления задания 3
 * @param array - массив
 * @param size - длинна массива
 * @return Возвращает ответ на задание 3
 */
size_t task3(const int* array, const size_t size);

/**
 * @brief Выводит сообщение об ошибке и завершает программу.
 */
void errors();

/**
 * @brief - проверка на правильность ввода границ массива
 * @param low - нижняя граница массива
 * @param high -верхняя граница массива
 */
void check_range(const int low, const int high);

/**
 * @brief - проверка на выделение памяти для динамического массива
 * @param size – размер массива
 */
int* check_memory(const size_t size);

/**
 * @brief Точка входа в программу.
 * @return Возвращает 0 в случае успеха.
 */
int main()
{
    setlocale(LC_ALL, "RU");
    printf("Введите размер массива: ");
    size_t size = check_size();
    int* array = check_memory(size);
    printf("Введите нижнюю границу массива: ");
    int low = get_value();
    printf("Введите верхнюю границу массива: ");
    int high = get_value();
    check_range(low, high);
    printf("Как Вы хотите заполнить массив? \n 1 – Cамостоятельно \n 2 – Случайным образом\n");
    int choose = get_value();
    enum array_input user_input = (enum array_input)choose;
    switch(user_input)
    {
        case MANUAL:
            get_array_manually(array, size, low, high);
            break;

        case RANDOM:
            get_array_randomly(array, size, low, high);
            break;

        default:
            errors();
            return 1;
            break;
    }
    printf("1) Сумма отрицательных элементов равна: ");
    printf("%d\n", task1(array, size));
    printf("Введите значение А для задания 2: ");
    printf("2) Количество тех элементов, значения которых положительны и не превосходят заданного числа А: %d", task2(array, size));
    if (task3(array, size) == 0)
    {
        printf("\n3) Требуемых пар не нашлось.");
    }
    else
    {
        printf("\n3) Номер последней пары соседних элементов с разными знаками: %zu", task3(array, size));
    }
    if (array == NULL)
    {
        free(array);
    }
    return 0;
}

double double_get_value()
{
    double result;
    double scanf_result = scanf("%lf", &result);
    if (scanf_result!=1)
    {
        errno = EIO;
        perror("Error");
        abort();
    }
    return result;
}

int get_value()
{
    int result;
    int scanf_result = scanf("%d", &result);
    if (scanf_result!=1)
    {
        errno = EIO;
        perror("Error");
        abort();
    }
    return result;
}

int check_size()
{
    int size = get_value();
    if (size <= 0)
    {
        errno = EIO;
        perror("Error");
        abort();
    }
    return (size_t) size;
}

void get_array_manually(int* array, const size_t size, const int low, const int high)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите число: ");
        int  x = get_value();
        if (x < low || x > high)
        {
            errno = EIO;
            perror("Error");
            abort();
        }
        array[i] = x;
    }
}

void get_array_randomly(int* array, const size_t size, const int low, const int high)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        array[i] = rand() % (high - low + 1) + low;
    }
}

int task1(const int* array, const size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] < 0)
        {
            sum += array[i];
        }
    }
    return sum;
}

int task2(const int* array, const size_t size)
{
    double a = double_get_value();
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if ((array[i]  > 0) && (a  >= array[i]))
        {
            count++;
        }
    }
    return count;
}

size_t task3(const int* array, const size_t size)
{
    for (size_t i = size - 1; i > 0; i--)
    {
        if ((array[i] * array[i - 1]) < 0)
        {
            return i;
        }
    }
    return 0;
}

void errors()
{
    errno = EIO;
    perror("Error");
    abort();
}

void check_range(const int low, const int high)
{
    if (low > high)
    {
        errno = EIO;
        perror("Error");
        abort();
    }
}

int* check_memory(const size_t size)
{
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL)
    {
        perror("Ошибка выделения памяти");
        exit(errno);
    }
    return array;
}