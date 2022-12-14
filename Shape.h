//
// Created by andyh on 12/8/2022.
//

#include <vector>
#include <string>
#include "Point.h"
#include <iostream>

#ifndef SHAPESPOROJECT_SHAPE_H
#define SHAPESPOROJECT_SHAPE_H


enum TypeOfShapes{
    UNKNOWN,            // a default value of an empty base Shape (default)
    LINE,
    RECTANGLE,
    CIRCLE
};

class Shape {
private:

    // shape type property.
    TypeOfShapes shapeType;


public:

    std::vector<Point>points;

// constructors
// ---------------------------------------------------
Shape() = default; // Default constructor

Shape(TypeOfShapes shape_type); // property constructor

// accessors
// ---------------------------------------------------

TypeOfShapes getShapeType();
void setShapeType(TypeOfShapes newType);

// methods
// ---------------------------------------------------

// virtual method for display info to avoid slicing
    virtual std::string displayInfo() {};

}; // Shape


class Line : public Shape {

private:

    float length;
    float slope;
    float angle;

public:

    // constructors

    // ---------------------------------------------------
    Line() = default;  // default

    Line(Point pointOne, Point pointTwo); // property

    // accessors
    // ---------------------------------------------------

    // points are inherited from base class points collection

    Point getPointOne();
    void setPointOne(Point point);

    Point getPointTwo();
    void setPointTwo(Point point);

    // methods
    // ---------------------------------------------------

    float calcLength();
    float calcSlope();
    float calcAngle();

    // Implement base shape classes method
    std::string displayInfo();

}; // Line

class Rectangle : public Shape {

private:

    int pointOne;
    int width;
    int height;

public:

    // constructors
    // ---------------------------------------------------

    Rectangle() = default; // default const

    Rectangle(Point pointOne, int width, int height); // property

    // accessors
    // ---------------------------------------------------

    Point getPointOne();
    void setPointOne(Point point);

    int getWidth();
    void setWidth(int width);

    int getHeight();
    int setHeight();

    // methods
    // ---------------------------------------------------

    float calcArea();
    float calcPerimeter();

    // Implement base shape classes method
    std::string displayInfo();

}; // Line

class Circle : public Shape {

private:

    int pointOne;
    int radius;

public:

    // constructors

    Circle();   // default

    Circle(Point pointOne, int radius); // property

    // accessors
    // ----------------------------------------------

    Point getPointOne();
    void setPointOne(Point point);

    int getRadius();
    float calcArea();
    float calcCircumference();

    // methods
    // ---------------------------------------------------

    float calcLength();
    float calcSlope();
    float calcAngle();

    // Implement base shape classes method
    std::string displayInfo();

}; // Line

#endif //SHAPESPOROJECT_SHAPE_H
