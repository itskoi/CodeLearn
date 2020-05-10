#include <iostream>
#include <vector>

using namespace std;

int fibLikeSq(int n) {
    const long long BASE = 1e9 + 7;
    vector<long long> F(101010);
    F[1] = 1LL, F[2] = 1LL, F[3] = 2LL;
    for (int i = 4; i <= n; i++) {
        F[i] = ((F[i - 1] % BASE) * (F[i - 2] % BASE)) % BASE + F[i - 3];
        F[i] %= BASE;
    }
    return F[n];
}

int main() {

    return 0;
}