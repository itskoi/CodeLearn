#include <iostream>
#include <vector>

using namespace std;

int sumFillerDiagonal(std::vector<std::vector<int>> a)
{
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += a[i][a[0].size() - i - 1];
    }
    return res;
}

int main() {

    return 0;
}