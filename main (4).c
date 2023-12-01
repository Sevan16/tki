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
         Manual = 1, 
         /** 
         * @brief Заполнение массива случайными числами. 
         */ 
         Random = 2 
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
 */ 
void arrmanual(int* arr, const int size);

 /** 
 * @brief Функция для заполнения массива случайными числами. 
 * @param size - длинна массива. 
 * @param arr - массив. 
 */ 
void arrrandom(int* arr, const int size);

/** 
 * @brief Функция для вычисления задания 1. 
 * @param size - длинна массива. 
 * @param arr - массив.
 * @return Возвращает ответ на задание 1.
 */ 
int zadanie1(int* arr, const int size);

/** 
 * @brief Функция для вычисления задания 2. 
 * @param size - длинна массива. 
 * @param arr - массив. 
 * @param A - заданное число.
 * @return Возвращает ответ на задание 2.
 */ 
int zadanie2(int* arr, const int size, double A);

/** 
 * @brief Функция для вычисления задания 3. 
 * @param size - длинна массива. 
 * @param arr - массив.
 * @return Возвращает ответ на задание 3.
 */ 
int zadanie3(int* arr, const int size);

/** 
 * @brief Точка входа в программу. 
 * @return Возвращает 0 в случае успеха. 
 */ 
int main(){
    setlocale(LC_ALL, "RU");
    printf("Введите размер массива: ");
    const int size = get_value(); 
    check_size(size);
    int* arr = (int*)malloc(size * sizeof(int)); 
    printf("Как Вы хотите заполнить массив? \n 1 – Cамостоятельно \n 2 – Случайным образом\n");
    const int choose = get_value();
    switch(choose){
        
       case Manual:
       arrmanual(arr, size);
       break;

       case Random:
       arrrandom(arr, size);       
       break;
       
       default:
        { 
            errno = EIO;
            perror("Input/Output error.");
            abort();
        } 
       break;}
       printf("Введите значение А для задания 2: ");
       double A = double_get_value();
       printf("1) Сумма отрицательных элементов равна: ");
       printf("%d\n", zadanie1(arr, size)); 
       printf("2) Количество тех элементов, значения которых положительны и не превосходят заданного числа А: ");
       printf("%d\n", zadanie2(arr, size, A)); 
       printf("3) Номер последней пары соседних элементов с разными знаками: ");
       printf("%d\n", zadanie3(arr, size)); 
       free(arr); 
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

void arrmanual(int* arr, const int size){ 
         for (int i = 0; i < size; i++){ 
                 printf("Введите число от -100 до 200: ");
                 int  x = get_value(); 
                 if (x < -100 || x > 200){ 
                         errno = EIO;
                         perror("Input/Output error.");
                         abort();
                 } 
                 arr[i] = x; 
         } 
 } 

void arrrandom(int* arr, const int size){
    srand(time(NULL));
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 301 - 100;
    }
}

int zadanie1(int* arr, const int size){
    int S = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] < 0){
            S = arr[i] + S;
        }
    }
    return S;
}

int zadanie2(int* arr, const int size, double A){
    int K = 0;
    for (int i = 0; i < size; i++){
        if ((arr[i] > 0) && (arr[i] <= A)){
            K++;
        }
    }
    return K;
}

int zadanie3(int* arr, const int size){
    int para;
    for (int i = size - 1; i >= 0; i--){
    if (((arr[i]>0) && (arr[i-1]<0)) || (arr[i]<0) && (arr[i-1]>0)){
        para = i;
        break;}}
    return para;
}

