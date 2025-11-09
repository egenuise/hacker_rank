#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); // Fast i/o
    cin.tie(nullptr);                // Untie cin and cout for faster input processing
    
    int N;                           // Declare variable for number of elements
    cin >> N;                        // Read the number of elements
    
    vector<int> arr(N);              // Declare a vector of size N to store sorted integers
    
    // Read the sorted array elements
    for (int i = 0; i < N; i++) {
        cin >> arr[i];               // Read each element into the vector
    }
    
    int Q;                           // Declare variable for number of queries
    cin >> Q;                        // Read the number of queries
    
    // Process each query
    while (Q--) {                    // Loop Q times for each query
        int query;                   
        cin >> query;                // Read the query integer
        
        // Use lower_bound to get the iterator pointing to the first element 
        // that is not less than the query value.
        auto it = lower_bound(arr.begin(), arr.end(), query);
        
        // Calculate the 1-based index from the iterator
        int index = it - arr.begin() + 1;
        
        // Check if the element equals the query (i.e., query exists in the vector)
        if (it != arr.end() && *it == query) {
            // If found, output "Yes" alongside the 1-based index
            cout << "Yes " << index << "\n";
        } else {
            // If not found, output "No" alongside the 1-based index where query would be inserted
            cout << "No " << index << "\n";
        }
    }
    
    return 0; // End of main function
}
