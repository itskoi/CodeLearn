#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DivideConquer(int i, int j, std::vector<int> &arr) {
    int res = 0;
    
    if (j - i <= 0) return 0;

    int mid = (i + j) / 2;
    res += DivideConquer(i, mid, arr);
    res += DivideConquer(mid + 1, j, arr);
    for (int k = mid + 1; k <= j; k++) {
        auto it = upper_bound(arr.begin() + i, arr.begin() + mid + 1, arr[k]);
        if (it != arr.begin() + mid + 1) {
            res += (arr.begin() + mid - it) + 1;
        }
    }
    sort(arr.begin() + i, arr.begin() + j + 1, [] (int a, int b) { return a < b; });
    return res;
}

int countInversions(std::vector<int> arr)
{
    return DivideConquer(0, arr.size() - 1, arr);
}

int main() {
    vector<int> arr = {4,6,2,9};
    cout <<DivideConquer(0, arr.size() - 1, arr);
    return 0;
}