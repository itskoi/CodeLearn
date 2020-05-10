#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long fastPower(long long a, int n, const long long BASE) {
    if (n == 0) return 1LL;
    long long tmp = fastPower(a, n / 2, BASE) % BASE;
    if (n % 2 == 0) return (tmp * tmp) % BASE;
    return ((tmp * tmp) % BASE * a) % BASE;
}

int easyLego(int n, int m)
{
    int size = max(m, 5);
    const long long BASE = 1e9 + 7;
    vector<long long> dp(size + 1, 0);

    dp[1] = 1; 
    dp[2] = 2;
    dp[3] = 4; 
    dp[4] = 8;

    for (int i = 5; i <= m; i++) {
        dp[i] = ((dp[i - 1] + dp[i - 2]) % BASE + (dp[i - 3] + dp[i - 4]) % BASE) % BASE;
    }
    return fastPower(dp[m], n, BASE);
}

int main() {
    cout << easyLego(3, 3);
    return 0;
}