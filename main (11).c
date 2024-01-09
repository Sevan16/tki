#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>

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
    RANDOM = 2
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
int check_size(size_t size);

/**
* @brief Функция для считывания элементов массива с клавиатуры.
* @param array - массив.
* @param size - длинна массива.
* @param low - нижняя граница массива
* @param high - верхняя граница массива
*/
void get_array_manually(int* array, const size_t size, const int low, const int high);

/**
* @brief Функция для заполнения массива случайными числами.
* @param array - массив.
* @param size - длинна массива.
* @param low - нижняя граница массива
* @param high - верхняя граница массива
*/
void get_array_randomly(int* array, const size_t size, const int low, const int high);

/**
 * @brief - проверка на правильность ввода границ массива
 * @param low - нижняя граница массива
 * @param high -верхняя граница массива
 */
void check_low_and_high(int low, int high);

/**
 * @brief - проверка на выделение памяти для динамического массива
 * @param array – массив
 */
void check_memory(int* array);

/**
 * @brief Выводит сообщение об ошибке и завершает программу.
 */
void errors();
/**
 * @brief выводит требуемый массив на экран
 * @param array – массив
 * @param size – размер массива
 */
void printArray(const int* array, size_t size);

/**
 * @brief Заменяет максимальный по модулю отрицательный элемент массива нулем.
 * @param array – массив
 * @param size – размер массива
 */
void task_1(int *array, const size_t size);

/**
 * @brief Вставляет число k между всеми соседними элементами, которые имеют разные знаки.
 * @param array – массив
 * @param size – размер массива
 * @param k – заданное число k
 */
void task_2(const int* array, const size_t size, int k);

/**
 * @brief Формирование нового массива по правилам из пункта 3
 * @param array – массив
 * @param size – размер массива
 * @param k1 – заданное число k
 */
void task_3(const int* array, const size_t size, int k1);

/**
 * @brief Точка входа в программу.
 * @return Возвращает 0 в случае успеха.
 */
int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    printf("Введите размер массива: ");
    size_t size = get_value();
    check_size(size);
    int* array = (int*)malloc(size * sizeof(int));
    check_memory(array);
    printf("Введите нижнюю границу массива: ");
    int low = double_get_value();
    printf("Введите верхнюю границу массива: ");
    int high = double_get_value();
    check_low_and_high(low, high);
    printf("Как Вы хотите заполнить массив?\n");
    printf("%d - Для заполнения массива с клавиатуры\n", MANUAL);
    printf("%d - Для заполнения массива случайными числами\n", RANDOM);
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
    }
    task_1(array, size);
    printf("Введите число K для вставки между всеми соседними элементами, которые имеют разные знаки: ");
    int k = get_value();
    printf("Результат после вставки числа K: ");
    task_2(array, size, k);
    printf("Введите число k для задания 3: ");
    int k1 = get_value();
    task_3(array, size, k1);
    return 0;
}

double double_get_value()
{
    double result;
    double scanf_result = scanf("%lf", &result);
    if (scanf_result!=1){
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
    if (scanf_result!=1){
        errno = EIO;
        perror("Error");
        abort();
    }
    return result;
}

int check_size(size_t size)
{
    if ((int)size <= 0)
    {
        errno = EIO;
        perror("Error");
        abort();
    }
    return (size_t)size;
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

void errors()
{
    errno = EIO;
    perror("Error");
    abort();
}

void check_low_and_high(int low, int high)
{
    if (low > high)
    {
        errno = EIO;
        perror("Error");
        abort();
    }
}

void check_memory(int* array)
{
    if (array == NULL)
    {
        perror("Ошибка выделения памяти");
        exit(errno);
    }
}

void printArray(const int* array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void task_1(int *array, const size_t size)
{
    printf("Массив до замены:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    size_t max_index = -1;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] < 0 && (max_index == -1 || abs(array[i]) > abs(array[max_index])))
        {
            max_index = i;
        }
    }
    if (max_index != -1)
    {
        array[max_index] = 0;
        printf("\nМассив после замены:\n");
        printArray(array, size);
    }
    else
    {
        printf("\nВ массиве нет отрицательных элементов.\n");
    }
}

void task_2(const int* array, const size_t size, int k)
{
    size_t new_size = size;
    int* new_array = (int*)malloc(new_size * sizeof(int));
    check_memory(new_array);
    for (size_t i = 0, j = 0; i < size; i++)
    {
        new_array[j++] = array[i];
        if ((i < size - 1) && ((array[i] * array[i + 1] < 0)))
        {
            new_array = realloc(new_array, (new_size + 1) * sizeof(int));
            check_memory(new_array);
            new_array[j++] = k;
            new_size++;
        }
    }
    printArray(new_array, new_size);
}

void task_3(const int* array, size_t size, int k1)
{
    int *new_array = (int *)malloc(size * sizeof(int));
    check_memory(new_array);
    for (int i = 0; i < size; i++)
    {
        if (i < k1)
        {
            new_array[i] = -array[i] * array[i];
        } else
        {
            new_array[i] = array[i] - 1;
        }
    }
    printf("Массив A:\n");
    printArray(new_array, size);
}