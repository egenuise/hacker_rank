#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Improve I/O speed when not using C-style I/O
    cin.tie(NULL);                    // Untie cin from cout for faster I/O operations

    int Q;            // Number of queries
    cin >> Q;         // Read the number of queries from standard input

    set<int> s;       // Declare an STL set of integers to store unique elements

    // Process each query
    while(Q--) {
        int queryType, value;     // Variable to hold the type of query and the integer value
        cin >> queryType >> value; // Read query type and the associated value

        // For query type 1, insert the element into the set
        if(queryType == 1) {
            s.insert(value);   // Insert value into the set
        }
        // For query type 2, erase the element if it exists in the set
        else if(queryType == 2) {
            s.erase(value);    // Erase value from the set if present. Safe if it doesn't exist.
        }
        // For query type 3, check if the element is present in the set
        else if(queryType == 3) {
            // find() returns an iterator. s.end() indicates the element wasn't found
            if(s.find(value) != s.end())
                cout << "Yes" << "\n"; // Element is found, print "Yes"
            else
                cout << "No" << "\n";  // Element is not found, print "No"
        }
        // If further query types are defined in the future, they can be added here.
    }
    return 0;  // End of main function; return 0 signals successful execution
}



