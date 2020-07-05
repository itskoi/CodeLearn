#include <iostream>
#include <map>

using namespace std;

bool switchString(string s1, string s2)
{
    if (s1.size() != s2.size()) return false;
    map<char, char> hashMap;

    for (int i = 0; i < s1.size(); i++) {
        if (!hashMap[s1[i]]) {
            hashMap[s1[i]] = s2[i];
            s1[i] = s2[i];
        } else {
            s1[i] = hashMap[s1[i]];
        }
    }
    
    return s1 == s2;
}

int main() {
    switchString("ab", "cc");
    return 0;
}