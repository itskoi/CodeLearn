#include <iostream>

using namespace std;

int threeDividable(int a, int b)
{
    b--;
    if (a % 2 == 1) a++;
    if (b % 2 == 1) b++;
    a /= 2; b /= 2;
    long long s1 = 1LL * a * a;
    long long s2 = 1LL * b * b;
    return (s2 - s1) % 3;
}

int main() {
    cout << threeDividable(10, 25);
    return 0;
}