#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Define the Matrix class
class Matrix {
public:
    // Public member variable 'a' to store matrix elements as a 2D vector
    vector<vector<int>> a;

    // Overload the '+' operator to add two Matrix objects
    // This operator will take another Matrix object (rhs) as a constant reference parameter
    // and return a new Matrix object which is the element-wise sum of *this and rhs.
    Matrix operator+(const Matrix &rhs) const {
        // Create a new matrix 'result' to store the sum of matrices
        Matrix result;
        
        // Get the number of rows in the matrix from the current object
        int rows = a.size();
        
        // Loop through each row using index i
        for (int i = 0; i < rows; i++) {
            // Create a temporary vector to store the row of resultant matrix
            vector<int> row;
            
            // Loop through each column element in row i
            int cols = a[i].size();
            for (int j = 0; j < cols; j++) {
                // Calculate the sum of corresponding elements from *this and rhs
                int sum = a[i][j] + rhs.a[i][j];
                
                // Append the sum to the temporary row vector
                row.push_back(sum);
            }
            
            // Append the computed row to the resultant matrix's vector 'a'
            result.a.push_back(row);
        }
        // Return the resultant matrix after addition
        return result;
    }
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
