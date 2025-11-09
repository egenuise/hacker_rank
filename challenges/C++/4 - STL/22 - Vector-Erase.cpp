#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // read int
    int N;
    cin >> N;
    
    // store numbers
    vector<int> arr(N);
    
    // read elements
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    // read position
    int x;
    cin >> x;
    
    // erase element
    arr.erase(arr.begin()+(x-1));
    
    // read two ints
    int a, b;
    cin >> a >> b;
    
    // convert
    arr.erase(arr.begin() + (a - 1), arr.begin()+(b-1));
    
    // output size
    cout << arr.size() << "\n";
    
    // output remaining elements
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    
      
    return 0;
}
