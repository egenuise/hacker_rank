#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		// Line 1: Hexadecimal (truncated, no prefix, lowercase)
        cout << nouppercase << showbase << hex << left << (long long)A << endl;

        // Line 2: Signed, 2 decimal places, width 15, right-justified with underscores
        cout << showpos << fixed << setprecision(2) 
             << setw(15) << setfill('_') << right << B << endl;

        // Line 3: Scientific notation, 9 decimal places, uppercase
        cout << noshowpos << scientific << setprecision(9) << uppercase << C << endl;

	}
	return 0;

}