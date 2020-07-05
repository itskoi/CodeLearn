#include <iostream>

using namespace std;

int lastDigit(int a, int b) {
    int last = a % 10;
    int mod = b % 4;
    cout << last << " " << mod << endl;
    if (b == 0) return 1;
    switch(last) {
        case 0:
        case 1:
        case 5:
        case 6:
            return last;
        case 4:
            mod = b % 2;
            if (mod) return 4;
            else return 6;
        case 9:
            mod = b % 2 ;
            if (mod) return 9;
            else return 1;
        case 2:
            if (mod == 0) return 6;
            else if (mod == 1) return 2;
            else if (mod == 2) return 4;
            else return 8;
        case 3:
            if (mod == 0) return 1;
            else if (mod == 1) return 3;
            else if (mod == 2) return 9;
            else return 7;
        case 7:
            if (mod == 0) return 1;
            else if (mod == 1) return 7;
            else if (mod == 2) return 9;
            else return 3;
        case 8:
            if (mod == 0) return 6;
            else if (mod == 1) return 8;
            else if (mod == 2) return 4;
            else return 2;
    }
    return -1;
}

int main() {
    cout << lastDigit(2, 4);
    return 0;
}