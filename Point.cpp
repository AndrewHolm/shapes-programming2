//
// Created by andyh on 12/8/2022.
//

#include "Point.h"
#include "Shape.h"


// constructors
// ---------------------------------------------------

Point::Point(int x, int y) {
    this-> x = x;
    this-> y = y;
}

// accessors
// ---------------------------------------------------

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

void Point::setX(int x) {
    this-> x = x;
}

void Point::setY(int y) {
    this-> y = y;
}



// points are inherited from base class points collection
Point Line::getPointOne() {
    return points[0];
}

void Line::setPointOne(Point point) {
    points[0] = point;
}


Point Line::getPointTwo() {
    return points[1];
}

void Line::setPointTwo(Point point) {
    points[1] = point;
}

