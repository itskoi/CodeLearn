#include <iostream>
#include <algorithm>
#include <vector>

int numberOfToys(std::vector<int> arr, int k)
{
    sort(arr.begin(), arr.end());
    int sum = 0, res = 0;
    for (auto x : arr) {
        if (sum + x <= k) {
            sum += x;
            res++;
        } else {
            return res;
        }
    }
    return res;
}