#include "list.h"

int main() {
    LinkedList list;
    list.pushFront(10);
    list.pushFront(20);
    list.pushBack(30);
    list.pushBack(40);

    cout << "List after additions: ";
    list.printList();

    list.popFront();
    cout << "List after popFront: ";
    list.printList();

    list.popBack();
    cout << "List after popBack: ";
    list.printList();

    list.clear();
    cout << "List after clear: ";
    list.printList();

    return 0;
}