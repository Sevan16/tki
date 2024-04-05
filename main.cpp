#include <iostream>
#include <sstream>
#include <cmath>

class Point {
private:
    unsigned int x;
    unsigned int y;

public:
    Point() : x(0), y(0) {}

    Point(unsigned int _x, unsigned int _y) : x(_x), y(_y) {}

    unsigned int getX() const { return x; }
    unsigned int getY() const { return y; }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    friend std::istream& operator>>(std::istream& in, Point& point) {
        in >> point.x >> point.y;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }

    Point operator+(unsigned int val) const {
        return Point(x + val, y + val);
    }

    Point operator-(unsigned int val) const {
        return Point(x - val, y - val);
    }
};

class Shape {
public:
    virtual std::string ToString() const = 0; 

    static Shape* ReadFromInput(std::istream& in) {
        return nullptr;
    }
};

class Circle : public Shape {
private:
    Point center;
    unsigned int radius;

public:
    Circle(Point _center, unsigned int _radius) : center(_center), radius(_radius) {}

    std::string ToString() const override {
        std::stringstream ss;
        ss << "Circle with center " << center << " and radius " << radius;
        return ss.str();
    }

    static Shape* ReadFromInput(std::istream& in) {
        Point center;
        unsigned int radius;
        in >> center >> radius;
        return new Circle(center, radius);
    }
};

int main() {

    std::cout << "Enter circle center (x y) and radius: ";
    Shape* shape = Circle::ReadFromInput(std::cin);
    if (shape != nullptr) {
        std::cout << shape->ToString() << std::endl;
        delete shape;
    } else {
        std::cout << "Invalid input for circle." << std::endl;
    }
    return 0;
}
