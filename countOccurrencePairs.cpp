#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// f2[i] = counter[arr[i]] + 1 - f[i]

long long recursion(int l, int r, vector<int> &arr ,vector<int> &f, map<int, int> &counter) {
    if (r - l + 1 <= 1) return 0;
    long long result = 0;
    if (r - l + 1 == 2) {
        if (f[l] > (counter[arr[r]] + 1 - f[r])) result = 1;
        if (f[l] > f[r]) swap(f[l], f[r]), swap(arr[l], arr[r]);
        cout << l << " " << r << " " << result <<endl;
        return result;
    }
    int ptr1 = l, ptr2 = r;
    int mid = (l + r) >> 1;
    result += recursion(l, mid, arr, f, counter);
    result += recursion(mid + 1, r, arr, f, counter);

    while(ptr1 <= ptr2 && ptr1 <= mid) {
        while(ptr2 >= mid + 1 && f[ptr1] > (counter[arr[ptr2]] + 1 - f[ptr2])) ptr2--;
        result += 1LL * (r - ptr2);
        ptr1++;
    }
    // Merge sort
    ptr1 = l, ptr2 = mid + 1;
    vector<int> tmp1 = arr, tmp2 = f;
    for (int i = l; i <= r; i++) {
        if (ptr1 > mid) {
            tmp1[i] = arr[ptr2];
            tmp2[i] = f[ptr2];
            ptr2++;
            continue;
        }
        if (ptr2 > r) {
            tmp1[i] = arr[ptr1];
            tmp2[i] = f[ptr1];
            ptr1++;
            continue;
        }
        if (f[ptr1] < f[ptr2]) {
            tmp1[i] = arr[ptr1];
            tmp2[i] = f[ptr1];
            ptr1++;
        } else {
            tmp1[i] = arr[ptr2];
            tmp2[i] = f[ptr2];
            ptr2++;
        }
    }
    arr = tmp1;
    f = tmp2;
    
    cout << l << " " << r << " " << result << endl;
    for (int i = l; i <= r; i++) cout << arr[i] << " ";
    cout << endl;
    for (int i = l; i <= r; i++) cout << f[i] << " ";
    cout << endl;
    cout << "------------------\n";
    return result;
}

long long countOccurrencePairs(std::vector<int> arr)
{
    map<int, int> counter;
    vector<int> f(arr.size());
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";\
    cout << endl;
    for (int i = 0; i < arr.size(); i++) {
        counter[arr[i]]++;
        f[i] = counter[arr[i]];
        cout << f[i] << " ";
    }
    cout << endl;
    cout << "-------------------\n";
    //
    return recursion(0, arr.size() - 1, arr, f, counter);
}

int main() {
    cout << countOccurrencePairs({2, 3, 3, 2, 1, 3, 2, 4, 3, 3});
    return 0;
}