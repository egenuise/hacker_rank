#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false); // Optimizes IO operations
    cin.tie(nullptr);            // Unties cin from cout for faster input

    int N;                     // Variable to hold the number of integers
    cin >> N;                  // Reading the number of integers from standard input
    
    vector<int> v;             // Declare a vector of integers to store the input numbers
    v.reserve(N);              // Reserve memory to improve input performance

    // Loop to read N integers and push them into the vector
    for (int i = 0; i < N; i++) {
        int num;                // Temporary variable to store each number read
        cin >> num;             // Read the number from input
        v.push_back(num);       // Add the number to the vector
    }
    
    // Sorting the entire vector in ascending order
    sort(v.begin(), v.end());
    
    // Iterate through the sorted vector and print each integer followed by a space
    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";  // Output the element and a space
    }
    
    // Flush the output and return 0 to signal successful execution
    return 0;
}
