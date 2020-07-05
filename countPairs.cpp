#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

long long countPairs(std::vector<int> arr)
{
    long long res = 0;
    map<int, int> counter;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 1; j * j <= arr[i] && arr[i] != 1; j++) {
            if (arr[i] % j == 0) {
                counter[j]++;
            }
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        res += counter[arr[i]];
    }
    counter.clear();
    for (int i = 0; i < arr.size(); i++) {
        counter[arr[i]]++;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (counter[arr[i]] < 0) continue;
        int tmp = counter[arr[i]];
        res += (tmp * (tmp - 1) / 2);
    }
    return res;
}
int main() {
    vector<int> arr = {1, 2, 3, 4};
    cout << countPairs(arr);
    return 0;
}