#include <iostream>
#include "Circle.h"

int main()
{
    std::cout << "Enter circle center (x y) and radius: ";
    Point center;
    unsigned int radius;
    std::cin >> center >> radius;
    Circle circle(center, radius);
    std::cout << circle.ToString() << std::endl;
    return 0;
}