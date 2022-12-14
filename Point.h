//
// Created by andyh on 12/8/2022.
//

#ifndef SHAPESPOROJECT_POINT_H
#define SHAPESPOROJECT_POINT_H


class Point {
private:
    int x;
    int y;

public:

// constructors
// ---------------------------------------------------
    Point() = default; // Default constructor
    Point(int x, int y); // property constructor

// accessors
// ---------------------------------------------------

    int getX ();
    void setX (int x);

    int getY();
    void setY(int y);

};


#endif //SHAPESPOROJECT_POINT_H
