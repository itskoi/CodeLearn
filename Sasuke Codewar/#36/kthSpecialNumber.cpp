#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string kthSpecialNumber(std::vector<int> arr, int k)
{
    if (arr.size() == 1 && arr[0] == 0) return "-1";
    sort(arr.begin(), arr.end());

    int n = 0;
    int size = 63;
    int p = 1;
    bool check = false;
    vector<int> base(size);
    base[0] = 0;
    
    if (arr[0] != 0) {
        for (int i = 1; i < size; i++) {
            p= p * arr.size();
            n = i;
            base[i] = base[i - 1] + p;
            if (base[i] >= k) {
                check = true;
                break;
            }
        }
        if (check) {
            n--;
            p /= arr.size();
        }
        string res = "";
        //cout << p  << " " << base[n] << endl;
        k -= base[n];
        //cout << k << " ";
        while(n > 0) {
            n--;
            int t = k / p;
            if (k % p == 0) t--, k = p;
            else k %= p;
            res += char(arr[t] + '0');
            p /= arr.size();
        }

        if (n == 0) res += char(arr[k - 1] + '0');
        return res;
    } else {
        p = arr.size() - 1;
        base[1] = p;
        n = 1;

        if (base[1] >= k) check = true;
        else {
            for (int i = 2; i < size; i++) {
                p= p * arr.size();
                n = i;
                base[i] = base[i - 1] + p;
                if (base[i] >= k) {
                    check = true;
                    break;
                }
            }
        }
        
        if (check) {
            n--;
            p /= (arr.size() - 1);
        }

        string res = "";
        //cout << n  << " " << base[n] << endl;
        k -= base[n];
        
        n--;
        int t = k / p;
        if (k % p == 0) t--, k = p;
        else k %= p;
        res += char(arr[t + 1] + '0');
        p /= arr.size();

        while(n > 0) {
            n--;
            int t = k / p;
            if (k % p == 0) t--, k = p;
            else k %= p;
            res += char(arr[t] + '0');
            p /= arr.size();
        }

        if (n == 0) res += char(arr[k - 1] + '0');
        return res;
    }
    
}

int main() {
    for (int i = 1; i <= 20; i++) 
    cout << kthSpecialNumber({0}, i) << endl;
    return 0;
}