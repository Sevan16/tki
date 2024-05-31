#ifndef TASK_LIST_V2_LIST_H
#define TASK_LIST_V2_LIST_H

#include <iostream>

using namespace std;

/**
 * @brief Структура узла списка.
 */
struct Node {
    int data;
    Node* next;

    /**
     * @brief Конструктор узла.
     * @param data Значение для инициализации данных узла.
     */
    Node(int data);
};

/**
 * @brief Класс односвязного списка.
 */
class LinkedList {
private:
    Node* head;

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    LinkedList();

    /**
     * @brief Деструктор списка. Очищает список при удалении объекта.
     */
    ~LinkedList();

    /**
    * @brief Добавляет элемент в начало списка.
    * @param data Значение для добавления.
    */
    void pushFront(int data);

    /**
     * @brief Добавляет элемент в конец списка.
     * @param data Значение для добавления.
     */
    void pushBack(int data);

    /**
     * @brief Удаляет элемент из начала списка.
     */
    void popFront();

    /**
     * @brief Удаляет элемент из конца списка.
     */
    void popBack();

    /**
     * @brief Очищает список, удаляя все элементы.
     */
    void clear();

    /**
     * @brief Печатает все элементы списка.
     */
    void printList() const;
};

#endif 