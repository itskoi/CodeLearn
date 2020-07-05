#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int theBestCar(std::vector<int> a, std::vector<int> b)
{
    vector<pair<double, int>> arr; 
    for (int i = 0; i < a.size(); i++) {
        arr.push_back({double(b[i]) / double(a[i]), i});
    }
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1].second;
}

int main() {

    return 0;
}