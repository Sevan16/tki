#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    virtual std::string ToString() const = 0;
    static Shape* ReadFromInput(std::istream& in);
};

#endif