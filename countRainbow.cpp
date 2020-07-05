#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string base[] = {"red", "violet", "orange", "yellow", "green", "indigo", "blue"};

int countRainbow(string str)
{
    map<char, int> counter;

    for (char x : str) counter[x]++;
    int result = 0;
    while(true) {
        bool makeRB = true;
        for (string x : base) {
            bool makeCL = true;
            for (char ch : x) if (counter[ch] <= 0) {
                makeCL = false;
                break;
            }
            if (!makeCL) {
                makeRB = false;
                break;
            } else {
                for (char ch : x) counter[ch]--;
            }
        }
        if (makeRB) result++;
        else break;    
    }
    return result;
}

int main() {
    cout << countRainbow("ngegooglnonnaugrnyeniroowealrlrerndrgyneeouerndeitnneboeuigwoielngiblboreoeogrlaolordwielvleeeiaylaelueweoelaloubgerllvegdulwonoaebigdorggwlnlgeriyldleeoenybbrelreuydengeegotiaao");
    return 0;
}