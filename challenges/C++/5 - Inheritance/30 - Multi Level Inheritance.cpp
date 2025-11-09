#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n";
		}
};

class Isosceles : public Triangle{
  	public:
  		void isosceles(){
    		cout<<"I am an isosceles triangle\n";
  		}
};

/*
* Derived class: Equilateral
* Inherits from Isosceles and provides an additional method for equilateral triangle.
 */
class Equilateral : public Isosceles {
public:
    // Member function to display equilateral triangle information
    void equilateral() {
        // Print the message for the equilateral triangle
        cout << "I am an equilateral triangle" << endl;
    }
};

int main(){
  
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
