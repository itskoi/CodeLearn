#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

bool canChangeNumber(int a, int b, int c, int d)
{
    return gcd(a, b) == gcd(c, d);
}

int main() {
    cout << gcd(28, 21);
    return 0;
}