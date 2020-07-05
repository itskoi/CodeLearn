#include <iostream>
#include <string>
#include <map>

using namespace std;

string maxNumber2(string a, string b)
{
    string res = "";
    int idx1 = 0, idx2 = 0;
    map<int, int> map1, map2;

    while(idx1 < a.size() || idx2 < b.size()) {

        int tmp1, tmp2;
        tmp1 = idx1;
        tmp2 = idx2;

        if (a[idx1] == b[idx2]) {
            char x = a[idx1];
            if (!map1[idx1] && !map2[idx2]) {
                while (tmp1 < a.size() && a[tmp1] == x) tmp1++;
                while (tmp2 < b.size() && b[tmp2] == x) tmp2++;
                map1[idx1] = tmp1;
                map2[idx2] = tmp2;
            }else if (map1[idx1] && !map2[idx2]) {
                while (tmp2 < b.size() && b[tmp2] == x) tmp2++;
                map2[idx2] = tmp2;
                tmp1 = map1[idx1];
            } else if (!map1[idx1] && map2[idx2]) {
                while (tmp1 < a.size() && a[tmp1] == x) tmp1++;
                map1[idx1] = tmp1;
                tmp2 = map2[idx2];
            } else {
                tmp1 = map1[idx1];
                tmp2 = map2[idx2];
            }
        }
        
        char ava1, ava2;

        if (tmp1 >= a.size()) ava1 = '0';
        else ava1 = a[tmp1];
        if (tmp2 >= b.size()) ava2 = '0';
        else ava2 = b[tmp2];

        if (ava1 > ava2) {
            res += a[idx1++];
        } else {
            res += b[idx2++];
        }

        if (idx1 == a.size()) {
            while(idx2 < b.size()) res += b[idx2++];
        }
        if (idx2 == b.size()) {
            while(idx1 < a.size()) res += a[idx1++];
        }
    }
    return res;
}

int main() {
    cout << maxNumber2("967453", "964423");
    return 0;
}