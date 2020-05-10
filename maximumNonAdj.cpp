#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumNonAdj(std::vector<int> arr)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
        dp[i] = max(dp[i], arr[i - 1]);
    }
    return dp[n];
}

int main() {

    return 0;
}