#include "Point.h"
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::Point(unsigned int x_, unsigned int y_) : x(x_), y(y_) {}

unsigned int Point::getX() const {
    return x;
}

unsigned int Point::getY() const {
    return y;
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

std::istream& operator>>(std::istream& in, Point& point) {
    in >> point.x >> point.y;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << (int)point.x << ", " << (int)point.y << ")";
    return out;
}

Point Point::operator+(unsigned int val) const {
    return Point(x + val, y + val);
}

Point Point::operator-(unsigned int val) const {
    return Point(x - val, y - val);
}