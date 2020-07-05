#include <iostream>

using namespace std;

int compareSumOfDigits(string input) {
    int res = 0;
    for (char x : input) {
        int num = x - '0';
        if (num % 2 == 0) res -= num;
        else res += num;
    }
    return res;
}

int main() {

    return 0;
}