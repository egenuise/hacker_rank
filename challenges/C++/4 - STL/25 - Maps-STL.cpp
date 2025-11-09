#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; 
    cin >> Q;
    map<string, int> mp;

    while (Q--) {
        int type; 
        cin >> type;
        if (type == 1) {
            string name; int y;
            cin >> name >> y;
            mp[name] += y;
        } else if (type == 2) {
            string name; 
            cin >> name;
            mp.erase(name);
        } else if (type == 3) {
            string name; 
            cin >> name;
            auto it = mp.find(name);
            cout << (it == mp.end() ? 0 : it->second) << "\n";
        }
    }
    return 0;
}
