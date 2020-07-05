#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int countDoublePrime(int n)
{
    vector<int> arr;
    map<int, bool> isNotPrime;
    for (int i = 2; i * i <= 2 * n; i++) {
        if (!isNotPrime[i]) {
            for (int j = i * i; j <= 2 * n; j += i) isNotPrime[j] = true;
        }
    }
    for (int i = 2; i <= 2 * n; i++) {
        if (!isNotPrime[i]) arr.push_back(i);
    }

    int counter = 0;
    for (int value : arr) {
        if (value > n) break;
        if (binary_search(arr.begin(), arr.end(), 2 * value - 1)) 
            counter++;
    }
    return counter;
}
int main() {
    countDoublePrime(10);
    return 0;
}