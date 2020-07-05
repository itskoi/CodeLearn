#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarray(vector<int> inputArray) {
    int maxSum = 0;
    vector<int> sum(inputArray.size() + 1, 0);
    for (int i = 0; i < inputArray.size(); i++) {
        sum[i + 1] = sum[i] + inputArray[i];
    }
    for (int i = 1; i <= inputArray.size(); i++) {
        for (int j = 0; j < i; j++) maxSum = max(maxSum, sum[i] - sum[j]);
    }
    return maxSum;
}

int main() {
    cout << maxSubarray({-1, -2, -5, -1});
    return 0;
}