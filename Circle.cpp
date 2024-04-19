#include "Circle.h"
#include <sstream>
#include <stdexcept> 

Circle::Circle(Point center_, unsigned int radius_) : center(center_) {
    if ((int)radius_ <= 0) { 
        throw std::invalid_argument("Radius must be positive");
    }
    radius = radius_;
}

std::string Circle::ToString() const {
    std::stringstream ss;
    ss << "Circle with center " << center << " and radius " << radius;
    return ss.str();
}

Shape* Circle::ReadFromInput(std::istream& in) {
    Point center;
    unsigned int radius;
    in >> center >> radius;
    if ((int)radius <= 0) { 
        throw std::invalid_argument("Radius must be positive");
    }
    return new Circle(center, radius);
}