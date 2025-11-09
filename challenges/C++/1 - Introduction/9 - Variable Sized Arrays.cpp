#include <iostream>     // For input-output operations
#include <vector>       // For using vector container
using namespace std;

int main() {
    // Optimize input-output performance.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;  
    // Read the number of arrays (n) and the number of queries (q)
    cin >> n >> q;
    
    // Initialize a vector of vectors to store the variable-sized arrays.
    vector<vector<int>> arrays(n);
    
    // Read each of the n arrays.
    for (int i = 0; i < n; i++) {
        int k;  
        // Read the number of elements for the i-th array
        cin >> k;
        // Resize the i-th vector to have k elements (optional step for clarity)
        arrays[i].resize(k);
        
        // Read each element in the i-th array
        for (int j = 0; j < k; j++) {
            cin >> arrays[i][j];
        }
    }
    
    // Process each query.
    for (int i = 0; i < q; i++) {
        int a, b;
        // For each query, read indices: `a` indicating the array number and `b` indicating the index within that array.
        cin >> a >> b;
        
        // Print the element at index b of array a.
        cout << arrays[a][b] << "\n";
    }
    
    return 0;  // Signal successful termination.
}
