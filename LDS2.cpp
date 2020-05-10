#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lDS2(std::vector<int> arr)
{
    vector<int> dp;
    dp.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > dp[0]) {
            dp[0] = arr[i];
        } else {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i], [](int a, int b) {return a > b;});
            if (it == dp.end()) dp.push_back(arr[i]);
            else *it = arr[i];
        }
    }
    return dp.size();
}

int main() {
    vector<int> arr = {75, -67, 65};
    cout << lDS2(arr);
    return 0;
}