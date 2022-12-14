#include <iostream>
#include "Shape.h"
#include "Point.h"
#include <vector>


using std::cout;
using std::cin;

enum Menu{
    Exit ,            // a default value of an empty base Shape (default)
    PRINT = 4
};

void printShapes(std::vector<Shape*> shapes); // prints all info on shapes
Point getPoint();   // ask the user for Point X and Y
Line* getLine();    // returns Pointer to Line created with "new" operator
Rectangle* getRectangle(); //returns a Pointer to Rectangle
int getWidth();    //ask user for width of rectangle
int getHeight();   //ask user for height of triangle
Circle* getCircle();    //return Pointer to a Circle
int getRadius();

int main() {

    int menuChoice;
    std::vector<Shape*> shapes;   // shapes collection variable

    do {
        // print menu
        cout << "\n \t Line(1) \n \t Rectangle(2) \n \t Circle(3) "
                "\n\t Print(4) \n\t Exit(0)\n\n Please select a shape: ";
        cin >> menuChoice;

        switch(menuChoice) {

            case LINE:

                // call the Line* getLine() function
                shapes.push_back( getLine());

                break;

            case RECTANGLE:

                // call the Rectangle* getLine() function
                shapes.push_back(getRectangle());

                break;

            case CIRCLE:

                // call the Circle* getLine() function
                shapes.push_back(getCircle());

                break;

            case PRINT:

                //call print and go through shape vector
                printShapes(shapes);

                break;
        }

    } while (menuChoice != Exit);

} // end main

/**
 *  Prompts user to enter points
 * @return point containing x and y coord
 */
Point getPoint() {
    Point point; // calls default constructor; makes empty point (0, 0)

    // print prompt message
    cout << "Please enter two points seperated by a space: ";

    int xIn, yIn;
    std::cin >> xIn >> yIn;

    // call property constructor to reconstruct as (xIn, yIn)
    point.setX(xIn);
    point.setY(yIn);

    return point;
} // get Point

// Line
// ---------------------------------------------------

/**
 * gets points and stores them in new point type
 * @return a pointer to a Line
 */
Line* getLine() {
    Line* ptrLine; // return Line pointer

    Point point1 = getPoint();
    Point point2 = getPoint();

    // use property constructor, dynamic allocation of Line type
    ptrLine = new Line(point1, point2);

    return ptrLine;
} // getRectangle


// Rectangle
// ---------------------------------------------------

/**
 * gets a point, width, and height from the use
 * @return pointer to a rectangle
 */
Rectangle* getRectangle() {
    Rectangle* ptrRect; // return Line pointer

    Point point1 = getPoint();
    int width = getWidth();
    int height = getHeight();
    // use property constructor
    ptrRect = new Rectangle(point1, width, height);

    return ptrRect;
} // getRect

/**
 *  prompts user to enter width of rect
 * @return width
 */
int getWidth(){

    int width;
    cout << "Enter a width for the rectangle: ";
    cin >> width;
    return width;
} // getWidth

/**
 *  prompts user to enter height of rect
 * @return height
 */
int getHeight(){

    int height;
    cout << "Enter a height for the rectangle: ";
    cin >> height;
    return height;
} // getHeight

// Circle
// ---------------------------------------------------

/**
 * gets radius and a point and stores in new cirlce
 * @return pointer to circle
 */
Circle* getCircle(){
    Circle* ptrCircle; // return circle pointer

    Point point1 = getPoint();
    int radius = getRadius();

    ptrCircle = new Circle(point1, radius);

    return ptrCircle;
}
/**
 * prompt user to enter radius for circle
 * @return cirlce
 */
int getRadius() {
    int radius;
    cout << "Enter a radius for the circle: ";
    cin >> radius;
    return radius;
} // getRadius

/**
 * loops through shapes vector and calls display info
 * for each
 * @param shapes
 */
void printShapes( std::vector<Shape*> shapes) {
    for (int i = 0; i < shapes.size(); i++) {
       cout << shapes[i]->getShapeType() << std::endl;
       std::string info = shapes[i]->displayInfo();
       cout << info;
    }
}
