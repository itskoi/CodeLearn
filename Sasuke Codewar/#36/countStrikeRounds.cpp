#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

std::vector<int> countStrikeRounds(std::vector<int> kills, std::vector<int> deaths)
{
    vector<int> result;
    if (kills[2] < 0) return result;
    if (kills[0] + kills[1] > deaths[2]) return result;
    if (kills[2] > (deaths[0] + deaths[1])) return {};
    if (-(kills[0] + kills[1] - deaths[2]) != (deaths[0] + deaths[1] - kills[2])) return result;

    int delta = abs(kills[0] + kills[1] - deaths[2]);
    int muy = abs(delta - deaths[2]);
    if (muy > kills[2]) return {};
    
    if (delta < deaths[2]) result.push_back(deaths[2] + (kills[2] - muy) / 2);
    else result.push_back(deaths[2] + muy + (kills[2] - muy) / 2 + ((kills[2] - muy) & 1));

    if (delta < kills[2]) result.push_back(deaths[2] + delta + (kills[2] - delta) / 2);
    else result.push_back(deaths[2] + kills[2]);
    
    if (result[0] > result[1]) return {};
    if (result[0] < 0) return {};

    return result;
}
//(deaths[0] + deaths[1] - kills[2]) / 2 + (deaths[2] - ((deaths[0] + deaths[1] - deaths[2]) & 1))
//deaths[2] + (deaths[0] + deaths[1] - deaths[2]) / 2 + ((deaths[0] + deaths[1] - deaths[2]) & 1)

int main() {
    vector<int> arr =  countStrikeRounds({-2, -2, 0}, {2, 2, 0});
    for (auto x : arr) {
        cout << x << " ";
    }
    return 0;
}