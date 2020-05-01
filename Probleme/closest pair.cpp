#include <bits/stdc++.h>
using namespace std;


int closestPair(vector<int>& first, vector<int>& second) {
    vector<pair<int,int>> total;
    total.reserve(first.size()+second.size());
    for(auto &i:first)
    total.push_back({i,1});
    for(auto &i:second)
    total.push_back({i,2});
    sort(total.begin(),total.end());
    int rez = 0xFFFFFFF;
    for(int i=0;i<total.size()-1;i++)
        if(total[i].second!=total[i+1].second)
        rez = min(rez, abs(total[i].first-total[i+1].first));
    return rez;
}

int main() {
    int n; cin >> n;
    vector<int> first, second;
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        first.push_back(val);
    }
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        second.push_back(val);
    }
    cout << closestPair(first, second) << "\n";
    return 0;
}
