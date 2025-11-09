#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// This class template AddElements handles generic types (T) for addition
template<typename T>
class AddElements {
    T element; // Stored element of type T
public:
    // Constructor that initializes object with an element
    AddElements(T arg) : element(arg) {
        // Initialization list stores arg in element; O(1)
    }
    
    // The add function that takes another element of type T and returns the sum
    T add(T anotherElement) {
        // For numeric types, perform addition operation and return the result; O(1)
        return element + anotherElement;
    }
};

// Template specialization for type string
template<>
class AddElements<string> {
    string element; // Stored element as a string
public:
    // Constructor to initialize the string element
    AddElements(string arg) : element(arg) {
        // Initialization; O(1)
    }
    
    // Function to concatenate another string to the stored element
    string concatenate(string anotherElement) {
        // Concatenation operation and return the result; O(n) where n is the length of the strings
        return element + anotherElement;
    }
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
