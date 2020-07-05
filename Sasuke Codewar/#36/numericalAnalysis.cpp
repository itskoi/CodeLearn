#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool checkPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

string numericalAnalysis(long long n)
{
    if (n == 1 || checkPrime(n)) return "-1"; 
    vector<int> primes = {2, 3, 5, 7};
    string result = "";
    for (auto x : primes) {
        while (n % x == 0) {
            result += char('0' + x);
            n /= x;
        }
    }
    if (n > 1) return "-1";
    sort(result.begin(), result.end(), [](char a, char b) -> bool {return a > b; });
    return result;
}

int main() {
    cout << numericalAnalysis(432);
    return 0;
}