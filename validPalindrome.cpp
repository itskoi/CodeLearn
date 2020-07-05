#include <iostream>
#include <string>
using namespace std;

bool validPalindrome(string s)
{
    string str = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= '9' && s[i] >= '0') str += s[i];
        else if (s[i] <= 'z' && s[i] >= 'a') str += s[i];
        else if (s[i] <= 'Z' && s[i] >= 'A') str += char(s[i] - 32);
    }
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - i - 1]) return false;
    }
    return true;
}

int main() {

    return 0;
}