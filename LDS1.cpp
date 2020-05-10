#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lDS1(std::vector<int> arr)
{
    int result = 1;
    vector<int> dp(arr.size() + 1, 1);
    dp[0] = 0;
    for (int i = 1; i <= arr.size(); i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i - 1] < arr[j - 1] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        result = max(result, dp[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {64, -86, -90};
    cout << lDS1(arr);
    return 0;
}