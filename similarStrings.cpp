#include <iostream>
#include <string>

using namespace std;

bool recursion(string a, string b) {
    if (a.size() % 2 == 1) return a == b;
    string suba1, suba2, subb1, subb2;
    suba1 = a.substr(0, a.size() / 2);
    suba2 = a.substr(a.size() / 2, a.size() / 2);
    subb1 = b.substr(0, b.size() / 2);
    subb2 = b.substr(b.size() / 2, b.size() / 2);
    bool flag = (recursion(suba1, subb1) && recursion(suba2, subb2));
    flag |= (recursion(suba1, subb2) && recursion(suba2, subb1));
    return flag;
}

bool similarStrings(string a, string b)
{
    if (a.size() != b.size()) return false;
    if (a == b) return true;
    if (a.size() % 2 == 1) return false;
    return recursion(a, b);
}

int main() {
    cout << similarStrings("aabb", "abab");
    return 0;
}