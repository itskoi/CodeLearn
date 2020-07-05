#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

std::vector<int> sortArray(std::vector<int> arr, std::vector<int> other)
{
    vector<int> tmp;
    map<int, bool> checker;
    for (int val : other) checker[val] = true;
    for (int val : arr) if (!checker[val]) tmp.push_back(val);
    
    sort(tmp.begin(), tmp.end());

    int idx = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (!checker[arr[i]]) arr[i] = tmp[idx++]; 
    }
    return arr;
}
int main() {
    sortArray({2,3,1,43,5,3,5,2,1,1,1}, {1, 2});
    return 0;
}