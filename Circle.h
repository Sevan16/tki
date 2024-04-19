#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
private:
    Point center;
    unsigned int radius;

public:
    Circle(Point center_, unsigned int radius_);

    std::string ToString() const override;
    static Shape* ReadFromInput(std::istream& in);
};

#endif