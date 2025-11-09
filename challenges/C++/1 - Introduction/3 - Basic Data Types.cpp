#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i;
    long l;
    char c;
    float f;
    double d;
    
    cin >> i >> l >> c >> f >> d;
    cout << i << endl;
    cout << l << endl;
    cout << c << endl;
    printf("%.3f\n", f);
    printf("%.9f\n", d);
    return 0;
}
