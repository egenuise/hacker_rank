#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long N, S, P, Q;
    cin >> N >> S >> P >> Q;
    const long long M = 1LL << 31;

    long long a = S % M;
    long long tortoise = (a * P + Q) % M;
    long long hare = (tortoise * P + Q) % M;
    long long step = 1;

    while (tortoise != hare && step < N) {
        tortoise = (tortoise * P + Q) % M;
        hare = (hare * P + Q) % M;
        hare = (hare * P + Q) % M;
        step++;
    }

    if (step >= N) { 
        cout << N << endl;
        return 0;
    }


    long long mu = 0;
    tortoise = a;
    while (tortoise != hare) {
        tortoise = (tortoise * P + Q) % M;
        hare = (hare * P + Q) % M;
        mu++;
    }


    long long lam = 1;
    hare = (tortoise * P + Q) % M;
    while (tortoise != hare) {
        hare = (hare * P + Q) % M;
        lam++;
    }

    cout << min(N, mu + lam) << endl;
    return 0;
}
