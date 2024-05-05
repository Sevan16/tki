#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
    unsigned int x;
    unsigned int y;

    Point();
    Point(unsigned int x_, unsigned int y_);

    unsigned int getX() const;
    unsigned int getY() const;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    friend std::istream& operator>>(std::istream& in, Point& point);
    friend std::ostream& operator<<(std::ostream& out, const Point& point);

    Point operator+(unsigned int val) const;
    Point operator-(unsigned int val) const;
};

#endif 