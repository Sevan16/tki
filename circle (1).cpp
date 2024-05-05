#include "Circle.h"
#include <sstream>
#include <stdexcept> 

Circle::Circle(Point center_, double radius_) : center(center_) {
    if (radius_ <= 0.00001) { 
        throw std::invalid_argument("Radius must be positive");
    }
    radius = radius_;
}

std::string Circle::ToString() const {
    std::stringstream ss{};
    ss << "Circle with center " << center << " and radius " << radius;
    return ss.str();
}

Shape* Circle::ReadFromInput(std::istream& in) {
    Point center;
    double radius;
    in >> center >> radius;
    return new Circle(center, radius);
}