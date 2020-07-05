#include <iostream>
#include <string>

using namespace std;

int onesAndZeros(string s)
{
    int one, zero;
    one = zero = 0;
    for (char x : s) if (x == '0') zero++; else if (x == '1') one++;
    int res = zero - one;
    if (res < 0) res *= -1;
    return res;
}

int main() {

    return 0;
}
