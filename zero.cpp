#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

int strToInt(string str) {
    int res = 0;
    int base = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        res += base * (str[i] - '0');
        base *= 10;
    }
    return res;
} 

void recursive(int t, string s, vector<string> &result, vector<int> bits) {
    if (t == s.size()) {
        int curIdx = 0, crawl, res = 0;
        while(curIdx < t) {
            crawl = curIdx + 1;
            if (s[curIdx] != '0') {
                while(crawl < t && bits[crawl] == 0) crawl++;   
                int tmp = strToInt(s.substr(curIdx, crawl - curIdx));
                if (bits[curIdx] == 1) res += tmp;
                else if (bits[curIdx] == 2) res -= tmp;
            }
            curIdx = crawl;
        }
        if (res == 0) {
            curIdx = 0;
            string final = "";
            while(curIdx < t) {
                crawl = curIdx + 1;
                if (s[curIdx] != '0') {
                    while(crawl < t && bits[crawl] == 0) crawl++;   
                    string str = s.substr(curIdx, crawl - curIdx);
                    if (bits[curIdx] == 1 && curIdx != 0) final += '+';
                    else if (bits[curIdx] == 2) final += '-';
                    final += str;
                } else {
                    if (bits[curIdx] == 1 && curIdx != 0) final += '+';
                    else if (bits[curIdx] == 2) final += '-';
                    final += '0';
                }
                curIdx = crawl;
            }   
            result.push_back(final);
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (t == 0 && i == 0) continue;
        if (s[t] == '0' && i == 0) continue; 
        bits[t] = i;
        recursive(t + 1, s, result, bits);
    }
}

vector<string> zero(string s) {
    vector<string> result;
    vector<int> bits(s.size(), 0);

    recursive(0, s, result, bits);
    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<string> res = zero("102003");
    for (string x : res) {
        cout << x << endl;
    }
    return 0;
}