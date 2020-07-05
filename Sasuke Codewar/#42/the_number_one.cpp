#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool theNumberOne(int n)
{
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for (int i = 2; i * i <= abs(n); i++) {
        if (abs(n) % i == 0) {
            if (i % 2 == 0) cnt1++;
            else cnt2++;
            if ((abs(n) / i) % 2 == 0) cnt1++;
            else cnt2++;
        }
    }
    return (cnt1 == cnt2) && cnt1 != 0;
}

int main() {
    cout << theNumberOne(0);
    return 0;
}