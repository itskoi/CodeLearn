#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

std::vector<std::vector<int>> pillShelf(int n)
{
    int idx = 1;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int k = n - 1; k >= 1 - n; k--) {
        for (int i = 0; i < n; i++) {
            if (i + k >= 0 && i + k < n) arr[i][i + k] = idx++;
        }
    }
    return arr;
}
int main() {
    pillShelf(4);
    return 0;
}