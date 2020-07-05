#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    long long c;
    while (b != 0) {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

string intToStr(long long a) {
    string res = "";
    while (a != 0) {
        res = char(a % 10 + '0') + res;
        a /= 10;
    }
    return res;
}

string safeAreaProbability(int n)
{
    long long nor, dor;
    if (n & 1) return "0";
    nor = 3LL;
    dor = 1LL * (n - 3) * (n - 1);
    long long tmpGCD = gcd(nor, dor);
    nor /= tmpGCD;
    dor /= tmpGCD;
    if (dor != 1) return intToStr(nor) + "/" + intToStr(dor);
    else return intToStr(nor);
}

int main() {
    cout << safeAreaProbability(7);
    return 0;
}