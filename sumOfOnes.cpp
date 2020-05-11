#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getLength(long long n) {
    int res = 0;
    while ((n  >> 1) != 0) {
        n = n >> 1;
        res++;
    }
    return res;
}

long long fastPow(long long a, long long n) {
    if (n == 0) return 1LL;
    long long tmp = fastPow(a, n / 2);
    if (n & 1) return tmp * tmp * a;
    return tmp * tmp;
}

long long calSum(long long n, long long idx) {
    if (idx == 0) return 0LL;
    int length = getLength(idx);
    int baseLength = getLength(n);
    long long res = 0;

    for (int i = length; i >= 0; i--) {
        if ((idx >> i) & 1) {
            long long base = (n / fastPow(2, baseLength - i));
            res += base / 2;
            res += (base & 1);
        }
    }
    return res;
}

long long sumOfOnes(long long n, long long l, long long r)
{
    long long right = calSum(n, r);
    long long left = calSum(n, l - 1);
    return right - left;
}

int main() {
    cout << sumOfOnes(10, 3, 10);
    return 0;
}