#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gradeCheating(int n, int m, std::vector<int> a)
{
    vector<int> maxSum(n + 1, 0);
    for (int i = 1; i < n; i++) {
        maxSum[i] = maxSum[i - 1] + a[i];
    }

    int res = a[0] + maxSum[n - 1];
    if (res > m) res = m;
    return res;
}

int main() {

    return 0;
}