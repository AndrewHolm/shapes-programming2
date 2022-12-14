//
// Created by andyh on 12/8/2022.
//

#include "Shape.h"
#include "Point.h"
#include <cmath>

// constructors
// ===================================================

Shape::Shape(TypeOfShapes shape_type) {  // Property constructor

    shapeType = shape_type;
}

Line::Line(Point pointOne, Point pointTwo) { // property for line
    // add the points to the points collection
    points.push_back(pointOne);
    points.push_back(pointTwo);
    setShapeType(LINE);
}

Rectangle::Rectangle(Point pointOne, int width, int height) { //property for rect

    points.push_back(pointOne);
    this->width = width;
    this->height = height;
    setShapeType(RECTANGLE);

}
Circle::Circle(Point pointOne, int radius) { // property for circle

    points.push_back(pointOne);
    this->radius = radius;
    setShapeType(CIRCLE);
}

//Methods
//====================================================

//Shape
// ---------------------------------------------------
TypeOfShapes Shape::getShapeType() {

    return shapeType;
}

void Shape::setShapeType(TypeOfShapes newType) {

    shapeType = newType;
}

//Line
// ---------------------------------------------------
float Line::calcLength() {

    int x1 = points[0].getX();
    int y1 = points[0].getY();
    int x2 = points[1].getX();
    int y2 = points[1].getY();

    float length = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

    this->length = length;
    return length;
}

float Line::calcSlope() {

    int x1 = points[0].getX();
    int y1 = points[0].getY();
    int x2 = points[1].getX();
    int y2 = points[1].getY();

    float slope = static_cast<float>(y2-y1)/static_cast<float>(x2-x1);
    this->slope = slope;
    return slope;

}
float Line::calcAngle() {

    int x1 = points[0].getX();
    int y1 = points[0].getY();
    int x2 = points[1].getX();
    int y2 = points[1].getY();

    float angle = atan2(y2 - y1, x2 - x1) * 180 / 3.1214;
    this->angle = angle;

    return angle;

}
// Rectangle
// ---------------------------------------------------

float Rectangle::calcArea() {

    float area = width * height;
    return area;

}

float Rectangle::calcPerimeter() {

    float perimeter = (2*width) + (2*height);

    return perimeter;

}

int Rectangle::getWidth() {
    return width;
}

int Rectangle::getHeight() {
    return height;
}

// Circle
// ---------------------------------------------------

int Circle::getRadius(){
    return radius;
}

float Circle::calcArea(){
    float area = M_1_PI*(radius*radius);
    return area;
}

float Circle::calcCircumference(){
    float circumference = 2*M_1_PI*radius;
    return circumference;
}

// Line info
std::string Line::displayInfo() {


        std::string retInfo = "\nLine:\n";  // return line description

        retInfo = retInfo + "Points: {(";
        retInfo = retInfo + std::to_string(points[0].getX()) + ", " + std::to_string(points[0].getY());
        retInfo += "), (";
        retInfo = retInfo + std::to_string(points[1].getX()) + ", " + std::to_string(points[1].getY());
        retInfo += ")}\n";
        retInfo = retInfo + "Length = " + std::to_string(calcLength()) + "\n";
        retInfo = retInfo + "Slope = " + std::to_string(calcSlope()) + "\n";
        retInfo = retInfo + "Angle = " + std::to_string(calcAngle()) + "\n";



    return retInfo;
}

// Rectangle info
std::string Rectangle::displayInfo(){


    std::string retInfo = "\nRectangle:\n";  // return Rectangle description

    retInfo = retInfo + "Points: {(";
    retInfo = retInfo + std::to_string(points[0].getX()) + ", " + std::to_string(points[0].getY());
    retInfo += ")}\n";
    retInfo = retInfo + "Width = " + std::to_string(getWidth()) + "\n";
    retInfo = retInfo + "Height = " + std::to_string(getHeight()) + "\n";
    retInfo = retInfo + "Area = " + std::to_string(calcArea()) + "\n";
    retInfo = retInfo + "Perimeter = " + std::to_string(calcPerimeter()) + "\n";

    return retInfo;
}



//Circle Info
std::string Circle::displayInfo(){


    std::string retInfo = "\nCircle:\n";  // return Circle description

    retInfo = retInfo + "Points: {(";
    retInfo = retInfo + std::to_string(points[0].getX()) + ", " + std::to_string(points[0].getY());
    retInfo += ")\n";

    retInfo = retInfo + "Radius = " + std::to_string(getRadius()) + "\n";
    retInfo = retInfo + "Area = " + std::to_string(calcArea()) + "\n";
    retInfo = retInfo + "Circumference = " + std::to_string(calcCircumference()) + "\n";

    return retInfo;
}

