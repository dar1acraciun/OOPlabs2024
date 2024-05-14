#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Compare {
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        return a.second < b.second;
    }
};

int main() {
    string c;
    c = "ana ana mere";
    map<string, int> mp;
    string aux = "";

    for (int i = 0; c[i] != '\0'; i++) {
        if (!(c[i] >= 'a' && c[i] <= 'z') && aux != "") {
            mp[aux]++;
            aux = "";
        }
        else if (c[i] >= 'a' && c[i] <= 'z') {
            aux += c[i];
        }
    }
    if (aux != "") {
        mp[aux]++;
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq(mp.begin(), mp.end());

    while (!pq.empty()) {
        cout << pq.top().first << " ";
        pq.pop();
    }

    return 0;
}
