#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getTime(string x) {
    return (x[0] - '0') * 10 + (x[1] - '0');
} 

string toStr(int n) {
    string res = "";
    while (n != 0) {
        res = char(n % 10 + '0') + res;
        n /= 10;
    }
    while (res.size() < 2) res = '0' + res;
    return res;
}

string subtractionTime(string a, string b)
{
    int h1, h2, p1, p2, s1, s2;
    h1 = getTime(a.substr(0, 2));
    h2 = getTime(b.substr(0, 2));
    p1 = getTime(a.substr(3, 2));
    p2 = getTime(b.substr(3, 2));
    s1 = getTime(a.substr(6, 2));
    s2 = getTime(b.substr(6, 2));
    string res = "";
    int remind = 0;
    if (s1 < s2) {
        res += ':' + toStr(s2 - s1);
    } else if (s1 > s2) {
        remind = 1;
        res += ':' + toStr(60 - s1 + s2);
    } else {
        res += ":00";
    }

    p1 += remind;
    if (p1 > 60) p1 = 1;
    remind = 0;

    if (p1 < p2) {
        res = ':' + toStr(p2 - p1) + res;
    } else if (p1 > p2) {
        remind = 1;
        res = ':' + toStr(60 - p1 + p2) + res;
    } else {
        res = ":00" + res;
    }

    h1 += remind;
    if (h1 > 24) h1 = 1;
    if (h1 < h2) {
        res = toStr(h2 - h1) + res;
    } else if (h1 > h2) {
        res = toStr(24 - h1 + h2) + res;
    } else {
        res = "00" + res;
    }
    return res;
}

int main() {
    cout << subtractionTime("19:22:28", "19:04:52");
    return 0;
}