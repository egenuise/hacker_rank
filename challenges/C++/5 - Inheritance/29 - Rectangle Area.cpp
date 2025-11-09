#include <iostream>

using namespace std;

/* 
* Base class Rectangle 
* Contains two integer data fields: width and height.
* Also includes a display() method to print these two values.
 */
class Rectangle {
    public:
        int width;  // Data member for width of rectangle
        int height; // Data member for height of rectangle

        // Method to display width and height separated by a space
        void display() {
            cout << width << " " << height << endl;  // Print width and height with a space in between, followed by a newline
        }
};

/* 
* Derived class RectangleArea
* Inherits from the base class Rectangle.
* Adds a method to read input values and overloads the display() function to print the area.
 */
class RectangleArea : public Rectangle {
    public:
        // read_input() method to read width and height from user input
        void read_input() {
            cin >> width >> height;    // Read two integers from standard input and store in inherited variables width and height.
        }

        // Overloaded display() method to print the area (width * height)
        void display() {
            cout << (width * height) << endl;  // Compute area and print it, followed by a newline
        }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}